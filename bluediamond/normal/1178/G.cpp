#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
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

struct container {

  struct line {
    ll a;
    ll b;
    int id;
    bool operator < (line &ln) {
      if (a == ln.a) {
        return b < ln.b;
      } else {
        return a > ln.a;
      }
    }
    ll eval(ll t) {
      return a * t + b;
    }
  };

  bool better(line l1, line l2, line l3) {
    return (l3.b - l1.b) * (l1.a - l2.a) < (l2.b - l1.b) * (l1.a - l3.a);
  }

  vector<line> lines, hull;
  int pos, pos2;
  ll last = -1;
  void sort_lines() {
    sort(lines.begin(), lines.end());
  }
  void add(ll a, ll b, int i) { /// y = a * x + b
    lines.push_back({a, b, i});
  }
  void build() {
    hull.clear();
    pos = 0;
    last = -1;
    int i = 0;
    while (i < (int) lines.size()) {
      int j = i;
      while (j + 1 < (int) lines.size() && lines[j + 1].a == lines[j].a) j++;
      int bmin = lines[i].b;
      for (int k = i + 1; k <= j; k++) bmin = min(bmin, lines[k].b);
      line l = {lines[i].a, bmin, 1};
      while ((int) hull.size() >= 2 && better(hull[(int) hull.size() - 2], hull[(int) hull.size() - 1], l)) {
        hull.pop_back();
      }
      hull.push_back(l);
      i = j + 1;
    }
  }
  ll best(ll x) {
    while (pos + 1 < (int) hull.size() && hull[pos + 1].eval(x) <= hull[pos].eval(x)) {
      pos++;
    }
    return hull[pos].eval(x);
  }
};

const int N = (int) 2e5 + 7;
const int INF = (int) 1e18;
int n, q, p[N], a[N], b[N], fl[N], fr[N], top, gaga[N], bubu[N];
vector<int> g[N];

void build(int x) {
  fl[x] = ++top;
  a[fl[x]] = gaga[x];
  b[fl[x]] = bubu[x];
  for (auto &y : g[x]) {
    build(y);
  }
  fr[x] = top;
}

void build2(int x) {
  for (auto &y : g[x]) {
    a[fl[y]] += a[fl[x]];
    b[fl[y]] += b[fl[x]];
    build2(y);
  }
}

int rad;
int bucket[N], first[N], last[N], grow[N];
container mic[N], big[N];
ll sg[N], tot[N];

void reb(int bu) {
  for (int j = first[bu]; j <= last[bu]; j++) {
    sg[j] += tot[bu];
  }
  tot[bu] = 0;
  for (auto &it : mic[bu].lines) {
    it.b = sg[it.id] * b[it.id];
  }
  for (auto &it : big[bu].lines) {
    it.b = -sg[it.id] * b[it.id];
  }
  mic[bu].build();
  big[bu].build();
}

signed realMain() {
  cin >> n >> q;
  rad = max(1LL, (int) sqrt(n) / 2);
  for (int i = 1; i <= n; i++) {
    bucket[i] = (i - 1) / rad + 1;
    last[bucket[i]] = i;
  }
  for (int i = n; i >= 1; i--) {
    first[bucket[i]] = i;
  }
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    g[p[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> gaga[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> bubu[i];
  }
  build(1);
  build2(1);
  for (int bu = bucket[1]; bu <= bucket[n]; bu++) {
    for (int i = first[bu]; i <= last[bu]; i++) {
      mic[bu].add(b[i], a[i] * b[i], i);
      big[bu].add(-b[i], -a[i] * b[i], i);
    }
    mic[bu].sort_lines();
    big[bu].sort_lines();
    mic[bu].build();
    big[bu].build();
  }
  for (int i = 1; i <= n; i++) {
    sg[i] = a[i];
  }
  int cnt = 0;
  for (int it = 1; it <= q; it++) {
    int type;
    cin >> type;
    if (type == 1) {
      int v, x, l, r;
      cin >> v >> x;
      l = fl[v];
      r = fr[v];
      if (bucket[l] == bucket[r]) {
        for (int j = l; j <= r; j++) {
          sg[j] += x;
        }
        reb(bucket[l]);
      } else {
        for (int j = l; j <= last[bucket[l]]; j++) {
          sg[j] += x;
        }
        for (int j = first[bucket[r]]; j <= r; j++) {
          sg[j] += x;
        }
        for (int j = bucket[l] + 1; j <= bucket[r] - 1; j++) {
          tot[j] += x;
        }
        reb(bucket[l]);
        reb(bucket[r]);
      }
    } else {
      int v, l, r, mn = INF, mx = -INF;
      cin >> v;
      l = fl[v];
      r = fr[v];
      cnt++;
      int type;
      int mn2 = INF, mx2 = -INF;
      if (bucket[l] == bucket[r]) {
        type = 1;
        reb(bucket[l]);
        for (int j = l; j <= r; j++) {
          mx2 = max(mx2, sg[j] * b[j]);
        }
        for (int j = l; j <= r; j++) {
          mn2 = min(mn2, sg[j] * b[j]);
        }
      } else {
        type = 2;
        reb(bucket[l]);
        reb(bucket[r]);
        for (int j = l; j <= last[bucket[l]]; j++) {
          mx2 = max(mx2, sg[j] * b[j]);
        }
        for (int j = first[bucket[r]]; j <= r; j++) {
          mx2 = max(mx2, sg[j] * b[j]);
        }
        for (int bu = bucket[l] + 1; bu <= bucket[r] - 1; bu++) {
          mx2 = max(mx2, -big[bu].best(tot[bu]));
        }
        for (int j = l; j <= last[bucket[l]]; j++) {
          mn2 = min(mn2, sg[j] * b[j]);
        }
        for (int j = first[bucket[r]]; j <= r; j++) {
          mn2 = min(mn2, sg[j] * b[j]);
        }
        for (int bu = bucket[l] + 1; bu <= bucket[r] - 1; bu++) {
          mn2 = min(mn2, mic[bu].best(tot[bu]));
        }
      }
      cout << max(abs(mn2), abs(mx2)) << "\n";
    }
  }
  return 0;
}