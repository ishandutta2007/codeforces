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
vector<int> h;
set<pair<int, int> > blocked;

void dfs(int vertex, int last, int d, vector<int> &path) {

  path.pb(vertex);

  h[vertex] = d;
  for (auto to : gr[vertex]) {
    if (to == last) continue;
    if (h[to] == -1) {
      dfs(to, vertex, d+1, path);
      continue;
    }

    if (h[to] > h[vertex]) continue;
    blocked.insert(mp(vertex, to));

    for (int i = 0; i < h[vertex] - h[to]; ++i) {
      blocked.insert(mp(path[path.size() - i - 1], path[path.size() - i - 2]));
    }
  }

  path.pop_back();

}

vector<pair<int, int> > ans;
vector<bool> used;

int Z;

int dfs2(int vertex, int last) {

  int tut = -1;
  used[vertex] = true;

  int ed = -1;

  for (auto x : gr[vertex]) {
    if (x == last) continue;
    int R = dfs2(x, vertex);

    if (R == x) {
      if (ed == -1) {
        ed = R;
        continue;
      }
    }

    if (tut == -1) tut = R;
    else {
      ans.pb(mp(tut, R));
      tut = -1;
    }
  }

  if (tut == -1) {
    tut = ed;
    ed = -1;
  }

  if (vertex == Z && tut != -1 && ed != -1) {
    ans.pb(mp(tut, ed));
    tut = -1, ed = -1;
  }

  if (tut != -1) return tut;
  return vertex;

}

void solve(int n, int m) {

  gr.assign(n, {});
  blocked.clear();

  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;

    vector<int> v(k);
    for (auto &x : v) cin >> x;

    for (int i = 1; i < k; ++i) {
      int a = v[i], b = v[i-1];
      a--, b--;
      gr[a].pb(b);
      gr[b].pb(a);
    }
  }

  h.assign(n, -1);

  vector<int> path;

  dfs(0, -1, 0, path);
  for (int i = 0; i < n; ++i) {
    int u = 0;
    while (u < gr[i].size()) {
      int to = gr[i][u];
      if (blocked.count(mp(i, to)) || blocked.count(mp(to, i))) {
        swap(gr[i][u], gr[i].back());
        gr[i].pop_back();
      }
      else u++;
    }
  }

  used.assign(n, false);
  ans.clear();

  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    Z=i;
    int Q = dfs2(i, -1);
    if (Q != i) {
      for (auto x : gr[i]) if (Q == x) Q = i;
      if (Q != i) {
        ans.pb(mp(Q, i));
      }
    }
  }

  cout << ans.size() << '\n';
  for (auto x : ans) cout << x.x+1 << " " << x.y+1 << '\n';




}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  while (true) {

    int n, m;
    cin >> n >> m;

    if (n == 0 && m == 0) exit(0);
    solve(n, m);

  }

}