#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

/**
mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}
**/
signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

vector<int> f(vector<int> v, int tp) {
  int n = (int) v.size();
  assert(n % 2 == 0);
  if (tp == 1) {
    for (int i = 0; i < n; i += 2) {
      swap(v[i], v[i + 1]);
    }
  } else {
    for (int i = n / 2; i < n; i++) {
      swap(v[i - n / 2], v[i]);
    }
  }
  return v;
}

set<vector<int>> s;
map<vector<int>, int> dist;

void bfs(vector<int> v) {
  queue<vector<int>> q;
  q.push(v);
  dist[v] = 0;
  assert(dist.count(v));
  while (!q.empty()) {
    v = q.front();
    q.pop();
    vector<int> v1 = f(v, 1), v2 = f(v, 2);
    if (!dist.count(v1)) {
      dist[v1] = dist[v] + 1;
      q.push(v1);
    }
    if (!dist.count(v2)) {
      dist[v2] = dist[v] + 1;
      q.push(v2);
    }
  }
}

signed realMain() {
  int n;
  cin >> n;
  dist.clear();
  vector<int> v(2 * n);
  iota(v.begin(), v.end(), 1);
  bfs(v);
  for (auto &x : v) {
    cin >> x;
  }
  if (!dist.count(v)) {
    cout << "-1\n";
  } else {
    cout << dist[v] << "\n";
  }
  return 0;
}