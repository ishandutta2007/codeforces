#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> cnt(30, 0);
    for(int i = 0; i<n; ++i){
        int a; cin >> a;
        for(int j = 0; j<30; ++j)
            if(a&(1<<j)) cnt[j]++;
    }
    int ans = 0;
    for(int i = 0; i<30; ++i)
        ans = __gcd(ans, cnt[i]);
    for(int i = 1; i<=n; ++i)
        if(ans%i==0) cout << i << ' ';
    cout << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}