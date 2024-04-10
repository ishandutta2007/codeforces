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

llong mynum = -1;

bool ask(llong x, llong y) {
  cout << "? " << x << ' ' << y << endl;
  string ans;
  if (mynum == -1) {
    cin >> ans;
    assert(ans != "e");
  } else {
    if (x % mynum >= y % mynum) ans = 'x';
    else ans = 'y';
    cout << ans << endl;
  }
  return ans[0] == 'x';
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  while (true) {
    string s; cin >> s;
    if (s == "custom") cin >> mynum;
    if (s == "end") break;
    assert(s != "mistake");
    llong x = 1;
    while (!ask(x, 2 * x)) x *= 2;
    if (ask(0, x)) {
      cout << "! " << x << endl;
      continue;
    }
    llong l = x + 1, r = 2 * x;
    while (l < r) {
      llong mid = l + (r - l) / 2;
      if (!ask(mid, x)) r = mid;
      else l = mid + 1;
    }
    cout << "! " << l << endl;
  }


  return 0;
}