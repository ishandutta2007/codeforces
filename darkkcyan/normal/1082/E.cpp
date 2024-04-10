#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
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
}/*}}}*/

#define maxn 501010
int n, c;
int a[maxn];
int sc[maxn] = {0};
int last[maxn] = {0}, mi[maxn] = {0};
int diff[maxn] = {0};

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> c;
  int ans = 0;
  rep1(i, n) {
    cin >> a[i];
    sc[i] = sc[i - 1] + (a[i] == c);
  }
  //clog << tovec(sc + 1, sc + n + 1) << endl;

  ans = sc[n];

  rep1(i, n) {
    if (a[i] == c) continue;
    if (last[a[i]] == 0) last[a[i]] = i;
    diff[i] = diff[last[a[i]]] + 1 - (sc[i] - sc[last[a[i]]]);
    //clog << i << ' ' << a[i] << ' ' << diff[i] << endl;
    ans = max(ans, sc[n] + diff[i] - mi[a[i]]);
    mi[a[i]] = min(mi[a[i]], diff[i] - 1);
    last[a[i]] = i;
  }
  cout << ans;

  return 0;
}