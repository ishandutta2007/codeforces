#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    ll ans = 0;
    for(int i = 0; i<n; ++i){
        vector<int> cnt(n+1, 0);
        for(int j = 0; j<i; ++j)
            ++cnt[arr[j]];
        for(int j = 1; j<=n; ++j)
            cnt[j] += cnt[j-1];
        int bruh = 0;
        for(int j = n-1; j>i; --j){
            ans += 1ll*bruh*cnt[arr[j]-1];
            bruh += (arr[j]<arr[i]);
        }
    }
    cout << ans << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}