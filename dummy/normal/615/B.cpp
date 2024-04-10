#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, deg[N], len[N];

vector< int > adj[N];

int main() {
  scanf("%d%d", &n, &m);
  while(m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    if(u > v)
      swap(u, v);
    adj[u].push_back(v);
    deg[u]++; deg[v]++;
  }
  long long ans = 0;
  for(int i = 0; i<n; i++) {
    len[i] = max(len[i], 1);
    ans = max(ans, 1LL*len[i]*deg[i]);
    for(int u : adj[i])
      len[u] = max(len[u], len[i]+1);
  }
  cout << ans << endl;
  return 0;
}