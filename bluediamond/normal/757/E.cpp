#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC optimize("O1")
///#pragma GCC optimize("O2")

///#pragma GCC optimize("O3")
///#pragma GCC optimize("Os")
///#pragma GCC optimize("Ofast")
///#pragma GCC target("avx,avx2,fma")

///#pragma GCC target("avx2")

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

class linearSieve { /// linear Sieve
public:
  vector<int> primes;
  vector<int> lp;
  void put(int Limit) {
    primes.clear();
    lp.clear();
    lp.resize(Limit + 1, 0);
    for (int i = 2; i <= Limit; i++) {
      if (!lp[i]) {
        lp[i] = i;
        primes.push_back(i);
      }
      for (int j = 0; j < (int) primes.size() && primes[j] * i <= Limit && primes[j] <= lp[i]; j++) {
        lp[primes[j] * i] = primes[j];
      }
    }
  }
} user;


const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = (int) 1e6 + 12345 + 7;
int fact[N], ifact[N];
int tab[N];

int comb(int n, int k) {
  if (k < 0 || k > n) return 0;
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int get(int r, int n) {
  vector<int> divis;
  for (int j = 1; j <= n; j *= 2) {
    divis.push_back(j);
  }
  int ret = 0;
  for (auto &i : divis) {
    int x = tab[i];
    int coef = 1;

    int y = n / i;

    while (y > 1) {
      int d = user.lp[y], cnt = 0;
      while (y % d == 0) {
        y /= d;
        cnt++;
      }
      coef = mul(coef, comb(cnt + r - 1, cnt));
    }
    ret = add(ret, mul(x, coef));
  }
  return ret;
}

signed realMain() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);
  user.put(N);
  for (int i = 1; i < N; i++) {
    tab[i] = 1;
    int x = i;
    while (x > 1) {
      int d = user.lp[x];
      while (x % d == 0) {
        x /= d;
      }
      tab[i] *= 2;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int r, n, ret = 1;
    cin >> r >> n;
    while (n > 1) {
      int num = 0, val = user.lp[n];
      while (n % val == 0) {
        num++;
        n /= val;
      }
      ret = mul(ret, get(r, 1 << num));
    }
    cout << ret << "\n";
  }
  return 0;
}