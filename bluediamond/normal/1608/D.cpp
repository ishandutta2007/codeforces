#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 998244353;

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

const int N = (int) 2e5 + 7;
int fact[N], ifact[N];

int comb(int n, int k) {
  assert(0 <= k && k <= n && n < N);
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

void compute() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = mul(ifact[i + 1], i + 1);
  }
  for (int i = 0; i < N; i++) {
    assert(mul(fact[i], ifact[i]) == 1);
  }
}


mt19937 rng(0);

char gen() {
  int r = rng() % 3;
  assert(0 <= r && r <= 2);
  if (r == 0) return '?';
  if (r == 1) return 'W';
  return 'B';
}

bool ok(vector<string> strs) {
  int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
  bool allw = true, allb = true;
  bool same = true;
  for (auto &s : strs) {
    assert((int) s.size() == 2);
    assert(s[1] == 'W' || s[1] == 'B');
    if (s[1] == 'W') {
      s[1] = 'B';
    } else {
      s[1] = 'W';
    }
    for (auto &ch : s) {
      allw &= (ch == 'W');
      allb &= (ch == 'B');
    }

    c1 += (s[0] == 'W');
    c2 += (s[1] == 'W');
    c3 += (s[0] == 'B');
    c4 += (s[1] == 'B');

    same &= (s[0] == s[1]);
  }

  if (allw) {
    return true;
  }
  if (allb) {
    return true;
  }
  if (same) {
    return false;
  }
  if (c1 == c2) {
    assert(c3 == c4);
  }
  return c1 == c2;
}

int cox;

void bkt(vector<string> strs) {
  for (auto &s : strs) {
    for (auto &ch : s) {
      if (ch == '?') {
        ch = 'W';
        bkt(strs);
        ch = 'B';
        bkt(strs);
        return;
      }
    }
  }
  cox += ok(strs);
}

int brute(vector<string> strs) {
  cox = 0;
  bkt(strs);
  return cox;
}


int mysolve(vector<string> strs) {
  if (strs.empty()) {
    return 1;
  }
  bool allw = true, allb = true;
  int a = 0, b = 0, n = (int) strs.size(), ua = 0, ub = 0;
  int cnt = 1;
  for (auto &s : strs) {
    if (s[1] == 'W') {
      s[1] = 'B';
    } else {
      if (s[1] == 'B') {
        s[1] = 'W';
      }
    }
    for (auto &ch : s) {
      if (ch == 'W') {
        allb = false;
      }
      if (ch == 'B') {
        allw = false;
      }
    }
    if (s[0] == s[1]) {
      if (s[0] == '?') {
        cnt = mul(cnt, 2);
      } else {
        if (s[0] == 'W') {
          cnt = cnt;
        } else {
          assert(s[0] == 'B');
          cnt = cnt;
        }
      }
    } else {
      if (s[0] == '?' || s[1] == '?') {
        cnt = cnt;
      } else {
        cnt = 0;
      }
    }

    if (s[0] == 'W') {
      a++;
    }
    if (s[0] == '?') {
      ua++;
    }
    if (s[1] == 'W') {
      b++;
    }
    if (s[1] == '?') {
      ub++;
    }
  }
  /// we want a == b

  /// a + fa = b + fb


  int sol = 0;


  for (int fa = 0; fa <= ua; fa++) {
    int fb = a + fa - b;
    if (0 <= fb && fb <= ub) {
      sol = add(sol, mul(comb(ua, fa), comb(ub, fb)));
    }
  }


  if (allb) {
    sol = add(sol, 1);
  }
  if (allw) {
    sol = add(sol, 1);
  }

  sol = add(sol, -cnt);
  return sol;
}

vector<string> getrng() {
  int n = rng() % 10;
  vector<string> strs(n);
  for (auto &s : strs) {
    for (int i = 0; i < 2; i++) {
      s += gen();
    }
  }
  return strs;
}

signed main() { compute();

  //freopen ("input", "r", stdin);

  if (0) {
    int st = 0;

    while (1) {
      st++;
      vector<string> strs = getrng();
      int br = brute(strs), my = mysolve(strs);
      if (st % 1000 == 0) {
        cout << st << " are ok!\n";
      }
      if (br != my) {
        cout << "st = " << st << "\n";
        for (auto &s : strs) {
          cout << s << "\n";
        }
        cout << "---------------\n";
        cout << "br = " << br << "\n";
        cout << "my = " << mysolve(strs) << "\n";
        exit(0);
      }

      assert(br == my);
    }
    exit(0);
  }

  ios::sync_with_stdio(0); cin.tie(0);

  if (1) {
    int n;
    cin >> n;
    vector<string> strs(n);
    for (auto &s : strs) {
      cin >> s;
    }
    //cout << brute(strs) << "\n";
    cout << mysolve(strs) << "\n";

  }
}