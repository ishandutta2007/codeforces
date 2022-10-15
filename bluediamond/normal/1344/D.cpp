///   ///https://www.youtube.com/watch?v=hQh9gsPTSbM Hola nios
#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

mt19937 rng_home(2);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}

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
const int INF = (int) 4e18 + 123;
int n, k, a[N], b[N];

int grow(int a, int x) {
  return a - 3 * x * x + 3 * x - 1;
}

int cnt(int peste) { /// nu animalul
  for (int i = 1; i <= n; i++) {
    int l = 1, r = a[i];
    b[i] = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (grow(a[i], mid) >= peste) {
        b[i] = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += b[i];
  }
  return sum;
}

signed realMain() {
  cin >> n >> k;
  int zu = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];zu+=a[i];
  }
  int l = -INF, r = +INF, last = -INF;
  if (cnt(-INF) != zu) {
    cout << cnt(-INF) << "\n";
    cout << zu << "\n";
    return 0;
  }
  while (l <= r) {
    int m = (l + r) / 2;
    if (cnt(m) <= k) {
      last = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cnt(last);
  for (int i = 1; i <= n; i++) {
    k -= b[i];
  }

  for (int i = 1; i <= n; i++) {
    while (k > 0 && b[i] + 1 <= a[i] && grow(a[i], b[i] + 1) == last - 1) {
      b[i]++;
      k--;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << b[i] << " ";
  }
  cout << "\n";
  if (k != 0) {
    cout << "bro : " << k << "\n";
    return 0;
  }
  return 0;
  cout << " = " << k << "\n";
  return 0;
  for (int j = -4; j <= +4; j++) {
    cout << cnt(j) << " ";
  }
  cout << "\n";
  return 0;
}