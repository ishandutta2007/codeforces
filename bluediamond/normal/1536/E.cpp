#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = 2000 + 7;
int n, m, a[N][N];




signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

///  freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      for (int j = 1; j <= m; j++) {
        char ch = s[j - 1];
        if (ch == '0') {
          a[i][j] = 0;
        } else {
          a[i][j] = -1;
        }
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cnt += (a[i][j] == -1);
      }
    }
    int sol = pw(2, cnt);
    if (cnt == n * m) sol = add(sol, -1);
    cout << sol << "\n";
  }

  return 0;
}