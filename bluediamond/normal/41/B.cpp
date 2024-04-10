#include <bits/stdc++.h>

using namespace std;

int n, gold;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>gold;
  vector <int> v(n);
  for (int i = 0; i < n; i ++) {
    cin>>v[i];
  }
  int ans = gold;
  for (int i = 0; i < n; i ++) {
    for (int j = i + 1; j < n; j++) {
      int euro = gold / v[i];
      int bourle = gold % v[i];
      int have = bourle + euro * v[j];
      ans = max (ans, have);
    }
  }
  cout<<ans<<"\n";
  return 0;
}
/**

**/