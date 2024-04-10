#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Vertex {
  int f;
  int r;
};

vector<Vertex> snm;

int get(int v) {
  if (snm[v].f == v) return v;
  return get(snm[v].f);
}

void unite(int u, int v) {
  if (snm[u].r > snm[v].r) swap(u, v);
  snm[u].f = v;
  if (snm[u].r == snm[v].r) snm[v].r++;
} 

set<int> used;

struct Edge
{
  int x;
  int y;
  int w;
};

vector<vector<int> > gr;
vector<vector<int> > components;

vector<int> N;

void dfs(int vertex) {

  N.pb(vertex);

  set<int> nei;
  for (auto x : gr[vertex]) nei.insert(x);

  set<int> nused;
  vector<int> to_go;

  for (auto x : used) {
    if (nei.count(x)) {
      nused.insert(x);
    }
    else {
      to_go.pb(x);
    }
  }

  used = nused;
  for (auto to : to_go) {
    dfs(to);
  }

}

bool cmp(Edge &a, Edge &b) {
  return (a.w < b.w);
}

vector<vector<pair<int, int> > > tree;
vector<int> order;

vector<int> h;

void dfs2(int vertex, int last, int ed) {
  if (last == -1) {
    h[vertex] = 0;
    order[vertex] = 0;
  }
  else {
    h[vertex] = h[last] + 1;
    if (ed == 0) order[vertex] = 0;
    else order[vertex] = order[last] + 1;
  }

  for (auto p : tree[vertex]) {
    if (p.x == last) continue;
    dfs2(p.x, vertex, p.y);
  }
}

struct FastLCA{

  static const int N = 524288, LG = 21; //N >= 2*n + 7 and N = 2^k

  vector<vector<int> > data;
  vector<int> euler, where, depth, logs;
  int table[N][LG];

  void dfs(int vertex, int last, int d){
      where[vertex] = euler.size();
      euler.push_back(vertex);
      depth[vertex] = d;
      for (int i=0; i < (int) data[vertex].size(); i++){
          int to = data[vertex][i];
          if (to==last) continue;
          dfs(to, vertex, d + 1);
          euler.push_back(vertex);
      }
  }

  void init(vector<pair<int, int> > edges) { //edges are given in 0-indexation
    int n = edges.size() + 1;
    data.assign(n, {}), where.assign(n, -1), depth.assign(n, -1);
    for (int i = 0; i < edges.size(); ++i) {
      int u = edges[i].first, v = edges[i].second;
      data[u].push_back(v), data[v].push_back(u);
    }
    dfs(0, -1, 0);


    int sz = euler.size();
      for (int i=0; i < sz; i++){
          table[i][0] = euler[i];
      }
    int counter = 1;
      int start_log = 1;
      logs.push_back(0);
      for (int i=2; i <= N; i*=2){
          for (int j=0; j + i <= sz; j++){
              int fv = table[j][counter - 1];
              int sv = table[j + i/2][counter-1];
              if (depth[fv] <= depth[sv]) table[j][counter] = fv;
              else table[j][counter] = sv;
          }
          for (int j=start_log; j <= i; j++){
              logs.push_back(counter - 1);
          }
          start_log = i + 1;
          counter += 1;
      }
  }

  int get(int q1, int q2) { //queries are given in 0-indexation
    int first = where[q1];
        int second = where[q2];
        if (first > second) swap(first, second);
        int dist = second - first + 1;
        int first_cand = table[first][logs[dist]];
        int second_cand = table[second + 1 - (1 << logs[dist])][logs[dist]];
        int ans;
        if (depth[first_cand] < depth[second_cand]) ans = first_cand;
        else ans = second_cand;
        return ans;
  }

};

FastLCA f;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m;
  cin >> n >> m;

  tree.assign(n, {});

  vector<pair<int, int> > R;

  gr.assign(n, {});
  vector<Edge> edges;

  int X = 0;

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;

    X ^= c;

    gr[a].pb(b);
    gr[b].pb(a);
    edges.pb({a, b, c});
  }

  for (int i = 0; i < n; ++i) used.insert(i);
  for (int i = 0; i < n; ++i) {
    if (used.count(i)) {
      N.clear();
      used.erase(used.find(i));
      dfs(i);
      components.pb(N);
    }
  }

  for (int i = 0; i < n; ++i) snm.pb({i, 1});

  for (auto x : components) {
    for (int i = 1; i < x.size(); ++i) {

      int z = x[i], q = x[i-1];
      tree[z].pb(mp(q, 0));
      tree[q].pb(mp(z, 0));
      R.pb(mp(z, q));

      int A = get(x[i]), B = get(x[i-1]);
      unite(A, B);
    }
  }

  ll total = 0;
  for (auto e : edges) {
    int A = get(e.x), B = get(e.y);
    if (A == B) total++;
  }

  ll mx = 0;
  for (auto x : components) {
    int S = x.size();
    mx += (ll) S * (S - 1) / 2 - (S-1);
  }

  ll must_spend = 0;
  ll min_betw = 2e9;

  sort(all(edges), cmp);

  vector<Edge> toc;

  for (auto e : edges) {
    int A = get(e.x), B = get(e.y);
    if (A != B) {
      must_spend += e.w;
      unite(A, B);

      int z = e.x, q = e.y;
      tree[z].pb(mp(q, 1));
      tree[q].pb(mp(z, 1));
      R.pb(mp(z, q));

    }
    else toc.pb(e);
  }

  f.init(R);

  h.assign(n, -1);
  order.assign(n, -1);
  dfs2(0, -1, -1);

  for (auto e : toc) {
    int L = f.get(e.x, e.y);
    if (order[e.x] >= h[e.x] - h[L] && order[e.y] >= h[e.y] - h[L]) continue;
    min_betw = min(min_betw, (ll) e.w);
  }

  if (total != mx) {
    cout << must_spend;
  }
  else {
    cout << must_spend + min((ll) X, min_betw);
  }




}