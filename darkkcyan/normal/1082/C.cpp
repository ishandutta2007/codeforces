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

#define maxn 101010
int n, m;
vector<int> sub[maxn];

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep(i, n) {
    int r, s; cin >> s >> r;
    sub[s].push_back(r);
  }
  rep1(i, m) {
    sort(sub[i].begin(), sub[i].end(), greater<int>());
    rep1(f, len(sub[i]) - 1)
      sub[i][f] += sub[i][f - 1];
  }

  sort(sub + 1, sub + m + 1, [](const vector<int>& x, const vector<int>& y){
      return len(x) > len(y);
  });
  //rep1(i, m) clog << sub[i] << endl;

  llong ans = 0;
  rep(i, len(sub[1])) {
    llong sum = 0;
    rep1(f, m) {
      if (len(sub[f]) <= i) break;
      if (sub[f][i] >= 0) sum += sub[f][i];
    }
    //clog << i << ' ' << sum << endl;
    ans = max(ans, sum);
  }
  cout << ans;
  


  return 0;
}