#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

int f(int n, int a, int b) {
  int cur = 1;
  while (1) {
    if (cur > n) return 0;
    if (cur % b == n % b) return 1;
    if (a == 1) break;
    cur *= a;
  }
  return 0;
}


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    cout << (f(n, a, b) ? "Yes" : "No") << "\n";
  }

  return 0;
}