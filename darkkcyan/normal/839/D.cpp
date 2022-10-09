#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxm 1010101
#define rem ((llong) 1e9 + 7)

int n;
int a[maxm] = {0};
int mcnt[maxm] = {0};
llong tans[maxm];

llong pow(llong b, llong m) {
  llong ans = 1;
  for (; m > 0; m >>= 1) {
    if (m & 1) (ans *= b) %= rem;
    (b *= b) %= rem;
  }
  return ans;
}

llong fac[maxm], revfac[maxm];

llong c(llong n, llong k) {
  llong u = fac[n];
  llong v = revfac[k] * revfac[n - k] % rem;
  return u * v % rem;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  fac[0] = 1;
  rep1(i, maxm - 1) fac[i] = (fac[i - 1] * i) % rem;
  rep(i, maxm) revfac[i] = pow(fac[i], rem - 2);

  rep(i, n) {
    int x; cin >> x;
    a[x] ++;
  }
  for (int i = 2; i < maxm; ++i) {
    for (llong f = i; f < maxm; f += i)
      mcnt[i] += a[f];
  }

  llong ans = 0;
  for (int i = maxm - 1; i > 1; i--) {
    tans[i] = 0;
    for (llong f = 1; f <= mcnt[i]; ++f) {
      (tans[i] += f * c(mcnt[i], f) % rem) %= rem;
    }
    for (llong f = i * 2; f < maxm; f += i)
      (tans[i] += rem - tans[f]) %= rem;
    (ans += (tans[i] * i) % rem) %= rem;
  }
  cout << ans;

  return 0;
}