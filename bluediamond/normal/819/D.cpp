#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 

bool home = true;
#define int long long
using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}


typedef long long ll;
typedef long double ld;

struct math {
  ll Tgcd(ll a, ll b) {
    if (b == 0) {
      return a;
    }
    else {
      return Tgcd(b, a % b);
    }
  }
  ll d = 0;
  pair<ll, ll> gcd(ll a, ll b) {
    if (b == 0) {
      d = a;
      return { 1, 0 };
    }
    else {
      pair<ll, ll> it = gcd(b, a % b);
      return { it.second, it.first - a / b * it.second };
    }
  }
  pair<ll, ll> coef(ll a, ll b, ll c) {
    auto it = gcd(a, b);
    if (c % d) return { 0, 0 };
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

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  function<int(int, int)>rep = [&](int a, int m) {
    a %= m;
    if (a < 0) a += m;
    return a;
  };

  int big_mod, n, sum = 0;


  cin >> big_mod >> n;
  vector<int> a(n), sol(n, 0);
  for (auto& x : a) {
    cin >> x;
    x %= big_mod;
    sum += x;
    sum %= big_mod;
  }
  for (int i = 1; i < n; i++) {
    a[i] = (a[i - 1] + a[i]) % big_mod;
  }
  vector<int> all_uinds;

  {
    all_uinds.reserve(n);
    set<int> us;
    for (int i = 0; i < n; i++) {
      if (!us.count(a[i])) {
        us.insert(a[i]);
        all_uinds.push_back(i);
      }
    }
  }
  int g = gcd(big_mod, sum);

  map<int, vector<int>> m_inds;

  for (auto& i : all_uinds) {
    m_inds[a[i] % g].push_back(i);
  }

  int mod = big_mod / g;



  for (auto& IT : m_inds) {
    int rr = IT.first;
    vector<int> inds = IT.second;

    int dim = (int)inds.size();

    
    if (dim == 1) {
      sol[inds[0]] = mod;
      continue;
    }

    for (auto& i : inds) {
      a[i] -= rr;
    }

    vector<int> pos(dim);

    for (int it = 0; it < dim; it++) {
      int i = inds[it];
      pos[it] = -1;

     
      pos[it] = rep(user.coef(sum, -big_mod, a[i]).first, mod);
    }

    vector<pair<int, int>> guys(dim);
    for (int i = 0; i < dim; i++) {
      guys[i] = { pos[i], i };
    }

    sort(guys.begin(), guys.end());
    for (int i = 0; i < dim; i++) {
      sol[inds[guys[i].second]] = rep(pos[(guys[(i + 1) % dim].second)] - guys[i].first, mod);
    }
  }
  for (auto& x : sol) {
    cout << x << " ";
  }
  cout << "\n";
}