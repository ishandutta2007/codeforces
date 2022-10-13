#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  if (n == 2) {
    cout << 1 << '\n';
    return 0;
  }

  // calc n-1 choose n/2-1
  long long coef = 1;
  for (int i = 1; i < n / 2; ++i) {
    coef *= n - i;
    coef /= i;
  }
  //cerr << "choose: " << coef << endl;
  
  long long coef2 = 1;
  int hn = n / 2;
  // how many distinct configurations
  // hn! / hn or 1
  for (int i = 1; i < hn; ++i)
    coef2 *= i;
  //cerr << "coef2: " << coef2 << endl;

  cout << coef * coef2 * coef2 << endl;


  return 0;
}