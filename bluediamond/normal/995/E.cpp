#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

int mod;

int add(int a, int b) {
  a += b;
  if (a >= mod) return a - mod;
  if (a < 0) return a + mod;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % mod;
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
  return mul(a, pw(b, mod - 2));
}

int f1(int a) {
  return add(a, 1);
}

int f2(int a) {
  return add(a, -1);
}

int f3(int a) {
  return pw(a, mod - 2);
}

int f(int x, int type) {
  if (type == 1) return f1(x);
  if (type == 2) return f2(x);
  if (type == 3) return f3(x);
  assert(0);
}

///mt19937 rng((long long) (new char));
mt19937 rng(2);

vector<int> get_rng(int x, map<int, vector<int>> &to) {
  vector<int> steps, gen = {x};
  for (int j = 0; j <= 100; j++) {
    int type = rng() % 3 + 1;
    if (!to.count(x)) {
      to[x] = steps;
    }
    steps.push_back(type);
    x = f(x, type);
    gen.push_back(x);
  }
  return gen;
}

signed realMain() {
  vector<int> a(2);
  map<int, vector<int>> t[2];
  cin >> a[0] >> a[1] >> mod;
  int it = 0;
  while (1) {
    auto now = get_rng(a[it], t[it]);
    it ^= 1;
    for (auto &x : now) {
      if (t[it].count(x)) {
        vector<int> ret, suf;
        for (auto &tp : t[0][x]) ret.push_back(tp);
        for (auto &tp : t[1][x]) {
          if (tp == 3) {
            suf.push_back(tp);
          } else {
            suf.push_back(3 - tp);
          }
        }
        reverse(suf.begin(), suf.end());
        for (auto &tp : suf) ret.push_back(tp);
        cout << (int) ret.size() << "\n";
        for (auto &x : ret) {
          cout << x << " ";
        }
        cout << "\n";
        exit(0);
      }
    }
  }
  return 0;
}