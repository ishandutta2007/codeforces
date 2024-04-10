#include <bits/stdc++.h>
using namespace std;

#define maxn 101010
#define llong long long 
#define rem ((llong)1e9+7)

llong mpow(llong b, llong m) {
  llong ans = 1;
  for (; m > 0; m >>= 1) {
    if (m & 1) (ans *= b) %= rem;
    (b *= b) %= rem;
  }
  return ans;
}

llong fac[maxn * 3], rfac[maxn * 3];
void genfac() {
  fac[0] = rfac[0] = 1;
  for (int i = 1; i < maxn * 3; ++i) {
    fac[i] = (fac[i - 1] * i) % rem;
    rfac[i] = mpow(fac[i], rem - 2);
  }
}

inline llong comb(llong n, llong k) { return fac[n] * rfac[k] % rem * rfac[n - k] % rem; }
inline llong count_(llong n, llong k) { return comb(n + k - 1, k - 1); }
llong count(llong n, llong k) {
  if (n < k) return 0;
  return count_(n - k, k);
}

#define div ____div
vector<int> div[maxn];
void gendivisor() {
  for (int i = 2; i < maxn; ++i) {
    for (int f = i + i; f < maxn; f += i) div[f].push_back(i);
  }
}

llong dp[maxn];
void reset(int num) {
  for (auto i: div[num]) dp[i] = -1;
}

llong solve(int n, int k) {
  if (dp[n] != -1) return dp[n];
  llong ans = count(n, k);
  //clog << n << ' ' << k << ' ' << ans << endl;
  for (auto i: div[n]) {
    (ans -= solve(i, k)) %= rem;
    if (ans < 0) ans += rem;
  }
  return dp[n] = ans;
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  genfac();
  gendivisor();
  int q; cin >> q;
  while (q--) {
    int n, k; cin >> n >> k;
    if (k == 1) {
      cout << (n == 1) << '\n';
      continue;
    }
    reset(n);
    dp[n] = -1;
    cout << solve(n, k) << '\n';
  }

  return 0;
}