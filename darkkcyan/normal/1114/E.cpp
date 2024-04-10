#include <bits/stdc++.h>
using namespace std;

#define cli clog << "\"" << __PRETTY_FUNCTION__ << "\"@" << __LINE__ << ": "
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  llong l = 0, r = 1e9 + 1;
  int ques = 59;
  while (l < r) {
    llong mid = l + (r - l) / 2;
    cout << "> " << mid << endl;
    --ques;
    int ok; cin >> ok;
    if (ok) l = mid + 1;
    else r = mid;
  }

  set<int> id;
  vector<llong> numlist;
  numlist.push_back(l);
  while (ques-- and len(numlist) < n) {
    int i;
    do {
      i = (int)(rng() % n + 1);
    } while (id.count(i));
    id.insert(i);
    cout << "? " << i << endl;
    llong num; cin >> num;
    if (num == numlist[0]) continue;
    numlist.push_back(num);
  }

  llong d = 0;
  rep(i, len(numlist)) for (int f = i + 1; f < len(numlist); ++f) {
    llong dis = abs(numlist[i] - numlist[f]);
    d = __gcd(d, dis);
  }
  
  cout << "! " << numlist[0] - d * (n - 1) << ' ' << d << endl;

  return 0;
}