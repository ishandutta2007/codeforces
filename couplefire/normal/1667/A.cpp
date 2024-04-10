#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    ll ans = 1e18;
    for(int i = 0; i<n; ++i){
        ll cnt = 0;
        ll prv = 0;
        for(int j = i-1; j>=0; --j)
            cnt += prv/arr[j]+1, prv = 1ll*arr[j]*(prv/arr[j]+1);
        prv = 0;
        for(int j = i+1; j<n; ++j)
            cnt += prv/arr[j]+1, prv = 1ll*arr[j]*(prv/arr[j]+1);
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
}