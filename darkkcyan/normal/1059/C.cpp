#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
#define ii pair<int, int>

template<typename T>
ostream& operator<<(ostream& cout, const vector<T>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<typename u, typename v>
ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

int findbigest(int n) {
  int cur = n / 2;
  for (int i = 3; i <= n; ++i) {
    if (n / i < cur) return i - 1;
  }
  return n;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  int curgcd = 1;
  while (n > 1) { 
    int u = findbigest(n);
    rep(i, n - n / u) cout << curgcd << ' ';
    curgcd *= u;
    n /= u;
  }
  cout << curgcd;


  return 0;
}