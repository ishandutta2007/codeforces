#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int INF = (int) 1e18 + 777;

int mul(int a, int b) {
  if (a == 0 || b == 0) return 0;
  if (a <= INF / b) return a * b;
  return INF;
}

int getmn(int x, int s) {
  return s + (s == x);
}

int mx(int x, int n) {
  int sol = n + mul(x, (n / x));

  return sol - 1;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  int t;
  cin >> t;
  while (t--) {
    int s, n, k;
    cin >> s >> n >> k;
    if (k == s) {
      cout << "YES\n";
      continue;
    }
    bool ok = (getmn(k, n) <= s && s <= mx(k, n));
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}