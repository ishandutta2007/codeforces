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

int n, m;
vector<string> a;

pair<int, vector<string>> genWithRow(char u1, char u2, char v1, char v2) {
  vector<string> ans(n, string(m + 1, '\n'));
  int cost = 0;
  rep(i, n) {
    char x = i & 1 ? u1: v1;
    char y = i & 1 ? u2: v2;
    int c1 = 0, c2 = 0;
    rep(f, m) {
      char t1 = f & 1 ? x : y;
      char t2 = x + y - t1;
      c1 += t1 != a[i][f];
      c2 += t2 != a[i][f];
    }
    bool s = c1 > c2;
    rep(f, m) {
      ans[i][f] = s ? x : y;
      s = !s;
    }
    cost += min(c1, c2);
  }
  //clog << cost << ' ' << ans << endl;
  return {cost, ans};
}

pair<int, vector<string>> genWithCol(char u1, char u2, char v1, char v2) {
  vector<string> ans(n, string(m + 1, '\n'));
  int cost = 0;
  rep(f, m) {
    char x = f & 1 ? u1: v1;
    char y = f & 1 ? u2: v2;
    int c1 = 0, c2 = 0;
    rep(i, n) {
      char t1 = i & 1 ? x : y;
      char t2 = x + y - t1;
      c1 += t1 != a[i][f];
      c2 += t2 != a[i][f];
    }
    bool s = c1 > c2;
    rep(i, n) {
      ans[i][f] = s ? x : y;
      s = !s;
    }
    cost += min(c1, c2);
  }
  return {cost, ans};
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  a.resize(n);
  rep(i, n) cin >> a[i];
  string s = "ACGT";
  pair<int, vector<string>> ans;
  ans.xx = INT_MAX;
  do {
    ans = min(ans, genWithRow(s[0], s[1], s[2], s[3]));
    ans = min(ans, genWithCol(s[0], s[1], s[2], s[3]));
  } while (next_permutation(s.begin(), s.end()));
  for (auto i: ans.yy) cout << i;
  //clog << ans.xx << endl;

  return 0;
}