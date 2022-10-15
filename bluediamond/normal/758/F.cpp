#include <bits/stdc++.h>

using namespace std;

///#define int long long
typedef long double ld;
typedef long long ll;
const int inf = (int) 1e7 + 777;
int n, l, r;
ll sol;

int mul(int a, int b) {
  if (a == 0 || b == 0) return 0;
  int c = a * b;
  if (c / a == b && c % a == 0 && c <= inf) return c;
  return inf;
}

int pw(int a, int b) {
  int sol = 1;
  for (int j = 1; j <= b && sol != inf; j++) {
    sol = mul(sol, a);
  }
  return sol;
}

int getrad() {
  int lo = 1, hi = r, sol = 0;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int val = pw(mid, n);
    if (val <= r) {
      sol = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return sol;
}

const int E = (int) 1e7 + 7;
int ptr[E];

signed main() {
  //freopen ("input", "r", stdin);
  cin >> n >> l >> r;
  if (n == 1) {cout << r - l + 1 << "\n"; return 0;}
  if (n == 2) {cout << (ll) (r - l + 1) * (r - l) << "\n"; return 0;}

  n--;
  int rad = getrad();

  for (int i = 1; i <= rad; i++) {
    ptr[i] = pw(i, n);
  }

  for (int x = 1; x <= rad; x++) {
    for (int y = x + 1; y <= rad; y++) {
      if (__gcd(x, y) == 1) {
        int val1 = ptr[y], val2 = ptr[x];
        int up = r / val1;
        int down = (l + val2 - 1) / val2;
        if (down <= up) {
          sol += up - down + 1;
        }
      }
    }
  }
  sol *= 2;
  cout << sol << "\n";
  return 0;
}