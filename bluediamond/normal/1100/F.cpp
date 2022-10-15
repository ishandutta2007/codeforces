#include <bits/stdc++.h>

using namespace std;

bool home = 1;
///#define int ll
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

const int L = (int) 1e6 + 7;
int lg[L];

struct T {
  int num[20];
};

T operator + (T a, int x) {
  for (int bit = 19; bit >= 0; bit--) {
    if (a.num[bit] && x & (1 << bit)) {
      x ^= a.num[bit];
    }
  }
  if (x) {
    a.num[lg[x]] = x;
  }
  return a;
}

T operator + (T a, T b) {
  for (int bit = 19; bit >= 0; bit--) {
    if (b.num[bit]) {
      a = a + b.num[bit];
    }
  }
  return a;
}

int get(T a) {
  int x = 0;
  for (int bit = 19; bit >= 0; bit--) {
    if (a.num[bit] && !(x & (1 << bit))) {
      x ^= a.num[bit];
    }
  }
  return x;
}

const int N = (int) 5e5 + 7;
int n, a[N], ret[N];
T val[N];

void singular(int i) {
  for (int bit = 0; bit <= 19; bit++) {
    val[i].num[bit] = 0;
  }
  val[i].num[lg[a[i]]] = a[i];
}

vector<pair<int, int>> questions[N];

void rec(int l, int r) {
  if (l == r) {
    for (auto &it : questions[l]) {
      if (it.first == l) {
        ret[it.second] = a[l];
      }
    }
    return;
  }
  int m = (l + r) / 2;
  rec(l, m);
  rec(m + 1, r);
  singular(m);
  singular(m + 1);
  for (int j = m + 2; j <= r; j++) {
    val[j] = val[j - 1] + a[j];
  }
  for (int j = m - 1; j >= l; j--) {
    val[j] = val[j + 1] + a[j];
  }
  for (int j = l; j <= m; j++) {
    for (auto &it : questions[j]) {
      int r = it.first, id = it.second;
      if (r <= m) {
        break;
      }
      ret[id] = get(val[j] + val[r]);
    }
  }
}

signed realMain() {
  for (int i = 2; i < L; i++) {
    lg[i] = lg[i / 2] + 1;
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    questions[l].push_back({r, i});
  }
  for (int i = 1; i <= n; i++) {
    sort(questions[i].rbegin(), questions[i].rend());
  }
  rec(1, n);
  for (int i = 1; i <= q; i++) {
    cout << ret[i] << "\n";
  }
  return 0;
}