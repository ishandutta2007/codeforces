
#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define llong long long 

template<typename x> ostream& operator<< (ostream& cout, const vector<x>& a) {
  cout << "[";
  len(a) && cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i] ;
  return cout;
}

template<typename u, typename v>
ostream& operator<< (ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) {
    llong a, b; cin >> a >> b;
    if (a - b > 1) {
      cout << "NO\n";
      continue;
    }
    llong num = a + b;
    bool ok = num & 1;
    for (llong i = 3; i * i <= num and ok; i += 2) {
      ok = !!(num % i);
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}