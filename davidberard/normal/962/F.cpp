#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100100;
const int M = 100100;

namespace BCC {
int vcompNum,ecompNum,I,m;
int first[N],low[N],vis[N],ecomp[N];
int nxt[2*M],ep[2*M],vcomp[2*M];
stack<int> edges, verts;
void init() { m = 0; memset(first, -1, sizeof(first)); }
void add_edge(int a, int b) {
    nxt[m] = first[ep[m] = a], first[ep[m]] = m, ++m;
    nxt[m] = first[ep[m] = b], first[ep[m]] = m; ++m; }
void biconnected(int u, int par){ int v,E; low[u] = vis[u] = ++I; verts.push(u);
  for (int e = first[u]; e != -1; e = nxt[e]) { v = ep[e^1];
    if (!vis[v]) { edges.push(e); biconnected(v,e); low[u] = min(low[u],low[v]);
      if (vis[u] <= low[v]) { // u is a cut vertex unless it's a one-child root
        do { E = edges.top(); edges.pop(); vcomp[E] = vcomp[E^1] = vcompNum; }
        while (e != E && e != (E^1)); ++vcompNum; }}
    else if (vis[v] < vis[u] && e != (par^1)) {
      low[u] = min(low[u], vis[v]); edges.push(e); }
    else if (v == u) vcomp[e] = vcomp[e^1] = vcompNum++; } // e is a self-loop
  if (vis[u] <= low[u]) { // par is a cut edge unless par==-1
    do { v = verts.top(); verts.pop(); ecomp[v] = ecompNum; }
    while (v != u); ++ecompNum; }
}
void get_bcc(int n) { memset(vis,0,sizeof vis); vcompNum=ecompNum=I=0;
  for (int i=0; i<n; ++i) if (!vis[i]) biconnected(i, -1);
}
// tree-independent criteria for identifying articulation points and bridges
bool isCutVertex(int u) { for (int e = first[u]; e != -1; e = nxt[e])
  if (vcomp[e] != vcomp[first[u]]) return true; return false; }
bool isCutEdge(int e) { return ecomp[ep[e]] != ecomp[ep[e^1]]; }
}

int ecount[N];
int esz[N];
unordered_set<int> cont[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  BCC::init();
  vector<pair<int, int>> e;
  for (int i=1; i<=m; ++i) {
    int a, b;
    cin >> a >> b;
    e.emplace_back(a, b);
    BCC::add_edge(a, b);
  }
  BCC::get_bcc(n+1);
  for (int i=0; i<m*2; i+=2) {
    ++esz[BCC::vcomp[i]];
    cont[BCC::vcomp[i]].insert(e[i/2].first);
    cont[BCC::vcomp[i]].insert(e[i/2].second);
  }
  for (int i=0; i<BCC::vcompNum; ++i) {
    ecount[i] = cont[i].size();
  }
  vector<int> g;
  for (int i=0; i<m; ++i) {
    auto [a, b] = e[i];
    //cerr << " x " << a << " " << b << endl;
    if (ecount[BCC::vcomp[i*2]] == esz[BCC::vcomp[i*2]]) {
      g.push_back(i+1);
    }
  }
  cout << g.size() << endl;
  for (auto& x : g) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}