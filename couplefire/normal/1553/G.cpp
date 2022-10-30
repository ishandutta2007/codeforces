#include <bits/stdc++.h>
using namespace std;

const int N = 150005;
const int MX = 1000005;

int fa[N], siz[N];

int find(int v){
    return v==fa[v]?v:fa[v] = find(fa[v]);
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if(u==v) return;
    if(siz[u]>siz[v]) swap(u, v);
    fa[u] = v; siz[v] += siz[u];
}

int n, q;
int arr[N], lp[MX];
vector<int> fact[MX], primes, stuff[MX];
set<array<int, 2>> st;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    for(int i = 0; i<n; i++)
        fa[i] = i, siz[i] = 1;
    for(int i = 2; i<MX; ++i){
        if(!lp[i]){
            lp[i] = i; primes.push_back(i);
            for(int j = 1; j*i<MX; ++j)
                fact[j*i].push_back(i);
        }
        for(int j = 0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<N; ++j)
            lp[i*primes[j]] = primes[j];
    }
    for(int i = 0; i<n; i++)
        for(auto p : fact[arr[i]])
            stuff[p].push_back(i);
    for(int i = 0; i<MX; i++)
        for(int j = 0; j<(int)stuff[i].size()-1; ++j)
            unite(stuff[i][j], stuff[i][j+1]);
    for(int i = 0; i<n; i++){
        vector<int> comp{find(i)};
        for(auto p : fact[arr[i]+1])
            if(stuff[p].size()) comp.push_back(find(stuff[p].back()));
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());
        for(int i = 0; i<(int)comp.size(); ++i)
            for(int j = i+1; j<(int)comp.size(); ++j)
                st.insert({comp[i], comp[j]});
    }
    while(q--){
        int u, v; cin >> u >> v; --u; --v;
        u = find(u), v = find(v);
        if(u > v) swap(u, v);
        if(u == v) cout << 0 << '\n';
        else if(st.count({u, v})) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}