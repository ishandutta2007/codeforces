#include <bits/stdc++.h>


using namespace std;


const int N = (int)2e5 + 7;
int n, a[N], frq[N], mn[N], mx[N];



signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    frq[i] = mn[i] = mx[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    frq[a[i]]++;
    mx[a[i]] = i;
  }
  for (int i = n; i >= 1; i--) {
    mn[a[i]] = i;
  }
  int skip = 0, l = 1, r = mx[a[1]];
  if (l == r) {
    skip++;
  }
  else {
    skip += 2;
  }
  while (1) {
    if (r == n) {
      break;
    }
    int far = 0;
    for (int j = l; j <= r; j++) {
      far = max(far, mx[a[j]]);
    }
    if (far <= r) {
      l = r + 1;
      r = mx[a[l]];
      if (l == r) {
        skip++;
      }
      else {
        skip += 2;
      }
    }
    else {
      l = mn[a[far]];
      r = far;
      skip += 1;
    }
  }
  cout << n - skip << "\n";
}