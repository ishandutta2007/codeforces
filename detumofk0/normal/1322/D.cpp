#include<bits/stdc++.h>

using namespace std;

const int maxn = 2055;
const int maxm = 4005;

int n, m;
int a[maxn];
int s[maxn];
int cost[maxm];

int g[maxn][maxn];
int f[maxn][maxn];

int bit[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m;
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i) cin >> s[i];
  for(int i = 1; i <= n + m; ++i) cin >> cost[i];

  reverse(a, a + n);
  reverse(s, s + n);

  for(int i = 0; i < maxn; ++i) {
    for(int j = 0; j < maxn; ++j) {
      g[i][j] = bit[i] = f[i][j] = -1e9 - 7;
    }
  }

  auto update = [&](int x, int val) {
    x++;
    for(; x < maxn; x += x & -x) bit[x] = max(bit[x], val);
    return;
  };

  auto get = [&](int x) {
    x++;
    int risan = 0;
    for(; x > 0; x -= x & -x) risan = max(risan, bit[x]);
    return risan;
  };

  f[0][0] = g[0][0] = 0;
  update(0, 0);

  for(int i = 0; i < n; ++i) {
    int v = a[i];
    /// stays at v
    for(int j = i; j >= 0; --j) {
      int cur = f[v][j];
      if(j == 0) {
        cur = max(cur, get(v));
      }
      f[v][j + 1] = max(f[v][j + 1], cur - s[i]);
    }
    /// next levels
    for(int j = 1; j <= i + 1; ++j) {
      int nxt = v, temp = j, curcost = f[v][j];
      while(temp > 1) {
        curcost += cost[nxt] * temp;
        ++nxt;
        temp /= 2;
        f[nxt][temp] = max(f[nxt][temp], curcost);
      }
      update(nxt + 1, curcost + cost[nxt]);
    }
    f[v][0] = max(f[v][0], get(v));
  }

  int ans = 0;
  for(int i = 0; i < maxn; ++i) {
    ans = max(ans, f[i][0]);
    ans = max(ans, get(i));
  }

  cout << ans << endl;

  return 0;
}