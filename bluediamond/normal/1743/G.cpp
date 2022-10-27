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

const int N = 35;
const int L = (int)3e6 + 7;
bitset<L> fibo;
int fibdim[N];

bool getfib(int g, int p) {
  if (g <= 1) {
    return g;
  }
  if (p < fibdim[g - 1]) {
    return getfib(g - 1, p);
  }
  else {
    return getfib(g - 2, p - fibdim[g - 1]);
  }
}

struct T {
  int len;
  int dp;
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  fibdim[0] = fibdim[1] = 1;
  for (int i = 2; i < N; i++) {
    fibdim[i] = fibdim[i - 2] + fibdim[i - 1];
  }
  set<int> sfibo;
  for (int i = 0; i < N; i++) {
    sfibo.insert(fibdim[i]);
  }
  for (int p = 0; p < L; p++) {
    bool is = getfib(N - 1, p);
    if (is) {
      fibo[p] = 1;
    }
  }
  int sumdp = 1, lastdp = 1;
  vector<T> prs, nw;
  int n;
  cin >> n;
  for (int iten = 1; iten <= n; iten++) {
    string s;
    cin >> s;
    for (auto& ch : s) {
      int x = ch - '0';
      int dp = sumdp;
      addup(dp, -lastdp);
      nw.clear();
      for (auto& it : prs) {
        if (x == fibo[it.len]) {
          it.len++;
          if (sfibo.count(it.len)) {
            addup(dp, -it.dp);
          }
          nw.push_back(it);
        }
      }
      prs = nw;
      if (x == 1) {
        prs.push_back({ 1, lastdp });
      }
      addup(sumdp, dp);
      lastdp = dp;
    }
    cout << lastdp << "\n";
  }
  return 0;
}
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */