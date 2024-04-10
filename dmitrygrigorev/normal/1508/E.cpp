#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > gr;
vector<int> labels;

int add = 0;

void dfs1(int vertex, int ps) {
  if (labels[vertex] == ps) {
    int to = -1, val = 1e9;
    for (auto x : gr[vertex]) {
      if (labels[x] > labels[vertex] && labels[x] < val) {
        val = labels[x];
        to = x;
      }
    }

    if (to != -1) {
      add++;
      swap(labels[vertex], labels[to]);
    }
  }

  for (auto x : gr[vertex]) dfs1(x, ps);

}

vector<int> pos;
vector<int> tin;
vector<int> tout;
vector<int> h;

int timer = 0;

void dfs2(int vertex, int d) {
  tin[vertex] = timer++;
  h[vertex] = d;

  pos[labels[vertex]] = vertex;
  for (auto x : gr[vertex]) dfs2(x, d+1);

  tout[vertex] = timer++;

}

vector<int> father;
vector<int> deg;

void gone() {
  cout << "NO";
  exit(0);
}

bool good(int u, int v) {
  if (tin[u] <= tin[v] && tout[u] >= tout[v]) return true;
  return false;
}

ll ans = 0;

vector<vector<int> > true_order;

vector<int> res;

void dfs3(int vertex) {
  res[vertex] = timer++;
  for (auto x : true_order[vertex]) dfs3(x);
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  true_order.assign(n, {});
  res.assign(n, -1);

  father.assign(n, -1);
  deg.assign(n, 0);

  gr.assign(n, {});
  labels.assign(n, -1);

  for (auto &x : labels) {
    cin >> x;
    x--;
  }

  for (int i = 0; i < n-1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    father[v] = u;
    deg[u]++;
    gr[u].pb(v);
  }

  if (labels[0] != 0) {
    dfs1(0, labels[0] - 1);
  }

  pos.assign(n, -1);
  tin.assign(n, -1);
  tout.assign(n, -1);
  h.assign(n, -1);


  dfs2(0, 0);

  ans -= add;

  int W = 0;

  if (labels[0] != 0) {
    W = pos[0];
    if (gr[W].size()) {
      gone();
    }

    for (int i = 0; i < labels[0]; ++i) {
      ans += h[pos[i]];

      int H = W;

      W = father[W];
      deg[W]--;

      if (W == -1) {
        gone();
      }

      true_order[W].pb(H);

      if (i + 1 == labels[0]) break;

      if (!good(W, pos[i + 1])) gone();
      W = pos[i + 1];
      if (deg[W]) gone();
    }

    vector<int> path;
    int Z = W;
    while (Z != -1) {
      path.pb(labels[Z]);
      Z = father[Z];
    }

    int must = labels[0];
    while (path.size()) {
      if (path.back() != must) gone();
      must++;
      path.pop_back();
    }
  }

  int must = labels[0] + h[W] + 1;
  while (W != -1) {

    if (deg[W] == 0) {

      int H = W;

      W = father[W];
      if (W!=-1) {
        deg[W]--;
        true_order[W].pb(H);
      }
    }

    else {
      int Q = pos[must];
      if (h[Q] - 1 == h[W]) {
        W = Q;
        must++;
      }
      else gone();
    }

  }
  if (must != n) gone();
  cout << "YES\n";
  cout << ans << '\n';

  timer = 0;
  dfs3(0);
  for (auto x : res) cout << x+1 << " ";




}