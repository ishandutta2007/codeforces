#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100005;

int n, q, l, ans;
vector<array<int, 2>> adj[N];
int tmp[N], dist[N], root, fa[N];
int psum[N]; vector<array<int, 2>> st;

void dfs1(int v, int p){
    for(auto u : adj[v]){
        if(u[0] == p) continue;
        tmp[u[0]] = tmp[v]+u[1];
        dfs1(u[0], v);
    }
}

void dfs2(int v, int p){
    fa[v] = p;
    st.push_back(array<int, 2>{dist[v], v});
    int x = (*lower_bound(st.begin(), st.end(), array<int, 2>{dist[v]-l, 0}))[1];
    if(fa[x] >= 0) psum[fa[x]]--;
    psum[v]++;
    for(auto u : adj[v]){
        if(u[0] == p) continue;
        dfs2(u[0], v);
    }
    st.pop_back();
}

void dfs3(int v, int p){
    for(auto u : adj[v]){
        if(u[0] == p) continue;
        dfs3(u[0], v);
        psum[v] += psum[u[0]];
    }
    ans = max(ans, psum[v]);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n-1; i++){
        int a, b, w; cin >> a >> b >> w; --a, --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    dfs1(0, -1);
    int _u = max_element(tmp, tmp+n)-tmp;
    memset(tmp, 0, sizeof tmp);
    dfs1(_u, -1);
    int _v = max_element(tmp, tmp+n)-tmp;
    swap(tmp, dist);
    dfs1(_v, -1);
    for(int i = 0; i<n; i++) dist[i] = max(dist[i], tmp[i]);
    root = min_element(dist, dist+n)-dist;
    cin >> q;
    while(q--){
        cin >> l;
        ans = 0;
        memset(psum, 0, sizeof psum);
        dfs2(root, -1);
        dfs3(root, -1);
        cout << ans << endl;
    }
}