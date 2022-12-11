#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

/*
std::size_t operator()(std::vector<uint32_t> const& vec) const {
  std::size_t seed = vec.size();
  for(auto& i : vec) {
    seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }
  return seed;
}
*/

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}
vvi G;

bool comp(pi a, pi b) {
  if (a.first != b.first) return a.first < b.first;
  for (int i = 0; i < a.first; ++i) {
    if (G[a.second][i] < G[b.second][i]) return true;
    if (G[a.second][i] > G[b.second][i]) return false;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    G = vvi(n);
    vector<ll> val(n);
    for (int i = 0; i < n; ++i) {
      cin >> val[i];
    }
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      G[y].push_back(x);
    }
    vpi D(n);
    for (int i = 0; i < n; ++i) {
      D[i] = pi(G[i].size(), i);
      sort(G[i].begin(), G[i].end());
    }
    sort(D.begin(), D.end(), comp);
    ll res = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
      if (!D[i].first) continue;
      if (i and G[D[i].second] != G[D[i-1].second]) {
        res = gcd(res, sum);
        sum = val[D[i].second];
      }
      else sum += val[D[i].second];
    }
    res = gcd(res, sum);
    cout << res << '\n';
  }
}