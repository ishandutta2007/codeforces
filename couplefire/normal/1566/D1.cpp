#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    map<int, vector<int>> mp;
    vector<array<int, 2>> pos(n*m);
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for(int i = 0; i<n*m; ++i){
        int a; cin >> a;
        mp[a].push_back(i);
    }
    int cur = 0;
    for(auto [a, b] : mp){
        sort(b.rbegin(), b.rend());
        for(int i = (int)b.size()-1; i>=0; --i, ++cur){
            if(i==0 || cur%m==m-1){
                int start = cur-((int)b.size()-1-i);
                int tmp = i;
                for(int j = start; j<=cur; ++j)
                    pos[b[i]] = {j/m, j%m}, ++i;
                while((int)b.size()-1>=tmp) b.pop_back();
                i = (int)b.size();
            }
        }
    }
    int ans = 0;
    for(int a = 0; a<n*m; ++a){
        int i = pos[a][0], j = pos[a][1];
        for(int b = 0; b<=j; ++b)
            if(vis[i][b]) ++ans;
        vis[i][j] = 1;
    }
    cout << ans << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}