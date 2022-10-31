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

const int maxn = 1e6 + 10;
int n, m;
int a[maxn] = {};
int no = 1;
int f[maxn];
void update(vector<int> &b) {
  unordered_map<int, int> c;
  for (auto x : b) {
    if (!c.count(a[x])) c[a[x]] = no++;
    a[x] = c[a[x]];
  }
}
const int mod = 1000000007;
int main() {
  f[0] = 1;
  for (int i = 1; i < maxn; ++i)
    f[i] = (1LL * f[i - 1] * i) % mod;
  scanf("%d%d", &n, &m);
  REP(i, n) {
    int g;
    scanf("%d", &g);
    unordered_map<int, int> v;
    unordered_map<int, vector<int>> w;
    REP(j, g) {
      int x;
      scanf("%d", &x);
      x--;
      v[x]++;
    }
    for (auto it : v)
      w[it.S].push_back(it.F);
    for (auto &it : w) {
      update(it.S);
    }
  }
  unordered_map<int, int> b;
  REP(i, m) b[a[i]]++;
  int ans = 1;
  for (auto it : b) {
    ans = 1LL * ans * f[it.S] % mod;
  }
  printf("%d\n", ans);
  return 0;
}