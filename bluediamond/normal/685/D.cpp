#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC optimize("O1")
///#pragma GCC optimize("O2")

///#pragma GCC optimize("O3")
///#pragma GCC optimize("Os")
///#pragma GCC optimize("Ofast")
///#pragma GCC target("avx,avx2,fma")

///#pragma GCC target("avx2")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
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

const int N = 100000 + 7;
int n, k;
ll sol[N];
vector<int> co;

struct pt {
  int x, y;
} a[N];

bool operator < (pt a, pt b) {
  return a.y < b.y;
}

struct upd {
  int rw;
  int l, r;
  int sgn;
};

bool operator < (upd a, upd b) {
  return a.rw < b.rw;
}

int fnd(int x) {
  int l = 0, r = (int) co.size() - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (co[m] == x) return m;
    if (co[m] < x) l = m + 1;
    else r = m - 1;
  }
  assert(0);
}

signed realMain() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    int go = a[i].y - k + 1;
    if (!co.empty() && go <= co.back()) go = co.back() + 1;
    for (int j = go; j <= a[i].y; j++) co.push_back(j);
  }
  vector<upd> evs;
  for (int i = 1; i <= n; i++) {
    int lft = a[i].y - k + 1, rgh = a[i].y;
    int l = fnd(lft), r = fnd(rgh);
    evs.push_back({a[i].x - k + 1, l, r, +1});
    evs.push_back({a[i].x + 1, l, r, -1});
  }
  vector<int> cnt((int) co.size()), utime;
  swap(utime, co);
  sort(evs.begin(), evs.end());
  int ret = 0;
  for (auto &it : evs) {
    int rw = it.rw;
    int l = it.l;
    int r = it.r;
    int sgn = it.sgn;
    for (int j = l; j <= r; j++) {
      sol[cnt[j]] += (rw - utime[j]);
      cnt[j] += sgn;
      utime[j] = rw;
    }
  }
  for (int j = 1; j <= n; j++) {
    cout << sol[j] << " ";
  }
  cout << "\n";
  return 0;
}