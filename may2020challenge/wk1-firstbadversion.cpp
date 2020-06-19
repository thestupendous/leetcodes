// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return firstBad2(1,n, -1);
    }
    int firstBad2(int left, int right, int ans){
        if (left>right) return ans;
        int mid = left + ( (right - left) / 2 );
        if (isBadVersion(mid)){
            //go left to find a better solution (already have got a bad version)
            ans = mid;
            ans = firstBad2(left,mid-1,ans);
        }
        else {
            //go right to find a bad version
            ans = firstBad2(mid+1, right,ans);
        }
        return ans;
    }
};
