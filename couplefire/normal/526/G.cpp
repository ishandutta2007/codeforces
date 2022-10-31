#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, q, ans;
vector<array<int, 2>> adj[N];

struct Tree{
    int root, dist[N], max_dist[N], heavy[N], time[N], order[N], val[N], psum[N], top[N], cnt;
    int anc[N][20];

    void dfs1(int v, int p){
        for(auto u : adj[v]){
            if(u[0] == p) continue;
            dist[u[0]] = dist[v]+u[1];
            dfs1(u[0], v);
        }
    }

    void dfs2(int v, int p){
        max_dist[v] = dist[v];
        anc[v][0] = p;
        for(int i = 1; i<20; i++) anc[v][i] = anc[anc[v][i-1]][i-1];
        for(auto u : adj[v]){
            if(u[0] == p) continue;
            dist[u[0]] = dist[v]+u[1];
            dfs2(u[0], v);
            if(heavy[v] == -1 || max_dist[u[0]] > max_dist[heavy[v]])
                heavy[v] = u[0], max_dist[v] = max_dist[u[0]];
        }
    }

    void dfs3(int v, int p, int tp){
        top[v] = tp;
        val[v] = max_dist[v]-dist[anc[v][0]];
        if(heavy[v] >= 0) dfs3(heavy[v], v, tp);
        for(auto u : adj[v]){
            if(u[0] == p || u[0] == heavy[v]) continue;
            dfs3(u[0], v, u[0]);
        }
    }

    void init(int x){
        dfs1(x, x);
        root = max_element(dist, dist+n)-dist;
        memset(dist, 0, sizeof dist);
        memset(heavy, -1, sizeof heavy);
        dfs2(root, root);
        dfs3(root, root, root);
        for(int i = 0; i<n; i++)
            if(top[i] == i) order[cnt++] = i;
        sort(order, order+cnt, [&](int a, int b){
            return val[a] > val[b];
        });
        for(int i = 0; i<cnt; i++){
            int v = order[i];
            while(v >= 0) time[v] = i, v = heavy[v];
        }
        psum[0] = val[order[0]];
        for(int i = 1; i<cnt; i++) psum[i] = psum[i-1]+val[order[i]];
    }

    int solve1(int v, int t){
        if(time[v] <= 2*t-2) return psum[min(2*t-2, cnt-1)];
        t = 2*t-3;
        int u = v;
        for(int i = 19; i>=0; i--)
            if(time[anc[u][i]] > t) u = anc[u][i];
        u = anc[u][0];
        return psum[t]+max_dist[v]-dist[u];
    }

    int solve2(int v, int t){
        if(time[v] <= 2*t-2) return psum[min(2*t-2, cnt-1)];
        t = 2*t-2;
        int u = v;
        for(int i = 19; i>=0; i--)
            if(time[anc[u][i]] > t) u = anc[u][i];
        u = anc[u][0];
        return psum[t]-max_dist[u]+max_dist[v];
    }

    int query(int v, int t){
        return max(solve1(v, t), solve2(v, t));
    }
} tree[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 0; i<n-1; i++){
        int a, b, w; cin >> a >> b >> w; --a; --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    tree[0].init(0); tree[1].init(tree[0].root);
    while(q--){
        int v, t; cin >> v >> t;
        v = (v+ans-1)%n+1; v--;
        t = (t+ans-1)%n+1;
        ans = max(tree[0].query(v, t), tree[1].query(v, t));
        cout << ans << endl;
    }
}