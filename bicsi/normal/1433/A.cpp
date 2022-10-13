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
    int x; cin >> x;
    int total = 0;
    for (int dig = 1; dig <= 9; ++dig) {
      int num = dig;
      for (int cnt = 1; cnt <= 4; ++cnt) {
        total += cnt;
        if (num == x) {
          cout << total << '\n';
          goto done;
        }
        num = num * 10 + dig;
      }
    }
done:;
  }
  

  return 0;
}