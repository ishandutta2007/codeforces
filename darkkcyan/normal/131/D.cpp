#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 101010
int n;
vector<int> gr[maxn];
vector<int> st;
int deg[maxn];
int ans[maxn] = {0};

void dfs(int u)  {
  for (auto v: gr[u]) {
    if (ans[v] != -1) continue;
    ans[v] = ans[u] + 1;
    dfs(v);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) {
    int u, v; cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  
  rep1(i, n) {
    if ((deg[i] = len(gr[i])) == 1) st.push_back(i);
  }
  
  while (len(st)) {
    int u = st.back(); st.pop_back();
    ans[u] = -1;
    for (auto v: gr[u]) {
      if (ans[v] == -1) continue;
      if (--deg[v] == 1) st.push_back(v);
    }
  }
  rep1(i, n) {
    if (ans[i] == 0) dfs(i);
  }
  rep1(i, n) cout << ans[i] << ' ';
  
  return 0;
}