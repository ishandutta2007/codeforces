#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
#define _pt(x) typename iterator_traits<x>::value_type
template<class u> vector<_pt(u)> tovec(u a, u b) { return vector<_pt(u)>(a, b); }
template<class x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  rep(i, len(a)) cout << a[i] << (i == len(a) - 1 ? "" : ", ");
  return cout << "]";
}
template<class u, class v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << a.xx << ": " << a.yy;
}/*}}}*/

#define maxn 5050
int n, m;
int closest[maxn];
int pickUpTime[maxn];

int distance(int u, int v) {
  return (v + n - u) % n;
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep(i, m) {
    int a, b; cin >> a >> b;
    --a; --b;
    if (pickUpTime[a] == 0 or distance(a, b) < distance(a, closest[a]))
      closest[a] = b;
    ++pickUpTime[a];
  }

  //rep(i, n) {
    //clog << closest[i] << ' ' << pickUpTime[i] << endl;
  //}

  rep(i, n) {
    llong ans = 0;
    rep(f, n) {
      ans = max(ans, distance(i, f) + 1LL * (pickUpTime[f] - 1) * n + distance(f, closest[f]));
    }
    cout << ans << ' ';
  }

  return 0;
}