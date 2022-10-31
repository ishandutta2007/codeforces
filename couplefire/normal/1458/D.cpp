#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s; cin >> s;
    n = s.length();
    vector<int> ladj(2*n+5, 0), radj(2*n+5, 0);
    int cur = n;
    for(int i = 0; i<n; i++){
        if(s[i] == '0') ladj[cur]++, cur--;
        else radj[cur]++, cur++;
    }
    string ans = "";
    auto dfs = [&](int v, auto&& dfs) -> void {
        if(ladj[v] && radj[v-1]) ans += '0', ladj[v]--, dfs(v-1, dfs);
        else if(radj[v] && ladj[v+1]) ans += '1', radj[v]--, dfs(v+1, dfs);
        else if(ladj[v]) ans += '0', ladj[v]--, dfs(v-1, dfs);
        else if(radj[v]) ans += '1', radj[v]--, dfs(v+1, dfs);
    };
    dfs(n, dfs);
    cout << ans << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}