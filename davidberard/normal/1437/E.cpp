#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 500500;
int a[N];
int b[N];
int f[N];
int g[N];

int lis(int n) {
  if (n == 0) return 0;
  //cerr << "  LIS ";
  for (int i=1; i<=n; ++i) {
    //cerr << f[i] << " ";
  }
  //cerr << endl;
  memset(g, 0, sizeof(int)*(n+2));
  g[0] = -1.5e9;
  g[1] = f[1];
  int m = 1;
  for (int i=2; i<=n; ++i) {
    int lo=0, hi=m;
    while (lo<hi) {
      int mid = (lo+hi+1)/2;
      if (g[mid] > f[i]) {
        hi = mid-1;
      } else {
        lo = mid;
      }
    }
    g[lo+1] = f[i];
    if (lo == m) {
      ++m;
    }
  }
  return m;
}

int n, k;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for (int i=1; i<=k; ++i) {
    cin >> b[i];
  }
  for (int i=1; i<k; ++i) {
    if (a[b[i+1]]-a[b[i]] < b[i+1]-b[i]) {
      cout << "-1\n";
      return 0;
    }
  }
  if (!k) {
    for (int i=1; i<=n; ++i) {
      f[i] = a[i]-i;
    }
    cout << n-lis(n) << endl;
    return 0;
  }
  int tot = 0;
  {
    int m = 0;
    for (int i=1; i<b[1]; ++i) {
      if (a[b[1]]-a[i] >= b[1]-i) {
        f[++m] = a[i]-i;
      }
    }
    tot += lis(m);
    //cerr << " front: " << lis(m) << endl;
  }
  {
    int m = 0;
    for (int i=b[k]+1; i<=n; ++i) {
      if (a[i]-a[b[k]] >= i-b[k]) {
        f[++m] = a[i]-i;
      }
    }
    tot += lis(m);
    //cerr << " back: " << lis(m) << endl;
  }
  for (int q=1; q<k; ++q) {
    int x = b[q], y = b[q+1];
    int m = 0;
    for (int i=x+1; i<y; ++i) {
      if (a[i]-a[x] >= i-x && a[y]-a[i] >= y-i) {
        f[++m] = a[i]-i;
      }
    }
    //cerr << " " << q << "to" << q+1 << ": " << lis(m) << endl;
    tot += lis(m);
  }
  cout << n-tot-k << endl;
  return 0;
}