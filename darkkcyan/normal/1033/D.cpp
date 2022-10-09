#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define len(x) ((int)x.size())
#define llong long long 
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define llong long long 
#define rem ((llong)998244353)

template<typename x> ostream& operator<< (ostream& cout, const vector<x>& a) {
  cout << "[";
  len(a) && cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i] ;
  return cout << "]";
}

template<typename u, typename v>
ostream& operator<< (ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

bool canbesqr(llong u) {
  llong v = (llong)round(sqrt(u));
  return v * v == u;
}

bool canbeper4(llong u) {
  if (!canbesqr(u)) return false;
  llong v = (llong)round(sqrt(sqrt(u)));
  return v * v * v * v == u;
}

bool canbecub(llong u) {
  llong v = (llong)round(cbrt(u));
  return v * v * v == u;
}

map<llong, llong >  cnt;
map<llong, llong> remain;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  rep(i, n) {
    llong u; cin >> u;
    if (u == 1) {
      continue;
    }
    llong v;
    if (canbeper4(u)) {
      v = (llong)round(sqrt(sqrt(u)));
      cnt[v] += 4;
      continue;
    }
    if (canbecub(u)) {
      v = (llong) round(cbrt(u));
      cnt[v] += 3;
      continue;
    }
    if (canbesqr(u)) {
      v = (llong)round(sqrt(u));
      cnt[v] += 2;
      continue;
    }
    remain[u] ++;
  }
  //clog << vector<pair<llong, int>>(cnt.begin(), cnt.end()) << endl;
  //clog << vector<pair<llong, int>>(remain.begin(), remain.end()) << endl;
  for (auto i: remain) {
    for (auto f: remain) {
      if (i.xx == f.xx) continue;
      llong g = __gcd(i.xx, f.xx);
      if (g == 1) continue;
      cnt[g] += 0;
    }
  }

  llong ans = 1;

  for (auto i: remain) {
    llong it = 1;
    for (auto f: cnt) {
      if (i.xx % f.xx) continue;
      it = f.xx;
      break;
    }
    if (it != 1) {
      cnt[it] += i.yy;
      cnt[i.xx / it] += i.yy;
    } else  (ans *= (llong)(i.yy + 1) * (i.yy + 1) % rem) %= rem;
  }
  for (auto i: cnt) {
    (ans *= (llong)i.yy + 1) %= rem;
  }
  cout <<ans << endl;

  return 0;
}