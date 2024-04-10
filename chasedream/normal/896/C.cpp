%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const ll mod = 1e9 + 7;
const int N = 200005;

struct ele {
  int l, r;
  mutable ll v;
  ele (int l, int r = -1, ll val = 0LL): l(l), r(r), v(val) {}
  bool operator < (const ele& b) const {
    return l < b.l;
  }
};

#define IT set <ele> :: iterator
#define VEC vector <pair <ll, int> > :: iterator
set <ele> s;

inline IT split(int pos) {
  IT it = s.lower_bound(ele(pos));
  if (it != s.end() && it->l == pos) return it;
  it--;
  int L = it->l, R = it->r;
  ll v = it->v;
  s.erase(it); s.insert(ele(L, pos - 1, v));
  return s.insert(ele(pos, R, v)).first; // s.insert -> (pair <int, int>, int) 
}

inline void assign(int l, int r, ll val = 0) {
  IT it1 = split(l), it2 = split(r + 1);
  s.erase(it1, it2);
  s.insert(ele(l, r, val));
}

inline void add(int l, int r, ll val = 1) {
  IT it1 = split(l), it2 = split(r + 1);
  for (; it1 != it2; it1++)
    it1->v += val;
}

inline ll rnk(int l, int r, int k) {
  vector <pair <ll, int> > vec;
  IT it1 = split(l), it2 = split(r + 1);
  vec.clear();
  for (; it1 != it2; it1++)
    vec.push_back(pair <ll, int> (it1->v, it1->r - it1->l + 1));
  sort(vec.begin(), vec.end());
  
  for (VEC it = vec.begin(); it != vec.end(); it++) {
    k -= it->second;
    if (k <= 0) return it->first;
  }
  return -1LL;
}

inline ll qpow(ll a, ll b, ll mod) {
  ll res = 1;
  a %= mod; 
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    b >>= 1; a = a * a % mod;
  }
  return res;
}

inline ll sum(int l, int r, int ex, int mod) {
  IT it1 = split(l), it2 = split(r + 1);
  ll res = 0;
  for (; it1 != it2; it1++) {
    res = (res + (ll)(it1->r - it1->l + 1) * qpow(it1->v, (ll)(ex), (ll)(mod))) % mod;
  }
  return res;
}

ll a[N], seed, vmax;
int n, m;

inline ll rnd() {
  ll ret = seed;
  seed = (seed * 7 + 13) % mod;
  return ret;
}

int main() {
  scanf("%d%d%lld%lld", &n, &m, &seed, &vmax);
  for (int i = 1; i <= n; i++) {
    a[i] = (rnd() % vmax) + 1;
    s.insert(ele(i, i, a[i]));
  }
  s.insert(ele(n + 1, n + 1, 0));
  
  for (int i = 1; i <= m; i++) {
    int opt = int(rnd() % 4) + 1;
    int l = int(rnd() % n) + 1;
    int r = int(rnd() % n) + 1;
    if (l > r) swap(l, r);
    
    int x, y;
    if (opt == 3) x = int(rnd() % (r - l + 1)) + 1;
    else x = int(rnd() % vmax) + 1;
    if (opt == 4) y = int(rnd() % vmax) + 1;

    if (opt == 1) add(l, r, (ll)(x));
    else if (opt == 2) assign(l, r, (ll)x);
    else if (opt == 3) printf("%lld\n", rnk(l, r, x));
    else printf("%lld\n", sum(l, r, x, y));
  }
  return 0;
}