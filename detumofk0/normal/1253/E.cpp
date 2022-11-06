#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct RMQ{
  int rmq[N][20];
  RMQ(){
    memset(rmq, 60, sizeof rmq);
  }
  void add(int i, int x) {
    rmq[i][0] = x;
    for(int j = 1; j < 20; ++j) {
      if(i - (1 << j) + 1 < 0) break;
      rmq[i][j] = min(rmq[i][j - 1], rmq[i - (1 << (j - 1))][j - 1]);
    }
  }
  int query(int l, int r) {
    int _log = log2(r - l + 1);
    return min(rmq[r][_log], rmq[l + (1 << _log) - 1][_log]);
  }
}g1, g2;

int n, m;
int a[N];
int r[N];
int f[N];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i] >> r[i];
  }

  memset(f, 60, sizeof f);

  f[0] = 0;
  g1.add(0, 0);
  g2.add(0, 0);

  for(int i = 1; i <= m; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(a[j] > i) continue;
      int cost = max(0, i - a[j] - r[j]);
      int bound = max(0, a[j] - r[j] - cost - 1);

      f[i] = min(f[i], g1.query(bound, i - 1) + cost);
      if(bound > 0) f[i] = min(f[i], g2.query(0, bound - 1) + bound + cost);
    }
    g1.add(i, f[i]);
    g2.add(i, f[i] - i);
  }

  cout << f[m] << endl;

  return 0;
}