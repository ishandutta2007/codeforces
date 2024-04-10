#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    int ans = 0;
    for(int i = 0; i<n; i+=2){
        int big = arr[i], smol = 1;
        for(int j = i+1; j<n; j+=2){
            if(smol>big) continue;
            if(j==i+1) big -= arr[j], smol -= arr[j];
            else big += arr[j-1]-arr[j], smol += arr[j-1]-arr[j];
            ans += max(0ll, -smol-max(-big, 0ll)+1);
            smol = max(smol, 0ll);
        }
    }
    cout << ans << '\n';
}