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

#define maxsqrtn 1000010
int me[maxsqrtn];
int cnt[maxsqrtn][6] = {0};

int getmex(int tl, int tr) {
  if (tl > tr) return 0;
  int i = 0;
  while (cnt[tr][i] - cnt[tl - 1][i]) ++i;
  return i;
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  me[1] = 0;
  cnt[1][0] = 1;
  for (int i = 2; i < maxsqrtn; ++i) {
    int lo = (int)ceil(sqrt(sqrt(i)));
    int hi = (int)floor(sqrt(i));
    me[i] = getmex(lo, hi);
    memcpy(cnt[i], cnt[i - 1], sizeof(cnt[i]));
    cnt[i][me[i]]++;
  }

  llong nimsum = 0;
  int n; cin >> n;
  while (n--) {
    llong a; cin >> a;
    if (a < maxsqrtn) {
      nimsum ^= me[a];
      continue;
    }
    int lo = (int)ceil(sqrt(sqrt(a)));
    int hi = (int)floor(sqrt(a));
    nimsum ^= getmex(lo, hi);
  }

  if (nimsum)
    cout << "Furlo";
  else
    cout << "Rublo";

  return 0;
}