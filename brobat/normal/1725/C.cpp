#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 998244353;

int64_t modpow(int64_t b, int64_t e) {
  int64_t ans = 1;
  for (; e; b = b*b%mod, e /= 2)
    if (e&1)
      ans = ans*b%mod;
  return ans;
}

int64_t euclid(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  if (!b) return x = 1, y = 0, a;
  int64_t d = euclid(b,a%b,y,x);
  return y -= a/b*x,d;
}

int64_t invert(int64_t m) {
  return modpow(m, mod-2);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  const int N = 3e5+7, M = 3e5+7;
  vector<int64_t> factorial(N), inv_factorial(N);
  factorial[0] = inv_factorial[0] =1;
  for (int i = 1; i < N; i++) factorial[i] = (factorial[i-1]*i)%mod;
  inv_factorial[N-1] = invert(factorial[N-1]);
  for (int i = N-2; i >= 1; i--) {
    inv_factorial[i] = (inv_factorial[i+1]*(i+1))%mod;
  }

  auto choose = [&](int n, int k)->int64_t {
    if (k < 0 || k > n) return 0;
    return (factorial[n]*((inv_factorial[k]*inv_factorial[n-k])%mod))%mod;
  };

  int n,m;
  cin >> n >> m;
  vector<int64_t> d(n);
  for (auto& x : d) cin >> x;
  int64_t D = 0;
  vector<int64_t> pr(n+1);
  map<int64_t, int> prmap;
  for (int i = 0; i < n; i++){
    D += d[i];
    pr[i+1] = pr[i] + d[i];
    prmap[pr[i]] = i;
  }
  int pairs = 0;
  if (D%2 == 0) {
    for (int i =0; i < n; i++) {
      if (prmap.count(pr[i] + D/2)) {
        pairs++;
      }
    }
  }
  int64_t ans = 0;
  for (int k = 0; k <= pairs; k++) {
    if (m < k) break;
    int64_t p1 = (choose(pairs, k) * ((factorial[m]*inv_factorial[m-k])%mod))%mod;
    int64_t p2 = modpow(2*choose(m-k,2), pairs-k);
    int64_t p3 = modpow(m-k, n-2*pairs);
    ans += (((p1*p2)%mod)*p3)%mod;
    ans %= mod;
  }
  if (ans < 0) ans += mod;
  cout << ans << '\n';
}