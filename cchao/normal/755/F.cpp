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
int n, k;
int p[maxn];
bool v[maxn];
vector<int> a;
int d[maxn];
int main() {
  scanf("%d%d", &n, &k);
  REP(i, n) {
    scanf("%d", &p[i]);
    --p[i];
  }
  if (k == 0) {
    puts("0 0");
    return 0;
  }
  for (int i = 0; i < n; ++i) if (!v[i]) {
    int cnt = 0;
    int j = i;
    while (!v[j]) {
      v[j] = true;
      j = p[j];
      cnt++;
    }
    a.PB(cnt);
  }
  map<int, int> f;
  for (auto x : a) f[x]++;
  int target = min(k, n - k);
  d[0] = 1;
  for (auto it : f) {
    int x = it.F;
    int y = it.S;
    for (int i = target; i >= 0; --i) if (d[i]) {
      for (int j = 0, s = i; j <= y; ++j, s += x) {
        if (s > target || d[s] == x) break;
        d[s] = x;
      }
    }
    if (d[target]) break;
  }
  LL mi = d[target] ? k : k + 1;
  mi = min(mi, (LL)n);
  LL mx = 0;
  for (auto &x : a) {
    int t = min(x / 2, k);
    k -= t;
    mx += t * 2;
    x -= t * 2;
  }
  for (auto &x : a) {
    int t = min(x, k);
    k -= t;
    mx += t;
    x -= t;
  }
  mx = min(mx, (LL)n);
  cout << mi << ' ' << mx << endl;
  return 0;
}