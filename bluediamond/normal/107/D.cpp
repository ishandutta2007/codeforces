#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 12345;

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

ll n;
int q;
vector<int> g[26];
int p[26];
vector<vector<int>> good;
vector<int> prods;
int sz;
int pall = 1;
int go[123][123];

int get(vector<int> a) {
  int sol = 0;
  for (int i = 0; i < sz; i++) {
    sol = sol * prods[i] + a[i];
  }
  return sol;
}

vector<int> get(int x) {
  vector<int> sol;
  for (int i = sz - 1; i >= 0; i--) {
    sol.push_back(x % prods[i]);
    x /= prods[i];
  }
  reverse(sol.begin(), sol.end());
  return sol;
}

void print(vector<int> a) {
  cout << " : ";
  for (auto &x : a) {
    cout << x << " ";
  }
  cout << "\n";
}

vector<int> operator * (vector<int> a, vector<int> b) {
  vector<int> c(pall, 0);
  for (int i = 0; i < pall; i++) {
    for (int j = 0; j < pall; j++) {
      int k = go[i][j];
      c[k] = add(c[k], mul(a[i], b[j]));
    }
  }
  return c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  if (q == 0) {
    cout << (n == 0) << "\n";
    return 0;
  }
  while (q--) {
    string s;
    int x;
    cin >> s >> x;
    int i = s[0] - 'A';
    if (p[i] == 0) {
      p[i] = 1;
    }
    g[i].push_back(x);
    p[i] *= x;
  }
  for (int i = 0; i < 26; i++) {
    if (p[i]) {
      good.push_back(g[i]);
      prods.push_back(p[i]);
      sz++;
    }
  }
  pall = 1;
  for (auto &it : prods) {
    pall *= it;
  }
  for (int i = 0; i < pall; i++) {
    for (int j = 0; j < pall; j++) {
      vector<int> a = get(i), b = get(j);
      vector<int> c(sz);
      for (int k = 0; k < sz; k++) {
        c[k] = (a[k] + b[k]) % prods[k];
      }
      go[i][j] = get(c);
    }
  }
  vector<int> zero(sz, 0);
  vector<int> sol(pall, 0), cur(pall, 0);
  sol[0] = 1;
  for (int i = 0; i < sz; i++) {
    vector<int> alpha = zero;
    alpha[i] = 1 % prods[i];
    cur[get(alpha)] += 1;
  }
  for (int p = 0; (1LL << p) <= n; p++) {
    if (n & (1LL << p)) {
      sol = sol * cur;
    }
    cur = cur * cur;
  }
  int ans = 0;
  for (int i = 0; i < pall; i++) {
    vector<int> a = get(i);
    bool oke = 1;
    for (int k = 0; k < sz; k++) {
      oke = 0;
      for (auto &it : good[k]) {
        if (a[k] % it == 0) {
          oke = 1;
          break;
        }
      }
      if (oke == 0) {
        break;
      }
    }
    if (oke) {
      ans = add(ans, sol[i]);
    }
  }
  cout << ans << "\n";
  return 0;
}