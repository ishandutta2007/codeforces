#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
typedef vector<vector<int> > graph;
typedef long long ll;

graph G;
int n, m;
ll deg[100005];
ll len[100005];

int main() {
	ios::sync_with_stdio(0);
  cin >> n >> m;
  G = graph(n+1, vector<int>());
  for(int i = 0; i < m; ++i) {
    int a,b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
    ++deg[a];
    ++deg[b];
  }
  len[1] = 1;
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    len[i] = 1;
    for(int j = 0; j < G[i].size(); ++j) {
      int v = G[i][j];
      if(v >= i) continue;
      len[i] = max(len[i], 1+len[v]);
    }
    ans = max(ans, len[i]*deg[i]);
  }
  cout << ans << "\n";
	return 0;
}