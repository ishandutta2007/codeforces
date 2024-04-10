#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  

  string s; cin >> s;
  int n = s.size();
  cout << 4 << endl;
  // absc -> babsc 
  cout << "L " << 2 << endl;
  // babsc -> bababsc
  cout << "L " << 3 << endl;
  // bababsc -> bababscsbaba
  cout << "R " << 2 << endl;
  cout << "R " << 2 * n + 3 << endl;

  
  return 0;
}