#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n, p, a[N];

bool check(int x) {
  int i = 1;
  for (int it = 1; it <= n; it++) {
    while (i <= n && a[i] <= x + it - 1) {
      i++;
    }
    if ((i - it) % p == 0) {
      return 0;
    }
  }
  return 1;
}

vector<int> sol;

void print() {
  cout << (int) sol.size() << "\n";
  for (auto &i : sol) {
    cout << i << " ";
  }
  cout << "\n";
  exit(0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int f = a[1] - 1 + 1;
  for (int i = 2; i <= n; i++) {
    f = max(f, a[i] - i + 1);
  }
  /// at least one is ok => sorted order is ok
  /// a[i] <= x + i - 1, i = 1..n =>
  /// a[i] - i + 1 <= x for all i = 1..n =>
  /// max(a[i] - i + 1) <= x

  /// not all are ok => the inverse sorted is not ok
  /// a[n] > x or
  /// a[n - 1] > x + 1 or
  /// a[n - 2] > x + 2 or
  /// ...
  /// a[1] > x + n - 1
  /// =>
  /// a[n] > x or
  /// a[n - 1] - 1 > x or
  /// a[n - 2] - 2 > x or
  /// ...
  /// a[1] - (n - 1) > x

  /// e a[i] - (n - i) > x
  /// max(a[i] - (n - i)) >= x + 1
  /// x + 1 <= max(a[i] - (n - i))
  /// x <= max(a[i] - (n - i) - 1)

  /// max(a[i] - i + 1) <= x && x <= max(a[i] - (n - i) - 1)
  /// max(a[i] - i + 1) <= x && x <= max(a[i] + i - n - 1)
  int l = a[1] - (n - 1) - 1;
  for (int i = 2; i <= n; i++) {
    l = max(l, a[i] - (n - i) - 1);
  }
  if (!check(f)) {
    print();
  }
  int lo = f, hi = l, ans = f;
  while (lo <= hi) {
    int mi = (lo + hi) / 2;
    if (check(mi) == 1) {
      ans = mi;
      lo = mi + 1;
    } else {
      hi = mi - 1;
    }
  }
  for (int i = f; i <= ans; i++) {
    sol.push_back(i);
  }
  print();
  return 0;
}