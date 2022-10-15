#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long
const int N = (int) 5e5 + 7;
int n, b[N], a[N], st[N], dr[N], sol[N];

struct T {
  int l, r, x;
};

bool operator < (T a, T b) {
  return a.r < b.r;
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
  ///  cout << "tc = " << tc << "\n";

    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      a[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
      if (b[i] == 0) {
        dr[i] = n;
      } else {
        dr[i] = i / b[i];
      }
      st[i] = (i + 1 + b[i] + 1 - 1) / (b[i] + 1);
      assert(st[i] <= dr[i]);
      ///cout << st[i] << "..." << dr[i] << "\n";
    }
    ///cout << "--------------\n";
    set<int> lib;
    for (int i = 1; i <= n; i++) {
      lib.insert(i);
      sol[i] = -1;
    }
    vector<T> v;
    for (int i = 1; i <= n; i++) {
      v.push_back({st[i], dr[i], i});
    }
    sort(v.begin(), v.end());
    for (auto &ite : v) {
      int l = ite.l, r = ite.r, i = ite.x;
      auto it = lib.lower_bound(l);
      assert(it != lib.end());
      assert(*it <= r);
      sol[i] = *it;
      lib.erase(it);
    }
    assert(lib.empty());
    for (int i = 1; i <= n; i++) {
      cout << sol[i] << " ";
    }
    cout << "\n";
  }
}
/**

2 * x <= 7

round_down(i / a[i]) = b[i]

b[i] <= i / a[i] < b[i] + 1

b[i] * a[i] <= i  ====> if (b[i] > 0) a[i] <= i / b[i]


i < a[i] * (b[i] + 1)
i <= a[i] * (b[i] + 1) - 1

i + 1 <= a[i] * (b[i] + 1)
(i + 1 + b[i] + 1 - 1) / (b[i] + 1) <= a[i]


**/