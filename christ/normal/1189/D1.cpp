#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int leaf[100001];
bool yes = 1;
void dfs (int cur, int p) {
  int cnt = 0;
  for (int i : adj[cur]) if (i != p) {
    dfs(i,cur);
    if (adj[i].size()==1) cnt++;
  }
  if ((cnt == 1 && adj[cur].size() <= 2) || (cnt == 0 && adj[cur].size() == 2)) {printf ("NO\n"); exit(0);}
}
int main() {
  memset(leaf,-1,sizeof leaf);
  int n,a,b;
  scanf ("%d",&n);
  int leafcnt = 0;
  if (n <= 2) return !printf ("YES\n");
  for (int i = 0; i < n-1; i++) {
    scanf ("%d %d",&a,&b );
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) if (adj[i].size() == 1) leafcnt++;
  if (leafcnt < 3) return !printf ("NO\n");
  for (int i = 1; i <= n; i++) if (adj[i].size() > 1) {
    dfs(i,-1); break;
  }
  printf ("YES\n");
  return 0;
}