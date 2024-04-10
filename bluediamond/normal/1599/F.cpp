#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

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

const int N = (int) 2e5 + 7;
const int K = 66;
int n, q, a[N], pref[N], coef[N][K + 1], fact[N], ifact[N], prefixhash[N];

int comb(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int coefs[N][K + 1];

int speccase[N];


int evaluate(int x, int last) {
  int sol = 0, px = 1;
  for (int p = 0; p <= K; p++) {
    addup(sol, mul(px, coef[last][p]));
    px = mul(px, x);
  }
  return sol;
}

int smart(int first, int len, int dif) {
  if (first == 0) {
    /// caz special
    return mul(speccase[len - 1], pw(dif, K));
  }

  int sol = evaluate(dv(dif, first), len - 1);
  return mul(pw(first, K), sol);
}

mt19937 rng((long long) (new char));

void gen() {
  freopen ("input", "w", stdout);

  int n = 100, q = n * (n + 1) / 2;
  cout << n << " " << q << "\n";
  for (int i = 1; i <= n; i++) {
    cout << rng() % M << " ";
  }
  cout << "\n";
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      cout << i << " " << j << " " << rng() % M << "\n";
    }
  }

  exit(0);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 //gen();
  {
    int cur = 0;
    for (int i = 0; i < N; i++) {
      addup(cur, pw(i, K));
      speccase[i] = cur;
    }
  }

  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = mul(ifact[i + 1], i + 1);
  }


  for (int j = 0; j < N; j++) {
    int pj = 1;
    for (int p = 0; p <= K; p++) {
      coef[j][p] = mul(comb(K, p), pj);
      if (j) {
        coef[j][p] = add(coef[j - 1][p], coef[j][p]);
      }
      pj = mul(pj, j);
    }
  }


  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    prefixhash[i] = add(prefixhash[i - 1], pw(a[i], K));
    pref[i] = add(pref[i - 1], a[i]);
  }

  while (q--) {
    int l, r, d;
    cin >> l >> r >> d;
    int sum = add(pref[r], -pref[l - 1]), len = r - l + 1;
    int first = add(dv(sum, len), -mul(dv(d, 2), len - 1));
    sum = add(prefixhash[r], -prefixhash[l - 1]);
    int really = smart(first, len, d);

    cout << ((really == sum) ? "Yes" : "No") << "\n";

  }


  return 0;
}