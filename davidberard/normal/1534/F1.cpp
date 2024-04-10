#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 400400;

int low[N],vis[N],scomp[N],scompNum,I;
vector<int> adj[N]; stack<int> verts;
void scc(int u) { low[u] = vis[u] = ++I; verts.push(u);
  for (int v : adj[u]) {
    if (!vis[v]) scc(v);
    if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
  if (vis[u] <= low[u]) { int v;
    do { v=verts.top(); verts.pop(); scomp[v]=scompNum; }while (v != u);
    ++scompNum; }}
void get_scc(int n) {
  memset(vis,0,sizeof vis); memset(scomp,-1,sizeof scomp);
  scompNum=I=0; for (int i=0; i<n; ++i) if (!vis[i]) scc(i); }

int a[N];
int in[N];

unordered_set<int> bdj[N];

int n, m;
int compress(int i, int j) {
  return i*m + j;
}
pair<int, int> decompress(int x) {
  return {x/m, x%m};
}
vector<string> grid;
char gr(int i, int j) {
  if (i < 0 || i >= n) {
    return '.';
  }
  if (j < 0 || j >= m) {
    return '.';
  }
  return grid[i][j];
}
int used_scomp[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  grid = vector<string>(n);
  for (int i=n-1; i>=0; --i) {
    string s;
    cin >> s;
    grid[i] = s;
  }
  for (int i=0; i<m; ++i) {
    cin >> a[i];
  }
  vector<int> vaa;
  for (int j=0; j<m; ++j) {
    int nxtl = -1, nxtb = -1, nxtr = -1;
    for (int i=0; i<n; ++i) {
      if (gr(i, j-1) == '#') {
        nxtl = compress(i, j-1);
      }
      if (gr(i, j+1) == '#') {
        nxtr = compress(i, j+1);
      }
      if (gr(i, j) == '#' && gr(i+1, j) == '#') {
        adj[compress(i, j)].push_back(compress(i+1, j));
        //cerr << " " << compress(i, j) << " -> " << compress(i+1, j) << endl;
      }
      if (gr(i, j) == '#') {
        vaa.push_back(nxtl);
        vaa.push_back(nxtr);
        vaa.push_back(nxtb);
        while (!vaa.empty()) {
          auto v = vaa.back(); vaa.pop_back();
          if (v != -1) {
            //cerr << " " << compress(i, j) << " -> " << v << endl;
            adj[compress(i, j)].push_back(v);
          }
        }
        nxtb = compress(i, j);
      }
    }
  }
  get_scc(n*m);
  for (int i=0; i<n*m; ++i) {
    for (auto& v : adj[i]) {
      if (scomp[i] != scomp[v]) {
        ++in[scomp[v]];
      }
      //cerr << " FROM " << i << " -> " << v << " +in to " << scomp[v] << endl;
      //bdj[scomp[i]].push_back(scomp[v]);
    }
  }
  int ans = 0;
  for (int i=0; i<n*m; ++i) {
    auto [r, c] = decompress(i);
    if (gr(r, c) != '#') {
      continue;
    }
    if (used_scomp[scomp[i]]) {
      continue;
    }
    ans += (in[scomp[i]] == 0);
    //cerr << "! " << i << " -> " << scomp[i] << " : " << in[scomp[i]] << endl;
    used_scomp[scomp[i]]++;
  }
  cout << ans << "\n";
  return 0;
}