#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 998244353;

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
    if (b & 1) r = mul(r, a);
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

void mulup(int &a, int b) {
  a = mul(a, b);
}

const int N = 23;
const int INF = (int) 1e9 + 7;
int n, f[N][26], mn[26], compute[1 << N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 // freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < (int) s.size(); j++) {
      assert('a' <= s[j] && s[j] <= 'z');
      f[i][s[j] - 'a']++;
    }
  }

  for (int mask = 1; mask < (1 << n); mask++) {
    vector<int> who;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        who.push_back(i);
      }
    }

    int prod = 1;

    for (int i = 0; i < 26; i++) {
      mn[i] = INF;
    }

    for (auto &i : who) {
      for (int j = 0; j < 26; j++) {
        mn[j] = min(mn[j], f[i][j]);
      }
    }

    for (int i = 0; i < 26; i++) {
      mulup(prod, mn[i] + 1);
    }


    if ((int) who.size() % 2 == 1) {
      compute[mask] = prod;
    } else {
      compute[mask] = add(0, -prod);
    }
  }

  for (int bit = 0; bit < n; bit++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      if (mask & (1 << bit)) {
        compute[mask] += compute[mask ^ (1 << bit)];
        if (compute[mask] >= M) {
          compute[mask] -= M;
        }
      }
    }
  }

  ll sol = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    vector<int> inds;
    ll coef = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        inds.push_back(i);
        coef += (i + 1);
      }
    }
    coef *= (int) inds.size();
    sol ^= (coef * (ll) compute[mask]);

  }
  cout << sol << "\n";

  return 0;
}