#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int adj[105][105];
int n;

int search(int from, int parent, int v, bool first) {
  if(!first && v == from)
    return 0;
  for(int i = 1; i <= n; ++i) {
    if(i == parent) continue;
    else if(adj[v][i] != -1e9)
      return search(from, v, i, false) + adj[v][i];
  }
  return 0;
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      adj[i][j] = -1e9;
  for(int i = 0; i < n; ++i) {
    int a,b,c;
    cin >> a >> b >> c;
    adj[a][b] = 0;
    adj[b][a] = c;
  }
  vector<int> n0;
  for(int i = 1; i <= n; ++i)
    if(adj[1][i] != -1e9)
      n0.push_back(i);
  int ans = min(search(1, n0[0], 1, true), search(1, n0[1], 1, true));
  cout << ans << "\n";

  return 0;
}