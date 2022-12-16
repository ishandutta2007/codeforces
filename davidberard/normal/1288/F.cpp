#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

namespace mcf {
    const int N = 600;
    const ll INF = 0x3f3f3f3f3f3f3f3f;
  struct Edge { int v, r; ll f, c, p; };
  vector<Edge> adj[N]; int sz[N]; ll mc;
  vector<Edge> mcf_edges; // for mcf on large graphs with negative costs
  void init(int n=N) { mc=0; fill(sz,sz+n,0); fill(adj,adj+n,vector<Edge>()); }
  void add_edge(int a, int b, ll c=1, ll p=0) { mc = max(mc,c);  // scaling
    adj[a].push_back({b,sz[b]++,0,c,p}); // mcf_edges.push_back({b,a,0,c,p});
    adj[b].push_back({a,sz[a]++,0,0,-p}); 
    //cerr << " " << a << " -> " << b << " CAP " << c << " PRICE " << p << endl;
    }

  bool vis[N]; int par[N]; ll pot[N], dist[N];
  void pot_init(int n) { fill(pot, pot+n, 0);
    // if all edge costs >= 0, we don't need to run the Bellman-Ford here
    for(int i=1; i<n; i++) for(const Edge& e:mcf_edges)
      if(e.c) pot[e.v] = min(pot[e.v], pot[e.r] + e.p); }
  ll mcf(int s, int t, ll& price, int n, bool sparse) {
    fill(vis, vis+n, 0); fill(dist, dist+n, INF); dist[s] = 0;
    // only need one of the branches below
    if(sparse) {  // replace priority_queue with queue for SPFA
      priority_queue<pair<ll,int>> dk; dk.push({0,s}); while(!dk.empty()) {
        int u = dk.top().second; dk.pop(); if(vis[u]) continue;
        for(const Edge& e:adj[u]) {  // BUBL;BUBL;BUBL;BUBL;BUBL;BUBL;BUBL;
          if (e.f < e.c && dist[e.v] > dist[u] + pot[u] - pot[e.v] + e.p) {
            dist[e.v] = dist[u] + pot[u] - pot[e.v] + e.p; par[e.v] = e.r;
            dk.push({-dist[e.v], e.v}); } } }
    } else {  // dense
      for(int u = s; u != -1; ) { vis[u] = true; for(const Edge& e: adj[u]) {
        if (e.f < e.c && dist[e.v] > dist[u] + pot[u] - pot[e.v] + e.p) {
          dist[e.v] = dist[u] + pot[u] - pot[e.v] + e.p; par[e.v] = e.r; } }
      u = -1; ll best = INF;
      for(int i=0; i<n; i++) if(!vis[i] && dist[i]<best) best = dist[u=i]; }
    }  // end branches
    if (dist[t] >= INF) { return 0; } ll df = INF;
    for(int u = t; u != s; ) { const Edge& r = adj[u][par[u]];
      df = min(df, adj[r.v][r.r].c - adj[r.v][r.r].f); u = r.v; }
    for(int u = t; u != s; ) { Edge& r=adj[u][par[u]], &e=adj[r.v][r.r];
      e.f += df; r.f -= df; price += df*e.p; u = r.v; }
    for(int i=0; i<n; i++) { pot[i] = min(INF, dist[i]+pot[i]); } return df; }
  ll min_cost_flow(int s, int t, ll& price, int n=N, bool sparse=false) {
    pot_init(n); ll flow = price = 0;
    while(ll df=mcf(s, t, price, n, sparse)) { flow += df; } return flow; }
}

int SEP = 205;
int s = 550;
int sp = 551;
int t = 552;
int tp = 553;

char col1[205], col2[205];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n1, n2, m, r, b;
    cin >> n1 >> n2 >> m >> r >> b;
    cin >> col1 >> col2;
    mcf::init(tp+10);
    mcf::pot_init(tp+10);
    int spcap = 0;
    for (int i=0; i<n1; ++i) {
        int u = i;
        if (col1[i] == 'R') {
            mcf::add_edge(s, u, 1e8, 0);
            mcf::add_edge(sp, u, 1, 0);
            mcf::add_edge(s, tp, 1, 0);
            ++spcap;
        } else if (col1[i] == 'B') {
            mcf::add_edge(u, t, 1e8, 0);
            mcf::add_edge(u, tp, 1, 0);
            mcf::add_edge(sp, t, 1, 0);
            ++spcap;
        } else {
            mcf::add_edge(u, t, 1e8, 0);
            mcf::add_edge(s, u, 1e8, 0);
        }
    }
    for (int i=0; i<n2; ++i) {
        int u = SEP+i;
        if (col2[i] == 'R') {
            ++spcap;
            mcf::add_edge(u, t, 1e8, 0);
            mcf::add_edge(u, tp, 1, 0);
            mcf::add_edge(sp, t, 1, 0);
        } else if (col2[i] == 'B') {
            ++spcap;
            mcf::add_edge(s, u, 1e8, 0);
            mcf::add_edge(sp, u, 1, 0);
            mcf::add_edge(s, tp, 1, 0);
        } else {
            mcf::add_edge(u, t, 1e8, 0);
            mcf::add_edge(s, u, 1e8, 0);
        }
    }

    map<pii, vector<int>> mp;

    for (int q=0; q<m; ++q) {
        int u, v;
        cin >> u >> v;
        u += -1;
        v += SEP-1;
        mp[pii(u, v)].push_back(q);
        mcf::add_edge(u, v, 1, r);
        mcf::add_edge(v, u, 1, b);
    }

    mcf::add_edge(t, s, 1e8, 0);

    ll price = 0;
    ll flow_amount = mcf::min_cost_flow(sp, tp, price);
    if (flow_amount != spcap) {
        cout << -1 << endl;
    } else {
        cout << price << endl;
        vector<char> ans(m, 'U');
        for (int i=0; i<tp; ++i) {
            for (auto& e : mcf::adj[i]) {
                int j = e.v;
                if (e.f && e.p == r && mp.count(pii(i, j))) {
                    int ind = mp[pii(i, j)].back();
                    mp[pii(i, j)].pop_back();
                    ans[ind] = 'R';
                } else if (e.f && e.p == b && mp.count(pii(j, i))) {
                    int ind = mp[pii(j, i)].back();
                    mp[pii(j, i)].pop_back();
                    ans[ind] = 'B';
                }
            }
        }
        for (auto& c : ans) {
            cout << c;
        }
        cout << endl;
    }


    return 0;
}