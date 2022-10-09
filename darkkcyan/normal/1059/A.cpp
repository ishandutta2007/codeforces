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

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, l, a;
  cin >> n >> l >> a;
  int cur = 0;
  int ans = 0;
  while (n--) {
    int u, t; cin >> u >> t;
    ans += (u - cur) / a;
    cur = u + t;
  }
  ans += (l - cur) / a;
  cout << ans;

  return 0;
}