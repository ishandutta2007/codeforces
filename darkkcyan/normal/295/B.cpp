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

#define maxn 555
int n;
llong d[maxn][maxn];
int remlist[maxn];
llong ans[maxn];
int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) rep1(f, n) cin >> d[i][f];
  rep(i, n) cin >> remlist[i];

  llong curans = 0;
  for (int i = n; i--; ) {
    int mid = remlist[i];
    for (int f = i + 1; f <= n; ++f) {
      curans += d[mid][remlist[f]] + d[remlist[f]][mid];
    }

    for (int f = i + 1; f < n; ++f)
      for (int g = i + 1; g < n; ++g) {
        int u = remlist[f], v = remlist[g];
        if (d[u][v] + d[v][mid] < d[u][mid]) {
          curans -= d[u][mid];
          d[u][mid] = d[u][v] + d[v][mid];
          curans += d[u][mid];
        }
        if (d[mid][v] + d[v][u] < d[mid][u]) {
          curans -= d[mid][u];
          d[mid][u] = d[mid][v] + d[v][u];
          curans += d[mid][u];
        }
      }

    for (int f = i + 1; f < n; ++f)
      for (int g = i + 1; g < n; ++g) {
        int u = remlist[f], v = remlist[g];
        if (d[u][mid] + d[mid][v] < d[u][v]) {
          curans -= d[u][v];
          d[u][v] = d[u][mid] + d[mid][v];
          curans += d[u][v];
        }
      }

    ans[i] = curans;
  }

  rep(i, n) cout << ans[i] << ' ';


  return 0;
}