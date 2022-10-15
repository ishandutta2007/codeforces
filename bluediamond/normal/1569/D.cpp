#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct T {
  int x;
  int y;
  int i;
};

map<int, int> f;
set<int> s;
set<pair<int, int>> s2;

int add(int y) {
  int group = 0;
  if (s.count(y)) return 0;
  auto it = s2.lower_bound({y, -1});
  assert(it != s2.end());
  group = it->second;
  return f[group]++;
}

bool operator < (T a, T b) {
  return a.x < b.x;
}

ll gen(vector<T> v, vector<int> ys) {
  s.clear();
  s2.clear();
  for (auto &it : ys) {
    s.insert(it);
  }
  for (int i = 0; i < (int) ys.size(); i++) {
    s2.insert({ys[i], i + 1});
  }
  f.clear();
  sort(ys.begin(), ys.end());
  ll sol = 0;
  for (auto &it : v) {
    sol += add(it.y);
  }
  sort(v.begin(), v.end());
  int l = 0;
  while (l < (int) v.size()) {
    int r = l;
    while (r + 1 < (int) v.size() && v[r + 1].x == v[r].x) {
      r++;
    }
    f.clear();
    for (int j = l; j <= r; j++) {
      sol -= add(v[j].y);
    }
    l = r + 1;
  }
  return sol;
}

const int N = (int) 3e5 + 7;
const int L = (int) 1e6 + 7;
int n, m, k, xp[N], yp[N];
bool ex[L], ey[L];


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ex[0] = ex[(int) 1e6] = 1;
  ey[0] = ey[(int) 1e6] = 1;

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m >> k;
    vector<int> x(n), y(m);
    for (int i = 0; i < n; i++) {cin >> x[i]; ex[x[i]] = 1;}
    for (int i = 0; i < m; i++) {cin >> y[i]; ey[y[i]] = 1;}
    x.push_back(0);
    x.push_back((int) 1e6);
    y.push_back(0);
    y.push_back((int) 1e6);
    vector<vector<T>> kek(2);
    for (int i = 1; i <= k; i++) {
      cin >> xp[i] >> yp[i];
      assert(ex[xp[i]] || ey[yp[i]]);
      if (ex[xp[i]]) {
        kek[0].push_back({xp[i], yp[i], i});
      } else {
        kek[1].push_back({yp[i], xp[i], i});
      }
    }
    ll bad = 0;
    bad += gen(kek[0], y);
    bad += gen(kek[1], x);
    cout << bad << "\n";
    for (int i = 0; i < n; i++) ex[x[i]] = 0;
    for (int i = 0; i < m; i++) ey[y[i]] = 0;
  }
}