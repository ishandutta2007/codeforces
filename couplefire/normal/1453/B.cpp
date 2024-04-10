#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<long long> dif;
    int cur = 0;
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        if(i != 0) dif.push_back(a-cur);
        cur = a;
    }
    long long ans = 0;
    for(auto x : dif) ans += abs(x);
    long long tot = ans;
    ans = min(ans, tot-1ll*abs(dif.front()));
    ans = min(ans, tot-1ll*abs(dif.back()));
    for(int i = 1; i<dif.size(); i++){
        long long a = dif[i-1];
        long long b = dif[i];
        ans = min(ans, tot-abs(a)-abs(b)+abs(b+a));
    }
    cout << ans << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}