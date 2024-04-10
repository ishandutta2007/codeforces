#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < (n); )
#define rep1(i,n) for (int i = 0; i ++ < (n); )
#define len(x) ((int)x.size())
#define lamb(args, ret) [&]args {return ret;}

template<class x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<class u, class v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

#define maxn 101010
int n, q, l;
llong a[maxn];

int main(void ){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> q >> l;
  rep1(i, n) cin >> a[i];
  a[0] = a[n + 1] = 0;
  int ans = 0;
  rep1(i, n) {
    if (a[i] > l) ans += a[i - 1] <= l;
  }

  while (q--) {
    int t; cin >> t;
    if (t == 0) cout << ans << '\n';
    else {
      int p; llong d; cin >> p >> d;
      a[p] += d;
      if ((a[p] > l) == (a[p] - d > l)) continue;
      if (a[p - 1] <= l and a[p + 1] <= l) ++ans;
      else if (a[p + 1] > l and a[p - 1] > l) --ans;
    }
  }

  return 0;
}