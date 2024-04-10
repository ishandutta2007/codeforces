#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

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

const int N = 200000 + 7;
const int K = 5;
const int K2 = 120;
int n, k, a[N], sum[K2][K2], last[K2], y;
map<vector<int>, int> to;
vector<vector<int>> inv;

vector<int> apply(vector<int> a, vector<int> b) {
  vector<int> ret;
  for (auto &i : b) {
    ret.push_back(a[i - 1]);
  }
  return ret;
}

void build() {
  vector<int> perm(k);
  iota(perm.begin(), perm.end(), 1);
  inv.push_back(perm);
  to[perm] = y++;
  while (next_permutation(perm.begin(), perm.end())) {
    inv.push_back(perm);
    to[perm] = y++;
  }
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < y; j++) {
      vector<int> p = apply(inv[i], inv[j]);
      assert(to.count(p));
      sum[i][j] = to[p];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (auto &x : perm) {
      cin >> x;
    }
    a[i] = to[perm];
  }
}

int cnt;
bool ok[K2];
vector<int> basis;

void bfs() {
  for (int i = 0; i < y; i++) {
    ok[i] = 0;
  }
  ok[0] = 1;
  queue<int> q;
  q.push(0);
  cnt = 0;
  while (!q.empty()) {
    cnt++;
    int x = q.front();
    q.pop();
    for (auto &sc : basis) {
      int y = sum[x][sc];
      if (!ok[y]) {
        ok[y] = 1;
        q.push(y);
      }
    }
  }
}

signed realMain() {
  cin >> n >> k;
  build();
  ll ret = 0;
  for (int i = 1; i <= n; i++) {
    last[a[i]] = i;
    vector<pair<int, int>> events;
    for (int j = 0; j < K2; j++) {
      if (last[j]) {
        events.push_back({last[j], j});
      }
    }
    sort(events.rbegin(), events.rend());
    events.push_back({0, 0});
    basis.clear();
    bfs();
    for (int j = 0; j + 1 < (int) events.size(); j++) {
      int i = events[j].first, dur = events[j].first - events[j + 1].first;
      if (!ok[a[i]]) {
        basis.push_back(a[i]);
        bfs();
      }
      ret += (ll) cnt * dur;
    }
  }
  cout << ret << "\n";
  return 0;
}