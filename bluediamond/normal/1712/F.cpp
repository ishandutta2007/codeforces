#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
/// #define int long long

struct T {
  int a;
  int b;
};

const int N = (int) 1e6 + 77;
const int INF = (int) 1e9 + 7;
int n;
int q;
int dist[N];
vector<int> g[N];
int min_dist[N];
vector<int> queries;
vector<int> results;
bool blocked[N];
int sub[N];
int total;
int max_a;
vector<T> current;

void place(int a, int p = -1) {
  current.push_back({dist[a], min_dist[a]});
  for (auto &b : g[a]) {
    if (blocked[b] || b == p) continue;
    place(b, a);
  }
}

void build_sub(int a, int p = -1) {
  sub[a] = 1;
  for (auto &b : g[a]) {
    if (blocked[b] || b == p) continue;
    build_sub(b, a);
    sub[a] += sub[b];
  }
}

int fcen(int a, int p = -1) {
  int mx = total - sub[a];
  for (auto &b : g[a]) {
    if (blocked[b] || b == p) continue;
    mx = max(mx, sub[b]);
  }
  if (mx <= total / 2) {
    return a;
  }
  for (auto &b : g[a]) {
    if (blocked[b] || b == p) continue;
    if (mx == sub[b]) {
      return fcen(b, a);
    }
  }
  assert(0);
}

void build_dist(int a, int p = -1) {
  max_a = max(max_a, dist[a]);
  for (auto &b : g[a]) {
    if (blocked[b] || b == p) continue;
    dist[b] = 1 + dist[a];
    build_dist(b, a);
  }
}

int tree[N];

void upd(int i, int x) {
  while (i <= max_a) {
    tree[i] = max(tree[i], x);
    i += i & (-i);
  }
}

int get(int i) {
  int sol = -INF;
  while (i) {
    sol = max(sol, tree[i]);
    i -= i & (-i);
  }
  return sol;
}

void solve(int root) {
  build_sub(root);
  total = sub[root];
  root = fcen(root);

  max_a = 0;
  dist[root] = 0;
  build_dist(root);

  max_a += 7;

  vector<vector<T>> v;
  v.push_back({{dist[root], min_dist[root]}});

  for (auto &b : g[root]) {
    if (!blocked[b]) {
      current.clear();
      place(b, root);
      v.push_back(current);
    }
  }

  int dim = (int) v.size();

  for (int iter_rec = 0; iter_rec < 2; iter_rec++) {
    for (int i = 0; i < (int) v.size(); i++) {
      for (int ix = 0; ix < (int) v[i].size(); ix++) {
        for (int iq = 0; iq < q; iq++) {
          while (1) {
            int over_a = max_a - (results[iq] + 1 - v[i][ix].a);
            int over_b = results[iq] + 1 - queries[iq] - v[i][ix].b;
            if (over_a >= 1 && get(over_a) >= over_b) {
              results[iq]++;
            } else {
              break;
            }
          }
        }
      }
      for (int ix = 0; ix < (int) v[i].size(); ix++) {
        upd(max_a - v[i][ix].a, v[i][ix].b);
      }
    }
    for (int i = 0; i <= max_a; i++) {
      tree[i] = -INF;
    }
  }
  blocked[root] = 1;
  for (auto &b : g[root]) {
    if (!blocked[b]) {
      solve(b);
    }
  }
}

signed main()
{
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  for (int i = 0; i < N; i++) {
    tree[i] = -INF;
  }

  cin >> n;
  for (int i = 2; i <= n; i++) {
    int j;
    cin >> j;
    g[i].push_back(j);
    g[j].push_back(i);
  }
  {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if ((int) g[i].size() == 1) {
        q.push(i);
        min_dist[i] = 0;
      } else {
        min_dist[i] = -1;
      }
    }
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      for (auto &b : g[a]) {
        if (min_dist[b] == -1) {
          min_dist[b] = 1 + min_dist[a];
          q.push(b);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      assert(min_dist[i] != -1);
    }

    if (0) {
      for (int i = 1; i <= n; i++) {
        cout << min_dist[i] << " ";
      }
      cout << "\n";
    }
  }
  cin >> q;
  queries.resize(q);
  results.resize(q, 0);
  for (auto &ask : queries) {
    cin >> ask;
  }
  solve(1);
  for (int i = 0; i < q; i++) {
    cout << results[i] << " ";
  }
  cout << "\n";
}