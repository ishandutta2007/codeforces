#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

template<class x> vector<typename x::value_type> tovec(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> tovec(u a, u b) { return vector<ptrtype(u)>(a, b); }

template<typename x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<typename u, typename v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

#define maxm 1111
llong n, m;
llong cnt[maxm] = {0};
int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep1(i, min(m - 1, n)) {
    llong r = (i * i) % m;
    cnt[r] += (n - i) / m + 1;
    //clog << i<< ' ' << r << ' ' << (n - r) / m + 1 << endl;
  }
  cnt[0] += n / m;

  //clog << tovec(cnt, cnt + m) << endl;

  llong ans = 0;
  rep(i, m) {
    ans += cnt[i] * cnt[(m - i) % m];
  }
  cout << ans;

  return 0;
}