#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
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

void addup(int &a, int b) {
  a = add(a, b);
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

void place(int n, vector<int> &divis) {
  divis = {1};
  while (n > 1) {
    int p = user.lp[n], e = 0;
    while (n % p == 0) {
      n /= p;
      e++;
    }
    vector<int> divis2;
    int cur = 1;
    for (int t = 0; t <= e; t++) {
      for (auto &x : divis) divis2.push_back(x * cur);
      cur *= p;
    }
    divis = divis2;
  }
}

const int N = (int) 2e5 + 7;
const int A = (int) 1e6 + 7;

int pt[N], cnt[A], fact[N], ifact[N], mx, ret[N], coef[N], need[N], cf[A], sol;

void add(int x) {
  mx = max(mx, x);
  vector<int> d;
  place(x, d);
  for (auto &y : d) {
    addup(sol, -mul(pt[cnt[y]], cf[y]));
    cnt[y]++;
    addup(sol, mul(pt[cnt[y]], cf[y]));
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  user.put(A);
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = mul(ifact[i + 1], i + 1);
  }
  int n, k, q;
  cin >> n >> k >> q;
  for (int i = k; i < N; i++) {
    pt[i] = mul(fact[i], mul(ifact[k], ifact[i - k]));
  }
  for (int i = 1; i < A; i++) {
    need[i] = i;
  }
  for (int i = 1; i < A; i++) {
    int x = need[i];
    cf[i] = x;
    for (int j = i; j < A; j += i) {
      need[j] -= x;
    }
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    add(x);
  }
  while (q--) {
    int x;
    cin >> x;
    add(x);
    cout << sol << "\n";
  }




  return 0;
}