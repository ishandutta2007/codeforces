#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int N = 300300;
vector<int> adj[N];
vector<int> ord;
int seen[N], past[N];
vector<int> match[N];

void dfs(int u, int p) {
  if (past[u]) {
    int mx = u, mn = u;
    for (int j=ord.size()-1; j>=0 && ord[j] != u; --j) {
      mx = max(mx, ord[j]);
      mn = min(mn, ord[j]);
    }
    match[mn].push_back(mx);
    assert(mn < mx);
    return;
  }
  if (seen[u]) {
    return;
  }
  seen[u] = 1;
  past[u] = 1;
  ord.push_back(u);
  for (auto& v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  past[u] = 0;
  ord.pop_back();
}

ll csum(ll x) {
  return x*(x+1)/2;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i=1; i<=m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> lim(n+1);
  for (int i=1; i<=n; ++i) {
    if (!seen[i]) {
      dfs(i, 0);
    }
  }

  map<int, int> endpoints;
  {
    int j = 0;
    for (int i=1; i<=n; ++i) 
    {
      while (j<n && (endpoints.empty() || j+1 < endpoints.begin()->first)) {
        ++j;
        for (auto& v : match[j]) {
          //cerr << " : " << v << endl;
          endpoints[v]++;
        }
      }
      lim[i] = j;
      //cerr << " LIM " << i << " : " << lim[i] << endl;
      for (auto& v : match[i]) {
        if (--endpoints[v] == 0) {
          endpoints.erase(v);
        }
      }
    }
  }

  /*
  n = 299299;
  lim = vector<int>(n+1);
  for (int i=1; i<=n; ++i) {
    lim[i] = min(i*3, n+1);
  }
  */

  vector<ll> sum(n+1);
  for (int i=1; i<=n; ++i) {
    sum[i] = sum[i-1]+lim[i];
  }

  int q;
  cin >> q;
  for (int i=1; i<=q; ++i) {
    int a, b;
    ll res = 0;
    cin >> a >> b;
    auto it = upper_bound(lim.begin(), lim.end(), b);
    int ind = it-lim.begin();
    ind = max(a, min(ind, b+1));
    res += csum(b+1-ind);
    res += sum[ind-1]-sum[a-1] - csum(ind-2) + csum(a-2);
    //cerr << " x " << csum(b+1-ind) << " (" << b+1-ind << ")" << endl;
    //cerr << " : " << sum[ind-1] << " - " << sum[a-1] << " - " << csum(ind-1) << " + " << csum(a-1) << endl;
    cout << res << "\n";
  }
  return 0;
}