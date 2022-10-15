#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
typedef long double ld;

const int M = (int) 1e9 + 7;

void check(int a) {
}

int add(int a, int b) {
  a %= M;
  b %= M;
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  a %= M;
  b %= M;
  check(a); check(b);
  return a * (int) b % M;
}

int pw(int a, int b) {
  a %= M;
  check(a);
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  check(a); check(b);
  return mul(a, pw(b, M - 2));
}

const int N = 2000 + 7;
const int OO = (int) 1e18 + 7;
int n, m, q, top;
int summax[N][N];
vector<pair<int, int>> e[N];

struct T {
  int a, b;
};

int eval(T it, int x) {
  return it.a * x + it.b;
}

T ln[N];

bool operator < (T f, T s) {
  if (f.a == s.a) {
    return f.b > s.b;
  } else {
    return f.a < s.a;
  }
}

ld isect(T f, T s) {
  ld a1 = f.a, b1 = f.b;
  ld a2 = s.a, b2 = s.b;
  return (b2 - b1) / (a1 - a2);
}

int gauss(int p) {
  int sol = mul(p % M, p + 1);
  sol = dv(sol, 2);
  return sol;
}

int gauss(int l, int r) {
  return add(gauss(r), -gauss(l - 1));
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  bool oke;
  cin >> n >> m >> q;
  oke = (n == 2000 && m == 1999 && q == 20001);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    e[a].push_back({b, c});
    e[b].push_back({a, c});
  }
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) summax[i][j] = -OO;
  summax[0][1] = 0;
  for (int ced = 0; ced < m; ced++) {
    for (int i = 1; i <= n; i++) {
      for (auto &it : e[i]) {
        int j = it.first;
        int val = summax[ced][i] + it.second;
        summax[ced + 1][j] = max(summax[ced + 1][j], val);
      }
    }
  }
  int sol = 0;
  for (int ed = 1; ed <= min(q, m); ed++) {
    int best = 0;
    for (int i = 1; i <= n; i++) {
      best = max(best, summax[ed][i]);
    }
    sol = add(sol, best % M);
  }
  for (int i = 1; i <= n; i++) {
    int bigBrother = 0;
    for (auto &it : e[i]) {
      bigBrother = max(bigBrother, it.second);
    }
    ln[i] = {bigBrother, summax[m][i] - bigBrother * (int) m};
  }
  if (q < m + 1) {
    cout << sol << "\n";
    return 0;
  }

  int l = m + 1, r = q;
  sort(ln + 1, ln + n + 1);
  top = 0;
  for (int i = 1; i <= n; i++) {
    if (top == 0 || ln[i].a != ln[i - 1].a) {
      ln[++top] = ln[i];
    }
  }
  n = top;
  top = 0;
  for (int i = 1; i <= n; i++) {
    while (top >= 2 && isect(ln[top - 1], ln[i]) < isect(ln[top - 1], ln[top])) {
      top--;
    }
    ln[++top] = ln[i];
  }
  n = top;
  top = 0;
  int first = l;
  for (int i = 1; i <= n; i++) {
    int last = r;
    if (i < n) {
      last = isect(ln[i], ln[i + 1]);
      if (last < first) {
        continue;
      }
    }
    if (last > r) {
      last = r;
    }
    int a = ln[i].a % M;
    int b = ln[i].b % M;
    if (a < 0) a += M;
    if (b < 0) b += M;
    sol = add(sol, mul(last - first + 1, b));
    sol = add(sol, mul(a, gauss(first, last)));
    first = last + 1;
  }

  cout << sol << "\n";
  return 0;
}