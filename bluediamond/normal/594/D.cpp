#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Question {
  int r;
  int i;
};

const int MOD = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= MOD) {
    return a - MOD;
  }
  if (a < 0) {
    return a + MOD;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % MOD;
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
  return mul(a, pw(b, MOD - 2));
}

const int N = 200000 + 7;
const int E = 1000000 + 7;
int n, a[N], pp[N], ipp[N], lp[E], val[E], ival[E], t[4 * N], q, sol[N], pos[E];
vector<int> primes, c[N], w[E];
vector<Question> qs[N];

int getpp(int l, int r) {
  return mul(pp[r], ipp[l - 1]);
}

void mult(int v, int tl, int tr, int i, int x) {
  if (tr < i || i < tl) {
    return;
  }
  if (tl == tr) {
    t[v] = mul(t[v], x);
    return;
  }
  int tm = (tl + tr) / 2;
  mult(2 * v, tl, tm, i, x);
  mult(2 * v + 1, tm + 1, tr, i, x);
  t[v] = mul(t[2 * v], t[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return 1;
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return mul(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

void mult(int i, int x) {
  mult(1, 1, n, i, x);
}

int get(int i) {
  return get(1, 1, n, 1, i);
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 2; i < E; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; j < (int) primes.size() && primes[j] * i < E && primes[j] <= lp[i]; j++) {
      lp[primes[j] * i] = primes[j];
    }
  }
  for (int i = 0; i < 4 * N; i++) {
    t[i] = 1;
  }
  for (auto &p : primes) {
    val[p] = dv(p - 1, p);
    ival[p] = dv(p, p - 1);
  }
  pp[0] = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pp[i] = mul(pp[i - 1], a[i]);
    int cop = a[i];
    while (cop > 1) {
      int p = lp[cop];
      c[i].push_back(p);
      while (cop % p == 0) {
        cop /= p;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    ipp[i] = dv(1, pp[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (auto &p : c[i]) {
      w[p].push_back(i);
    }
  }
  for (auto &p : primes) {
    if (!w[p].empty()) {
      mult(w[p][0], val[p]);
    }
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    qs[l].push_back({r, i});
  }
  for (int l = 1; l <= n; l++) {
    for (auto &it : qs[l]) {
      int r = it.r;
      int i = it.i;
      sol[i] = mul(getpp(l, r), get(r));
    }
    for (auto &p : c[l]) {
      mult(w[p][pos[p]], ival[p]);
      pos[p]++;
      if (pos[p] < (int) w[p].size()) {
        mult(w[p][pos[p]], val[p]);
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << sol[i] << "\n";
  }
  return 0;
}