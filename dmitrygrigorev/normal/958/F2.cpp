#include <bits/stdc++.h>
using namespace std;
signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    vector<int> x(m);
    for (int i=0; i < m; i++) cin >> x[i];
    vector<vector<int> > g(m);
    for (int i=0; i < n; i++){
        g[v[i]-1].push_back(i);
        v[i]--;
    }
    for (int i=0; i < m; i++) g[i].push_back(n);
    multiset<int> F;
    int res = 1e8;
    int t=0;
    for (int i=0; i < m; i++) t += x[i];
    for (int i=0; i < m; i++){
        if (x[i] >= g[i].size()){
            if (res==1e8){
                cout << -1;
            }
            else cout << res-t;
            return 0;
        }
        if (x[i] != 0){
            F.insert(g[i][x[i]-1]);
        }
    }
    for (int i=0; i < n; i++){
        multiset<int>::iterator it = F.end();
        it--;
        int L = *it;
        res = min(res, L-i+1);
        if (x[v[i]] != 0){
            F.erase(F.find(g[v[i]][x[v[i]]-1]));
        }
        x[v[i]]++;
        if (x[v[i]] >= g[v[i]].size()){
            if (res==1e8){
                cout << -1;
            }
            else cout << res-t;
            return 0;
        }
        F.insert(g[v[i]][x[v[i]]-1]);
    }
    return 0;
}