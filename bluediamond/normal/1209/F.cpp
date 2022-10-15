#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}


const int N = (int) 5e5 + 7;
vector<pair<int, int>> g[N];
int n, m, n2, best[N], ct[N], yoj[N];

void add(int x, int y, int val) {
  ///cout << " : " << x << " " << y << " and " << val << "\n";
  g[x].push_back({y, val});
 /// g[y].push_back({x, val});
}

vector<int> digits(int x) {
  vector<int> ret;
  while (x) {
    ret.push_back(x % 10);
    x /= 10;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

vector<int> kek;
pair<int, int> vin[N];
int num[N];

signed realMain() {
  cin >> n >> m;
  n2 = n;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    auto dig = digits(i);
    int sz = (int) dig.size();
    int last = x;
    for (int i = 0; i < sz - 1; i++) {
      add(last, ++n2, dig[i]);
      last = n2;
      num[i] = n2;
    }
    add(last, y, dig[sz - 1]);
    swap(x, y);
    last = x;
    for (int i = 0; i < sz - 1; i++) {
      add(last, num[i], dig[i]);
      last = num[i];
    }
    add(last, y, dig[sz - 1]);
  }
  for (int i = 2; i <= n2; i++) {
    best[i] = -1;
    vin[i] = {(int) 1e9, (int) 1e9};
  }
  kek.push_back(1);
  while (!kek.empty()) {
    vector<int> potential;
    while (!kek.empty()) {
      int x = kek.back();
      kek.pop_back();
      for (auto &it : g[x]) {
        int y = it.first, digit = it.second;
        if (best[y] == -1) {
          if (make_pair(ct[x], digit) < vin[y]) {
            vin[y] = {ct[x], digit};
            yoj[y] = best[x];
          }
          potential.push_back(y);
        }
      }
    }
    kek.clear();
    map<pair<int, int>, int> tr;
    for (auto &x : potential) {
      tr[vin[x]] = 0;
    }
    int ind = 0;
    for (auto &it : tr) {
      it.second = ++ind;
    }
    for (auto &x : potential) {
      if (best[x] == -1) {
        best[x] = add(mul(10, yoj[x]), vin[x].second);
        ct[x] = tr[vin[x]];
        kek.push_back(x);
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    cout << best[i] << "\n";
  }
  return 0;
}