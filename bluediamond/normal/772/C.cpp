#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC optimize("O1")
///#pragma GCC optimize("O2")

///#pragma GCC optimize("Os")
///#pragma GCC optimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC optimize("O3")
///#pragma GCC optimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

struct math {
  ll Tgcd(ll a, ll b) {
    if (b == 0) {
      return a;
    } else {
      return Tgcd(b, a % b);
    }
  }
  ll d = 0;
  pair<ll, ll> gcd(ll a, ll b) {
    if (b == 0) {
      d = a;
      return {1, 0};
    } else {
      pair<ll, ll> it = gcd(b, a % b);
      return {it.second, it.first - a / b * it.second};
    }
  }
  pair<ll, ll> coef(ll a, ll b, ll c) {
    auto it = gcd(a, b);
    if (c % d) return {0, 0};
    it.first *= (c / d);
    it.second *= (c / d);
    return it;
  }
  ll crt(ll m1, ll m2, ll r1, ll r2) {
    pair<ll, ll> it = coef(m1, -m2, r2 - r1);
    ll t = m1 * it.first + r1, mod = m1 * m2 / abs(d);
    t %= mod;
    if (t < 0) {
      t += mod;
    }
    if (t % m1 != r1 || t % m2 != r2) {
      return -1;
    }
    return t;
  }
} user;

const int N = 200000 + 7;
int nrestr, mod, phi;
int can[N];
int nxt[N];
int hulk[N];
int best[N];
vector<int> cine[N];



signed realMain() {
  cin >> nrestr >> mod;
  for (int j = 0; j < mod; j++) {
    can[j] = 1;
  }
  for (int r = 1; r <= nrestr; r++) {
    int j;
    cin >> j;
    can[j] = 0;
  }
  for (int i = 1; i < mod; i++) {
    if (can[i]) {
      int g = __gcd(i, mod);
      cine[g].push_back(i);
      hulk[g]++;
    }
  }
  for (int i = mod - 1; i >= 1; i--) {
    best[i] = 0;
    for (int j = 2 * i; j < mod; j += i) {
      if (best[j] > best[i]) {
        best[i] = best[j];
        nxt[i] = j;
      }
    }
    best[i] += hulk[i];
  }
  int i = 1;
  while (best[i] != best[1] || hulk[i] == 0) {
    i++;
  }
  vector<int> prod = {1}, ret;
  while (best[i]) {
    for (auto &j : cine[i]) {
      prod.push_back(j);
    }
    i = nxt[i];
  }
  for (int itr = 0; itr + 1 < (int) prod.size(); itr++) {
    int x = prod[itr], y = prod[itr + 1];
    auto it = user.coef(x, -mod, y);
    it.first %= mod;
    if (it.first < 0) {
      it.first += mod;
    }
    int num = (ll) x * it.first % mod;
    if (num < 0) num += mod;
    assert(num == y);
    ret.push_back(it.first);
  }
  if (can[0]) {
    ret.push_back(0);
  }
  cout << (int) ret.size() << "\n";
  for (auto &x : ret) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}