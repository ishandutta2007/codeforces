#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

/**
mt19937 rng_home(0);
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
**/
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

const int N = (int) 1e6 + 7;
int n, inv[N], p[N], suf[N];

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b;
    bool inow = 0;
    cin >> a >> b;
    if (a > b) {
      swap(a, b);
      inow ^= 1;
    }
    if (!(a <= n && b > n)) {
      cout << "-1\n"; /// nothing personal kid
      return 0;
    }
    inv[a] = inow;
    p[a] = b;
  }
  
  for (int i = n; i >= 1; i--) suf[i] = max(suf[i + 1], p[i]);
  int m1 = 2 * N, m2 = 2 * N, mnpre = 2 * N, le1 = 0, le2 = 0, cox1 = 0, cox2 = 0, cox3 = 0;
  for (int i = 1; i <= n; i++) {
    mnpre = min(mnpre, p[i]);
    if (m1 > p[i]) {
      m1 = p[i];
      le1++;
      cox1 += inv[i];
    } else {
      if (m2 > p[i]) {
        m2 = p[i];
        le2++;
        cox2 += inv[i];
      } else {
        if (home) {
          cout << "uga buga\n";
        }
        cout << "-1\n";
        return 0;
      }
    }
    if (mnpre > suf[i + 1]) { /// freedom of choice
      cox3 += min(le1 + cox2 - cox1, le2 + cox1 - cox2);
      le1 = le2 = 0;
      cox1 = cox2 = 0;
      m1 = m2 = 2 * N;
    }
  }
  cout << cox3 << "\n";
  return 0;
}