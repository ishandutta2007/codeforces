#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 100005
ll inf = 1e16;
ll mod = 1e9 + 7;
char en = '\n';
 
ll power(ll x, ll n, ll mod) {
  ll res = 1;
  x %= mod;
  while (n) {
    if (n & 1)
      res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
unordered_map<int, int> prime[N]; // prime factorisation of a number
vector<int> fact[N];              // fact[i] -> all factors of i except i
bool isPrime[N];
ll dp[N]; // dp[i] denotes number of steps to get a gcd of 1 if current gcd is i
ll m;
ll findCount(ll x,
             ll n) // number of numbers p in [1:m] such that gcd of
// (n,p)==x
{
  ll currCnt = m / x;
  vector<ll> arr;
  for (auto &it : prime[n]) {
    if (!prime[x].count(it.first)) {
      arr.push_back(it.first);
      continue;
    }
    if (it.second == prime[x][it.first]) {
      continue;
    } else {
      arr.push_back(it.first);
    }
  }
 
  ll sz = arr.size();
  ll lim = m / x;
  for (ll i = 1; i < (1 << sz); i++) {
    ll sign = 1;
    ll prod = 1;
    for (ll j = 0; j < sz; j++) {
      if (i & (1ll << j)) {
        prod *= arr[j];
        sign *= -1;
      }
    }
    currCnt += sign * (lim / prod);
  }
  return currCnt;
}
 
ll invm;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  memset(isPrime, true, sizeof(isPrime));
  for (ll i = 2; i < N; i++) {
    if (isPrime[i]) {
      for (ll j = i; j < N; j += i) {
        ll curr = j;
        ll cnt = 0;
        while (curr % i == 0) {
          curr /= i;
          cnt++;
        }
        prime[j][i] = cnt;
        isPrime[j] = false;
      }
    }
  }
  for (ll i = 1; i < N; i++) {
    for (ll j = 2 * i; j < N; j += i)
      fact[j].push_back(i);
  }
 
  cin >> m;
 
  invm = power(m, mod - 2, mod);
  dp[1] = 0;
  for (ll i = 2; i <= m; i++) {
    ll rhs = 1;
    for (ll x : fact[i]) {
      ll cnt = findCount(x, i);
      rhs += (dp[x] * cnt) % mod * invm % mod;
      if (rhs >= mod)
        rhs -= mod;
    }
    ll cnt = m / i;
    dp[i] = rhs * m % mod * power(m - cnt, mod - 2, mod) % mod;
  }
 
  ll res = 1;
  for (ll i = 1; i <= m; i++) {
 
    res += dp[i] * invm % mod;
    if (res >= mod)
      res -= mod;
  }
  cout << res << en;
  return 0;
}