#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

template<typename x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<typename u, typename v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}/*}}}*/
#define maxn 1010
int n;
int l[maxn];
int r[maxn];
int ans[maxn];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) cin >> l[i];
  rep1(i, n) cin >> r[i];
  memset(ans, -1, sizeof(ans));
  int cur = 0;
  int cnt = n;
  for (; cnt; ++cur) {
    vector<int> ids;
    rep1(i, n) {
      if (ans[i] != -1) continue;
      if (l[i] == 0 and r[i] == 0) ids.push_back(i);
    }
    if (len(ids) == 0) {
      cout << "NO";
      return 0;
    }
    for (auto i: ids) {
      ans[i] = cur;
      --cnt;
    }
    int f = 0;
    rep1(i, n) {
      if (ans[i] != -1) continue;
      while (f < len(ids) and ids[f] <= i) ++f;
      r[i] -= len(ids) - f;
      l[i] -= f;
      if (r[i] < 0 || l[i] < 0) {
        cout << "NO";
        return 0;
      }
    }
    clog << cur << endl;
    clog << ids << endl;
    clog << vector<int>(l + 1, l + n + 1) << endl;
    clog << vector<int>(r + 1, r + n + 1) << endl;
    clog << endl;
  }
  cout << "YES\n";

  rep1(i, n) cout << cur - ans[i] << ' ';

  return 0 ;
}