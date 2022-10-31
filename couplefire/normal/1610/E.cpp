#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        for(int i = 0; i<n; ++i)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i = 0; i<n; ++i){
            if(i && arr[i]==arr[i-1]) continue;
            int tmp = 0, cur = i;
            while(cur<n)
                ++tmp, cur = max((int)(lower_bound(arr.begin(), arr.end(), arr[cur]*2-arr[i])-arr.begin()), cur+1);
            ans = max(ans, tmp);
        }
        cout << n-ans << '\n';
    }
}