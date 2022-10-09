#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 2010
vector<int> gr[maxn];

int dfs(int u) {
  int ans = 0;
  for (auto v: gr[u]) ans = max(ans, dfs(v));
  return ans + 1;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  rep1(i, n) {
    int p; cin >> p;
    if (p == -1) p = 0;
    gr[p].push_back(i);
  }
  cout << dfs(0) - 1;
  
  return 0;
}