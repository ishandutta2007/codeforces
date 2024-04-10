#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
///typedef long double ld;
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

const int N = (int) 1e5 + 7;
int n, q, a[N], y;
bool stop;
vector<pair<int, int>> ret;
deque<pair<int, int>> dq;
map<pair<int, int>, int> when;

void print() {
  for (auto &x : dq) {
    cout << x.first << " ";
  }
  cout << "\n";
}

void op() {
  auto a = dq.front(); dq.pop_front();
  auto b = dq.front(); dq.pop_front();
  if (when.count({a.second, b.second})) {
    stop = 1;
    return;
  }
  when[{a.second, b.second}] = ++y;
  ret.push_back({a.first, b.first});
  if (a.first < b.first) swap(a, b);
  dq.push_front(a);
  dq.push_back(b);
}

signed realMain() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dq.push_back({a[i], i});
  }
  while (!stop) {
    op();
  }
  while (q--) {
    int t;
    cin >> t;
    t--;
    if (t >= y) {
      int c = (t - y) / (n - 1);
      t -= (c + 1) * (n - 1);
    }
    cout << ret[t].first << " " << ret[t].second << "\n";
  }
  return 0;
}