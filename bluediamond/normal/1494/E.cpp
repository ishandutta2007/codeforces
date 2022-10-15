#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n, q, eq = 0, sum = 0;
set<int> g[N];
map<pair<int, int>, int> col;
map<pair<int, int>, int> f[N];

bool good(int a, int b) {
  if (!g[a].count(b)) return 0;
  if (!g[b].count(a)) return 0;
  return col[{a, b}] == col[{b, a}];
}

void del(int a, int b) {
  if (!g[a].count(b) || !g[b].count(a)) return;
  sum -= (f[a][{col[{a, b}], col[{b, a}]}] == 1);
  f[a][{col[{a, b}], col[{b, a}]}]--;
  swap(a, b);
  sum -= (f[a][{col[{a, b}], col[{b, a}]}] == 1);
  f[a][{col[{a, b}], col[{b, a}]}]--;
}

void add(int a, int b) {
  if (!g[a].count(b) || !g[b].count(a)) return;
  f[a][{col[{a, b}], col[{b, a}]}]++;
  sum += (f[a][{col[{a, b}], col[{b, a}]}] == 1);
  swap(a, b);
  f[a][{col[{a, b}], col[{b, a}]}]++;
  sum += (f[a][{col[{a, b}], col[{b, a}]}] == 1);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  while (q--) {
    string s;
    cin >> s;
    if (s == "+") {
      int a, b;
      cin >> a >> b >> s;
      del(a, b);
      eq -= good(a, b);
      g[a].insert(b);
      col[{a, b}] = s[0] - 'a';
      eq += good(a, b);
      add(a, b);
      continue;
    }
    if (s == "-") {
      int a, b;
      cin >> a >> b;
      del(a, b);
      eq -= good(a, b);
      g[a].erase(b);
      eq += good(a, b);
      add(a, b);
      continue;
    }
    int k;
    cin >> k;
    k++;
    if (eq) {
      cout << "YES\n";
      continue;
    }
    if (k % 2 == 0) {
      if (sum) {
        cout << "YES\n";
        continue;
      }
    }
    cout << "NO\n";
  }
}