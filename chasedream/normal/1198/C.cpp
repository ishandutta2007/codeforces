%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 100005;
int vis[3 * N], n, m;
 
int main() {
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 3 * n; i++) vis[i] = 0;
 
    vector <int> ans;
    for (int i = 1; i <= m; i++) {
      int u, v; scanf("%d%d", &u, &v);
      if (!vis[u] && !vis[v]) {
        vis[u] = vis[v] = 1;
        ans.push_back(i);
      }
    }
    
    if ((int)ans.size() >= n) {
      puts("Matching");
      for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
      }
      putchar('\n');
    }
    else {
      puts("IndSet"); int cnt = 0;
      for (int i = 1; i <= 3 * n; i++) {
        if (!vis[i]) {
          printf("%d ", i);
          if (++cnt == n) break;
        }
      }
      putchar('\n');
    }
  }
  return 0;
}
 //