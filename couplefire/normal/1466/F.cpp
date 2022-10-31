#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define MOD 1000000007

struct DSU{
    int parent[MAXN];
    int siz[MAXN];

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]); 
    }

    void make_set(int v) {
        parent[v] = v;
        siz[v] = 1;
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (siz[a] < siz[b])
                swap(a, b);
            parent[b] = a;
            siz[a] += siz[b];
        }
    }
};

vector<pair<int, pair<int, int>>> edges;
DSU dsu;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i<n; i++){
        int k; cin >> k;
        int a, b; cin >> a;
        if(k > 1) cin >> b;
        else b = m+1;
        edges.push_back({i, {a, b}});
    }
    sort(edges.begin(), edges.end());
    for(int i = 1; i<=m+1; i++) dsu.make_set(i);
    int cnt = 0;
    vector<int> ans;
    for(auto e : edges){
        if(dsu.find_set(e.second.first) != dsu.find_set(e.second.second)){
            cnt++; ans.push_back(e.first);
            dsu.union_sets(e.second.first, e.second.second);
        }
    }
    int cur = 1;
    while(cnt--) cur = cur*2%MOD;
    cout << cur << " " << ans.size() << endl;
    for(auto x : ans) cout << x+1 << " ";
    cout << endl;
}