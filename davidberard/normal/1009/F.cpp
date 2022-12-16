#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct State {
  vector<int> d;
  set<pii> st;
  void add(int dep, int cnt) {
    assert(dep < d.size());
    st.erase(pii(d[d.size()-1-dep], d.size()-1-dep));
    d[d.size()-1-dep] += cnt;
    st.insert(pii(d[d.size()-1-dep], d.size()-1-dep));
  }
};

const int N = 1001000;
State f[N];
int ans[N];

vector<int> adj[N];

int dfs(int u, int p) {
  pii best(-1, -1);
  for (auto& v : adj[u]) {
    if (p == v) continue;
    int res = dfs(v, u);
    best = max(best, pii(res, v));
  }
  if (best.second != -1) {
    swap(f[u], f[best.second]);
    f[u].d.push_back(1);
    f[u].st.insert(pii(1, f[u].d.size()-1));
  } else {
    f[u].d.push_back(1);
    f[u].st.insert(pii(1, 0));
  }
  //cerr << " U " << u << endl;
  for (auto& v : adj[u]) {
    if (p == v) continue;
    if (v == best.second) continue;

    //cerr << "   V = " << v << endl;
    for (int i=0; i<f[v].d.size(); ++i) {
      f[u].add(f[v].d.size()-i, f[v].d[i]);
    }
  }
  int ind = f[u].st.rbegin()->second;
  ans[u] = f[u].d.size() - ind - 1;
  return f[u].d.size();
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i=1; i<n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  for (int i=1; i<=n; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}