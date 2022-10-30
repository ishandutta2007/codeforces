#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

struct DSU{
    vector<int> fa;
    vector<vector<int>> comps;
    set<pair<int, int>> st;
    DSU(){}
    DSU(int n){
        fa.resize(n+1);
        comps.resize(n+1);
        for(int i = 1; i<=n; ++i)
            fa[i] = i;
        for(int i = 1; i<=n; ++i)
            st.insert({1, i});
        for(int i = 1; i<=n; ++i)
            comps[i] = {i};
    } 
    int find(int v){
        return v==fa[v]?v:fa[v]=find(fa[v]);
    }
    void unite(int u, int v){
        u = find(u), v = find(v);
        if(u==v) return;
        if(comps[u].size()>comps[v].size()) swap(u, v);
        fa[u] = v; 
        st.erase({(int)comps[u].size(), u});
        st.erase({(int)comps[v].size(), v});
        for(int x : comps[u]) comps[v].push_back(x);
        st.insert({(int)comps[v].size(), v});
        comps[u].clear();
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
        if(d1.st.size()==1 || d2.st.size()==1) break;
        DSU& a = d1, &b = d2;
        if(a.st.begin()->f+next(a.st.begin())->f > b.st.begin()->f+next(b.st.begin())->f)
            swap(a, b);
        int c1 = a.st.begin()->s;
        int c2 = next(a.st.begin())->s;
        int u = a.comps[c1][0], v = a.comps[c2][0];
        bool work = 0;
        for(int x : a.comps[c2])
            if(b.find(u)!=b.find(x)){
                edges.push_back({u, x});
                a.unite(u, x); b.unite(u, x);
                work = 1; break;
            }
        if(work) continue;
        for(int x : a.comps[c1])
            if(b.find(v)!=b.find(x)){
                edges.push_back({v, x});
                a.unite(v, x); b.unite(v, x);
                work = 1; break;
            }
        if(!work){
            int tmp = b.st.begin()->s;
            if(b.find(u)==1) tmp = next(b.st.begin())->s;
            v = b.comps[tmp][0];
            edges.push_back({u, v});
            a.unite(u, v); b.unite(u, v);
        }
    }
    cout << edges.size() << '\n';
    for(auto [a, b] : edges)
        cout << a << ' ' << b << '\n';
}