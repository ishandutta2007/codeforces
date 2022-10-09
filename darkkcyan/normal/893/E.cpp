#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
#define rem ((llong)1e9 + 7)

#define maxn 1010101
int p[maxn] = {0};
void sieve() {
  for (int x = 2; x < maxn; ++x) {
    if (p[x] != 0) continue;
    for (llong f = x; f < maxn; f += x)
      p[f] = x;
  }
}

llong x, y;
vector<int> fac(int x) {
  vector<int> ans;
  while (x > 1) {
    int t = p[x];
    ans.push_back(0);
    while (x % t == 0) {
      ++ans.back();
      x /= t;
    }
  }
  return ans;
}

llong fa[maxn], rfa[maxn];
llong mpow(llong b, llong m) {
  llong ans = 1;
  for (; m > 0; m >>= 1, (b *= b) %= rem)
    if (m & 1) (ans *= b) %= rem;
  return ans;
}

void processcomb() {
  fa[0] = rfa[0] = 1;
  rep1(i, maxn - 1) rfa[i] = mpow(fa[i] = (fa[i - 1] * i) % rem, rem - 2);
}

llong comb(int n, int k) {
  //clog << n << ' ' << fa[n] << ' ' << k << ' ' << rfa[k] << ' ' << rfa[n - k] << endl;
  return fa[n] * rfa[k] % rem * rfa[n - k] % rem;
}

llong process() {
  vector<int> t = fac(x);
  llong m = 1;
  for (auto u: t) {
    //clog << x << ' ' << y << ' ' << u << ' ' << comb(y + u - 1, u) << endl;
    (m *= comb(y + u - 1, u)) %= rem;
  }
  //clog << m << endl;
  llong ans = m * mpow(2, y - 1) % rem;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  processcomb();
  sieve();
  int q; cin >> q;
  while (q--) {
    cin >> x >> y;
    cout << process() << '\n';
  }

  return 0;
}