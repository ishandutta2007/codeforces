#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
int n;
ll L;
ll a[N], b[N*3];
ll l[N], r[N];
int am[N*4];
ll f[N];

bool solve(ll x) {
  //cerr << "  SOLVE " << x << endl;
  memset(am, 0, sizeof am);
  memset(f, 0, sizeof f);
  l[0] = r[0] = 0;
  for (int i=1; i<=n; ++i) {
    l[i] = l[i-1];
    r[i] = r[i-1];
    while (l[i] <= n*3 && a[i] - b[l[i]] > x) {
      ++l[i];
    }
    while (r[i] <= n*3 && b[r[i]] - a[i] <= x) {
      ++r[i];
    }
    am[l[i]-i+n] ++;
    am[r[i]-i+n] --;
  }
  for (int i=1; i<=4*n; ++i) {
    am[i] += am[i-1];
    f[i%n] += am[i];
  }
  for (int i=0; i<n; ++i) {
    if (f[i] >= n) {
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> L;
  b[0] = -1e10;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    a[i] += L;
  }
  for (int i=1; i<=n; ++i) {
    cin >> b[i];
    b[i+n] = b[i]+L;
    b[i+n*2] = b[i]+2*L;
  }
  sort(a+1, a+n+1);
  sort(b+1, b+3*n+1);
  ll lo = 0, hi = (L/2);
  while (lo<hi) {
    ll mid = (lo+hi)/2;
    bool possible = solve(mid);
    if (possible) {
      hi = mid;
    } else {
      lo = mid+1;
    }
  }
  cout << lo << "\n";
  return 0;
}