#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int a, b, n; cin >> a >> b >> n;
    int ops = 0;
    while (a + b <= n) {
      if (a > b) swap(a, b);
      a += b;
      ops += 1;
    }
    cout << ops + 1 << '\n';
  }  

  return 0;
}