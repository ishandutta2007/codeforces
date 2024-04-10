#include <bits/stdc++.h>

#define int long long
using namespace std;
vector<vector<int> > data;
int mod = 998244353;
vector<int> fact;
vector<int> sz;
int n;
int dfs(int vertex, int last){
    int P = 1;
    int cur=0;
    sz[vertex]=1;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (to == last) continue;
        P = (P*dfs(to, vertex))%mod;
        sz[vertex] += sz[to];
        cur++;
    }
    int res = (P*fact[cur])%mod;
    //cout << vertex << " " << cur << " " << res<< endl;
    if (vertex == 0) return (res*n)%mod;
    return (res*(cur+1))%mod;
}
main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    data.resize(n, {});
    sz.resize(n, -1);
    for (int i=0;i<n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        data[u].push_back(v), data[v].push_back(u);
    }
    fact.push_back(1);
    for (int i=1; i <= n+10; i++){
        fact.push_back((fact.back()*i)%mod);
    }
    cout << dfs(0,-1);
}