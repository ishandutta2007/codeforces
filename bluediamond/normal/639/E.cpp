#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

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

#define l first
#define r second

const int N = 150000 + 7;
int n;
vector<pair<int, int>> blocks;

struct T {
  int p;
  int t;
  int old;
};

bool operator < (T a, T b) {
  return (ll) a.t * b.p < (ll) b.t * a.p;
}

bool operator == (T a, T b) {
  return (ll) a.t * b.p == (ll) b.t * a.p;
}

ld cc;

T a[N];
ld mn[N], mx[N], total;

ld eval(int i, ld tm) {
  return (ld) a[i].p * (1 - (ld) cc * tm / total);
}

vector<pair<int, int>> segs;

bool paradox(ld c) {
  cc = c;
  ld bef = 0;
  for (auto &it : blocks) {
    int l = it.l, r = it.r;
    ld now = 0;
    for (int j = l; j <= r; j++) {
      now += a[j].t;
    }
    for (int j = l; j <= r; j++) {
      ld mnt, mxt;
      mnt = bef + a[j].t;
      mxt = bef + now;
      mx[a[j].old] = eval(j, mnt);
      mn[a[j].old] = eval(j, mxt);
    }
    bef += now;
  }
  int ind = 0;
  ld gig = -1;
  for (auto &it : segs) {
    ind++;
    for (int j = it.l; j <= it.r; j++) {
      if (gig > mn[j]) {
        return 1;
      }
    }
    for (int j = it.l; j <= it.r; j++) {
      gig = max(gig, mx[j]);
    }
  }
  return 0;
}

bool cmp(T a, T b) {
  return a.p < b.p;
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].p;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].t;
    total += a[i].t;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    a[i].old = i;
  }
  int lf = 1;
  while (lf <= n) {
    int r = lf;
    while (r + 1 <= n && a[r + 1].p == a[r].p) {
      r++;
    }
    segs.push_back({lf, r});
    lf = r + 1;
  }
  sort(a + 1, a + n + 1);
  lf = 1;
  while (lf <= n) {
    int r = lf;
    while (r + 1 <= n && a[r + 1] == a[r]) {
      r++;
    }
    blocks.push_back({lf, r});
    lf = r + 1;
  }
  /// 0.608696
  ld l = 0, r = 1;
  for (int taxi = 0; taxi < 100; taxi++) {
    ld m = (l + r) * 0.5;
    if (paradox(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << fixed << setprecision(6) << l << "\n";
  return 0;
}