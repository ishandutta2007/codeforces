#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

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

int dp[66][6];
bool bad[6][6];
map<string, int> mp;
set<int> spec;
map<int, int> este;
map<pair<int, int>, int> memo;

int get(int x, int color, int level) {
  if (memo.count({x, color})) return memo[{x, color}];
  if (!spec.count(x)) {
   /// cout << x << " " << color << " : " << dp[level][color] << "\n";
    memo[{x, color}] = dp[level][color];
    return dp[level][color];
  }

  if (level == 1) {
    if (este.count(x)) {
      memo[{x, color}] = (color == este[x]);
    } else {
      memo[{x, color}] = 1;
    }
   /// cout << x << " = " << memo[{x, color}] << "\n";
    return memo[{x, color}];
  }


  if (este.count(x)) {
    if (este[x] != color) return 0;
  }

  vector<int> good;
  for (int i = 0; i < 6; i++) {
    if (!bad[color][i]) good.push_back(i);
  }



  int sol = 0;

  for (auto &k1 : good) {
    for (auto &k2 : good) {
      addup(sol, mul(get(2 * x, k1, level - 1), get(2 * x + 1, k2, level - 1)));
    }
  }

  memo[{x, color}] = sol;
  return sol;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  for (int i = 0; i < 6; i++) {
    bad[i][i] = 1;
    bad[i][i ^ 1] = 1;
    dp[1][i] = 1;
  }



  for (int i = 2; i <= 60; i++) {
    for (int top = 0; top < 6; top++) {
      vector<int> good;
      for (int i = 0; i < 6; i++) {
        if (!bad[top][i]) good.push_back(i);
      }
      for (auto &k1 : good) {
        for (auto &k2 : good) {
          addup(dp[i][top], mul(dp[i - 1][k1], dp[i - 1][k2]));
        }
      }
    }
  }

  mp["white"] = 0;
  mp["yellow"] = 1;
  mp["green"] = 2;
  mp["blue"] = 3;
  mp["red"] = 4;
  mp["orange"] = 5;

  int k, n;
  cin >> k >> n;
  int last = (1LL << k) - 1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    string s;
    cin >> s;
    int c = mp[s];
    if (este.count(x)) {
      if (este[x] != c) {
        cout << "0\n";
        return 0;
      }
    }
    este[x] = c;
    while (x > 1) {
      int nxt = x / 2;
      spec.insert(x);
      x = x / 2;
    }
    spec.insert(1);
  }
  int sol = 0;
  for (int i = 0; i < 6; i++) {
    addup(sol, get(1, i, k));
  }
  cout << sol << "\n";
  return 0;
}