#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 400400;
const int INF = 0x3f3f3f3f;
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

int n, m;
vector<string> grid;
int in[N], inc[N], out[N], outc[N];
bool need[N], need_par[N];
pair<int, int> trange[N];
pair<int, int> qrange[N];
string va;
char gr(int i, int j) {
  if (i < 0 || j < 0 || i >= n || j >= m) {
    return '.';
  }
  return grid[i][j];
}
bool qr(int i, int j) {
  return gr(i, j) == '#';
}
int compress(int i, int j) {
  return i*m + j;
}
pair<int, int> decompress(int x) {
  return {x/m, x%m};
}

unordered_set<int> bdj[N];
vector<int> rvals[N];

int a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  grid = vector<string>(n);
  for (int i=n-1; i>=0; --i) {
    cin >> grid[i];
  }
  for (int i=0; i<n; ++i) {
    va += grid[i];
  }
  for (int i=0; i<m; ++i) {
    cin >> a[i];
  }

  // build graph
  vector<int> tadj;
  for (int j=0; j<m; ++j) {
    int lx = -1, bx = -1, rx = -1;
    for (int i=0; i<n; ++i) {
      if (qr(i, j-1)) {
        lx = compress(i, j-1);
      }
      if (qr(i, j+1)) {
        rx = compress(i, j+1);
      }
      if (qr(i, j)) {
        if (qr(i+1, j)) {
          adj[compress(i, j)].push_back(compress(i+1, j));
        }
        tadj.push_back(bx);
        tadj.push_back(lx);
        tadj.push_back(rx);
        while (!tadj.empty()) {
          int x =tadj.back(); tadj.pop_back();
          if (x != -1) {
            adj[compress(i, j)].push_back(x);
          }
        }

        bx = compress(i, j);
      }
    }
  }

  // build scc
  get_scc(n*m);
  // build DAG graph on the SCC components
  unordered_set<int> valid_scomp;
  for (int i=0; i<m*n; ++i) {
    if (va[i] == '#') {
      valid_scomp.insert(scomp[i]); // only components containing '#'
      for (auto& v : adj[i]) {
        if (scomp[i] != scomp[v]) {
          bdj[scomp[i]].insert(scomp[v]);
        }
      }
    }
  }

  // trange[i] will store the range of special column indices of the vertices in a component i
  for (int i=0; i<m*n; ++i) {
    trange[i] = {INF, -1};
  }
  // identify the special vertices & their components
  for (int j=0; j<m; ++j) {
    if (a[j] == 0) {
      continue;
    }
    int zcnt = 0;
    for (int i=0; i<n; ++i) {
      if (gr(i, j) == '#') {
        ++zcnt;
        if (zcnt == a[j]) {
          int x = scomp[compress(i, j)];
          trange[x].first = min(trange[x].first, j);
          trange[x].second = min(trange[x].second, j);
          need[x] = 1;
          break;
        }
      }
    }
  }

  // iterate through dag to find which components are "special"
    queue<int> q;

    for (auto& x : valid_scomp) {
      for (auto& v : bdj[x]) {
        ++in[v];
      }
    }
    for (auto& x : valid_scomp) {
      if (!in[x]) {
        q.push(x);
      }
    }
    vector<int> special;
    vector<int> dag_order;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      dag_order.push_back(u);
      // special components: have an a[i]-th '#' in an i-th column, and no parent component has such a vertex
      if (need[u] && !need_par[u]) {
        special.push_back(u);
      }
      for (auto& v : bdj[u]) {
        if (need[u]) {
          need[v] = 1;
          need_par[v] = 1;
        }
        if (--in[v] == 0) {
          q.push(v);
        }
      }
    }
    // sort the special nodes and index them from left to right
    sort(special.begin(), special.end(), [&](const int& a, const int& b) {
      return trange[a].first + trange[a].second < trange[b].first + trange[b].second;
    });
    for (int i=0; i<n*m; ++i) {
      qrange[i] = {INF, -1};
    }
    for (int i=0; i<special.size(); ++i) { //indexing the special nodes
      int x = special[i]; 
      qrange[x].first = qrange[x].second = i;
    }

    // go through dag in reverse order and assign an range of special node indices to each scc component
    reverse(dag_order.begin(), dag_order.end());
    for (auto& u : dag_order) {
      for (auto& x : bdj[u]) {
        qrange[u].first = min(qrange[u].first, qrange[x].first);
        qrange[u].second = max(qrange[u].second, qrange[x].second);
      }
      if (qrange[u].first != INF) {
        rvals[qrange[u].first].push_back(qrange[u].second);
      }
    }
    // greedily select segments from left to right
    int qfree = 0;
    int qnxt = 0;
    int ans = 0;
    while (qfree < special.size()) {
      int rmax = -1;
      while (qnxt <= qfree) {
        for (auto& rv : rvals[qnxt]) {
          rmax = max(rmax, rv);
        }
        ++qnxt;
      }
      ++ans;
      qfree = rmax+1;
    }
    cout << ans << "\n";


  return 0;
}