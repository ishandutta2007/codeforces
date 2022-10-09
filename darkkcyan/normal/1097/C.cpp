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

int cnto(string& s) {
  int ans = 0;
  for (auto i: s) {
    if (i == '(') ++ans;
    else if (ans == 0) return -1;
    else --ans;
  }
  return ans;
}

void dorev(string& s) {
  reverse(s.begin(), s.end());
  for (auto& i: s) if (i == '(') i = ')'; else i = '(';
}

#define maxn 501010
int n;
int co[maxn] = {0};
int cc[maxn] = {0};

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  while (n--) {
    string s; cin >> s;
    int u = cnto(s);
    dorev(s);
    int v = cnto(s);
    if (u != -1) ++co[u];
    if (v != -1) ++cc[v];
  }

  llong ans = (llong) co[0] / 2;
  rep1(i, maxn - 1) ans += min(co[i], cc[i]);
  cout << ans;


  return 0;
}