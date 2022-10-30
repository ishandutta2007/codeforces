#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

struct DSU{
    int fa[N];
    DSU(){}
    DSU(int n){
        for(int i = 1; i<=n; ++i)
            fa[i] = i;
    } 
    int find(int v){
        return v==fa[v]?v:fa[v]=find(fa[v]);
    }
    void unite(int u, int v){
        u = find(u), v = find(v);
        if(u==v) return;
        fa[u]  = v;
    }
} d1, d2;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n, m1, m2; cin >> n >> m1 >> m2;
    d1 = DSU(n); d2 = DSU(n);
    for(int i = 0; i<m1; ++i){
        int a, b; cin >> a >> b;
        d1.unite(a, b);
    }
    for(int i = 0; i<m2; ++i){
        int a, b; cin >> a >> b;
        d2.unite(a, b);
    }
    vector<pair<int, int>> edges;
    while(1){
        int a = 1, b = -1;
        for(int i = 1; i<=n; ++i)
            if(d1.find(1) != d1.find(i)){
                b = i; break;
            }
        if(b==-1) break;
        bool work = 0;
        for(int i = 1; i<=n; ++i)
            if(d1.find(a)!=d1.find(i) && d2.find(a)!=d2.find(i)){
                work = 1;
                d1.unite(a, i); d2.unite(a, i);
                edges.push_back({a, i});
                break;
            }
        if(work) continue;
        for(int i = 1; i<=n; ++i)
            if(d1.find(b)!=d1.find(i) && d2.find(b)!=d2.find(i)){
                work = 1;
                d1.unite(b, i); d2.unite(b, i);
                edges.push_back({b, i});
                break;
            }
        if(!work) break;
    }
    cout << edges.size() << '\n';
    for(auto [a, b] : edges)
        cout << a << ' ' << b << '\n';
}