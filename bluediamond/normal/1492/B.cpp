#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
#define int ll

const int N = (int) 1e5 + 7;
int n, a[N], mx;
bool act[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  while (t--) {
    cin >> n;
    mx = n;
    for (int i = 1; i <= n; i++) {cin >> a[i]; act[i] = 1;}
    while (n) {
      while (!act[mx]) mx--;
      int l = n, r = n;
      while (a[l] != mx) l--;
      for (int j = l; j <= r; j++) {act[a[j]] = 0; cout << a[j] << " ";}
      n = l - 1;
    }
    cout << "\n";
  }
}