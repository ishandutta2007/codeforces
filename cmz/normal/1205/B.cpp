#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10, LOG = 60, M = 1010;
ll a[N];
int b[M][M], dis[M], vis[M];
int nm[LOG + 2];
 
void Min(int &x, int y) {
  if(!x) x = y;
  else x = min(x, y);
}
 
queue<int>q;
 
bool cmp(ll x, ll y) {
  return x > y;
}
 
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    for(int j = 0; j <= LOG; ++j) {
      if(a[i] & (1ll << j))
        nm[j]++;
    }
  }
  sort(a + 1, a + 1 + n, cmp);
  while(n && !a[n]) --n;
  // printf("%d\n", n);
  int flg = 1;
  for(int i = 0; i <= LOG; ++i)
    if(nm[i] > 1) flg = 0;
  if(flg || n < 3) return printf("-1\n"), 0;
  for(int i = 0; i <= LOG; ++i) 
    if(nm[i] >= 3) return printf("3\n"), 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = i + 1; j <= n; ++j) {
      if(a[i] & a[j]) {
        b[i][j] = b[j][i] = 1;
      }
    }
  }
  int ans = 1e9;
  for(int i = 1; i <= n; ++i)
    for(int j = i + 1; j <= n; ++j) {
      if(!b[i][j]) continue;
      b[i][j] = 0;
      int be = i, ed = j;
      memset(dis, 0x3f, sizeof dis);
      dis[be] = 1;
      q.push(be);
      while(!q.empty()) {
        int h = q.front(); q.pop();
        vis[h] = 0;
        for(int k = 1; k <= n; ++k) {
          if(b[h][k] && dis[k] > dis[h] + 1) {
            dis[k] = dis[h] + 1;
            if(!vis[k]) {
              q.push(k);
              vis[k] = 1;
            }
          }
        }
      }
      b[i][j] = 1;
      ans = min(ans, dis[ed]);
    }
  if(ans == 1e9) puts("-1");
  else printf("%d\n", ans);
  return 0;
}