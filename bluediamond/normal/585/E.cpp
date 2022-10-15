#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

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

class linearSieve {
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
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    a += M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = (int) 5e5 + 7;
const int L = (int) 1e7 + 7;
int n, a[N], p2[N], coef[N];
int sgn[L], cnt[L];

vector<int> gen(int a) {
  vector<int> sol;
  while (a > 1) {
    int p = user.lp[a];
    while (a % p == 0) {
      a /= p;
    }
    sol.push_back(p);
  }
  return sol;
}

signed realMain() {
  user.put(L);
  p2[0] = 1;
  for (int i = 1; i < N; i++) {
    p2[i] = mul(2, p2[i - 1]);
    coef[i] = add(p2[i], -1);
  }

  sgn[1] = -1;
  for (int i = 2; i < L; i++) {
    int p = user.lp[i];
    if ((i / p) % p) {
      sgn[i] = -sgn[i / p];
    }
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vector<int> primes = gen(a[i]);
    int sz = (int) primes.size();
    for (int mask = 1; mask < (1 << sz); mask++) {
      int prod = 1;
      for (int i = 0; i < sz; i++) {
        if (mask & (1 << i)) {
          prod *= primes[i];
        }
      }
      cnt[prod]++;
    }
  }
  int sum = 0;
  for (int i = 2; i < L; i++) {
    sum = add(sum, sgn[i] * coef[cnt[i]]);
  }
  /// cur = cate au gcd-ul > 1
  int sol = 0, aft;
  for (int i = 1; i <= n; i++) {
    vector<int> primes = gen(a[i]);
    int cur = sum;
    int sz = (int) primes.size();
    aft = coef[n - 1];
    for (int mask = 1; mask < (1 << sz); mask++) {
      int prod = 1;
      for (int i = 0; i < sz; i++) {
        if (mask & (1 << i)) {
          prod *= primes[i];
        }
      }
      cur = add(cur, -sgn[prod] * coef[cnt[prod]]);
      cur = add(cur, +sgn[prod] * coef[cnt[prod] - 1]);

      aft = add(aft, -sgn[prod] * coef[cnt[prod] - 1]);
    }
    int bef = add(coef[n - 1], -cur);
    sol = add(sol, add(aft, -bef));
  }
  cout << sol << "\n";
  return 0;
}