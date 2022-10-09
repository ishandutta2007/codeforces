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

#define maxn 600
int n;
bool isleaf[maxn];
int a[maxn];
vector<ii> edges;

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  vector<int> leaf;
  rep1(i, n) {
    cin >> a[i];
    if ((isleaf[i] = (a[i] == 1))) leaf.push_back(i);
  }

  if (len(leaf) >= 2) {
    if (len(leaf) == n) {
      if (n == 2) {
        cout << "YES 1\n1\n1 2";
        return 0;
      } else {
        cout << "NO";
        return 0;
      }
    }
    int ans = n - len(leaf) + 1;
    int bg = -1;
    int last = -1;
    rep1(i, n) {
      if (isleaf[i]) continue;
      if (last != -1) {
        edges.push_back({last, i});
        --a[last];
        --a[i];
        //clog << i << ' ' << last << endl;
      }
      last = i;
      if (bg == -1) bg = i;
    }
    edges.push_back({bg, leaf[0]});
    edges.push_back({last, leaf[1]});
    --a[bg], --a[last];
    int f = 0;
    for (int i = 2; i < len(leaf); ++i) {
      while (f <= n and (isleaf[f] or a[f] == 0)) ++f;
      if (f > n) {
          cout << "NO";
          return 0;
        }
      edges.push_back({leaf[i], f});
      --a[f];
    }
    cout << "YES " << ans << '\n' << len(edges) << '\n';
    for (auto i: edges) cout << i.xx << ' ' << i.yy << '\n';
  } else {
    cout << "YES " << n - 1 << '\n' << n - 1 << '\n';
    rep1(i, n - 1) cout << i << ' ' << i + 1 << '\n';
  }

  return 0;
}