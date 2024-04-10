#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i<n; ++i)
        cin >> grid[i];
    vector<int> bad;
    for(int i = 0; i<m-1; ++i){
        bool found = 0;
        for(int j = 1; j<n; ++j)
            if(grid[j][i]=='X' && grid[j-1][i+1]=='X')
                {found=1; break;}
        if(found) bad.push_back(i+1);
    }
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        auto it = lower_bound(bad.begin(), bad.end(), l);
        if(it==bad.end() || (*it)>=r) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}