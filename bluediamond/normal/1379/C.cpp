#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (int) 1e5 + 7;
int cnt;
int n;

struct T {
  int a;
  int b;
};

T v[N];
int as[N];
int pre[N];

void solve() {
  cin >> cnt >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].a >> v[i].b;
    as[i] = v[i].a;
  }
  sort(as + 1, as + n + 1);
  reverse(as + 1, as + n + 1);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + as[i];
  }
  int sol = 0;
  for (int i = 1; i <= n; i++) {
    int a = v[i].a;
    int b = v[i].b;
    int j = 0, l = 1, r = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (as[mid] >= b) {
        j = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    /// [1...j] they are better loool
    if (a < b) {
      /// this is NOT from the first j
      int take = min(j, cnt - 1);
      sol = max(sol, pre[take] + a + b * (cnt - take - 1));
    } else {
      /// this is from the first j so actually there are only j - 1
      if (cnt >= j) {
        sol = max(sol, pre[j] + b * (cnt - j));
        continue;
      } else {
        sol = max(sol, pre[cnt]);
      }
      continue;
    }
  }
  cout << sol << "\n";
}

/**

f(type, x) = 0 if x 0
             a + (x - 1) * b if x >= 1

we pick flowers {i1, i2, ..., ik}
b(i1) <= b(i2) <= ... <= b(ik)

than final = a(i1) + ... + a(ik) + b(ik) * (n - k)

we could have made : a(ik) + b(ik) * (n - 1)
but a(i1) > b(ik)
    a(i2) > b(ik)
  ...
    a(ik-1) > b(ik)

  **/

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}