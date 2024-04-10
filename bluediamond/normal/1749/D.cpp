#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
mt19937 rng(228);
#else
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

typedef long long ll;
const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll)b % M;
}

int add(int a, int b, int c) {
  return add(add(a, b), c);
}

int mul(int a, int b, int c) {
  return mul(mul(a, b), c);
}

int add(int a, int b, int c, int d) {
  return add(add(a, b, c), d);
}

int mul(int a, int b, int c, int d) {
  return mul(mul(a, b, c), d);
}

int add(int a, int b, int c, int d, int e) {
  return add(add(a, b, c, d), e);
}

int mul(int a, int b, int c, int d, int e) {
  return mul(mul(a, b, c, d), e);
}

int add(int a, int b, int c, int d, int e, int f) {
  return add(add(a, b, c, d, e), f);
}

int mul(int a, int b, int c, int d, int e, int f) {
  return mul(mul(a, b, c, d, e), f);
}

int add(int a, int b, int c, int d, int e, int f, int g) {
  return add(add(a, b, c, d, e, f), g);
}

int mul(int a, int b, int c, int d, int e, int f, int g) {
  return mul(mul(a, b, c, d, e, f), g);
}

int add(int a, int b, int c, int d, int e, int f, int g, int h) {
  return add(add(a, b, c, d, e, f, g), h);
}

int mul(int a, int b, int c, int d, int e, int f, int g, int h) {
  return mul(mul(a, b, c, d, e, f, g), h);
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

void addup(int& a, int b) {
  a = add(a, b);
}

void mulup(int& a, int b) {
  a = mul(a, b);
}

void dvup(int& a, int b) {
  a = dv(a, b);
}

const int N = (int)3e5 + 7;

bool isprime(int x) {
  if (x <= 1)return 0;
  for (int i = 2; i * i <= x; i++)if (x % i == 0)return 0;
  return 1;
}

signed main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

  int n;
  ll lim;
  cin >> n >> lim;
  ll man = 1;
  int prod = 1, sol = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    if (isprime(i))man *= i;
    cnt = (lim / man) % M;
    mulup(prod, cnt);
    if (prod == 0) {
      break;
    }
    addup(sol, prod);
  }
  sol = add(0, -sol);
  int cur = 1;
  for (int i = 1; i <= n; i++) {
    mulup(cur, lim % M);
    addup(sol, cur);
  }
  cout << sol << "\n";
  return 0;
}


/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */