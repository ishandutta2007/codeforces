#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct E {
  int x, y, c;
};

bool operator < (E a, E b) {
  return a.c < b.c;
}

const int N = (int) 2e5 + 7;
const int K = 800 + 7;
const ll INF = (ll) 1e18;
int n, m, k, id[N];
ll best[K][K];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  /**
  let's just assume that k <= m, the case for k > m can be solved using brute-force
  So, bear in mind that k <= m
  It's obvious that our answer <= the k-th smallest edge
  From now, we build another graph which uses only the k-th smallest edges and it's endpoints
  Let's assume that there is a solution which contains an edge outside of our new graph.
  Let the edges be e(1), ..., e(t).
  If t == 1 => e(1) is not in our new graph => the k-th smallest edge <= e(1)
  If t > 1 => let i be an edge so that the k-th smallest edge <= e(k) => the answer for the path e(1), ..., e(t) >= the k-th smallest edge + t - 1 > k-th smallest edge
  => results that any solution which contains at least one edge from outside of our new graph is at least as bad as the solution from our new graph
  => the solution to our new graph = the solution to our initial problem
  **/

  cin >> n >> m >> k;
  vector<E> e(m);
  for (auto &it : e) cin >> it.x >> it.y >> it.c;
  sort(e.begin(), e.end());
  for (int i = 0; i < min(m, k); i++) id[e[i].x] = id[e[i].y] = 1;
  int y = 0;
  for (int i = 1; i <= n; i++) if (id[i]) id[i] = ++y;
  for (int i = 1; i <= y; i++) for (int j = 1; j <= y; j++) if (i != j) best[i][j] = INF;
  for (int i = 0; i < min(m, k); i++) best[id[e[i].x]][id[e[i].y]] = best[id[e[i].y]][id[e[i].x]] = e[i].c;
  for (int k = 1; k <= y; k++) for (int i = 1; i <= y; i++) for (int j = 1; j <= y; j++) best[i][j] = min(best[i][j], best[i][k] + best[k][j]);
  vector<ll> values;
  for (int i = 1; i <= y; i++) for (int j = i + 1; j <= y; j++) values.push_back(best[i][j]);
  sort(values.begin(), values.end());
  cout << values[k - 1] << "\n";
}