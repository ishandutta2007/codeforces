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

vector<int> g[2010];
int d[2010];

void dfs(int x, int dep) {
  d[x] = dep++;
  for (int y : g[x])
    dfs(y, dep);
}

int main() {
  int n;
  cin >> n;
  REPE(i, 1, n) {
    int x;
    cin >> x;
    if (x >= 0) g[x].PB(i);
  }
  REPE(i, 1, n) if (!d[i])
    dfs(i, 1);
  cout << *max_element(d, d + n + 1) << endl;
  return 0;
}