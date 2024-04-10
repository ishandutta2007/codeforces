#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

int n, m;
string a[1010];
int b[1010];
string c[1010];

map<string, int> rev;
bool fail[110][110];
int chz[110];
string s;

bool mat(string a, string b) {
  for (auto &c : a)
    if (!isalnum(c))
      c = ' ';
  stringstream ss(a);
  while (ss >> a)
    if (a == b) return true;
  return false;
}

bool f(int x, int y) {
  if (x == m) {
    REP(i, m) {
      cout << a[chz[i]] << ":" << c[i] << endl;
    }
    return true;
  }
  if (fail[x][y]) return false;
  bool ret = false;
  if (b[x] != -1) {
    if (b[x] != y) {
      bool tmp = mat(c[x], a[b[x]]);
      if (!tmp) {
        chz[x] = b[x];
        ret = f(x + 1, b[x]);
      }
    }
  }
  else {
    REP(i, n) if (i != y) {
      if (mat(c[x], a[i])) continue;
      chz[x] = i;
      ret = f(x + 1, i);
      if (ret) break;
    }
  }
  if (!ret) fail[x][y] = true;
  return ret;
}

void solve() {
  scanf("%d", &n);
  rev.clear();
  REP(i, n) {
    cin >> a[i];
    rev[a[i]] = i;
  }
  rev["?"] = -1;
  cin >> m;
  getline(cin, s);
  REP(i, m) {
    getline(cin, s);
    int j = 0;
    while (s[j] != ':') j++;
    string name = s.substr(0, j);
    string sen = s.substr(j + 1);
    b[i] = rev[name];
    c[i] = sen;
  }
  memset(fail, 0, sizeof fail);
  if (!f(0, n)) puts("Impossible");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}