#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef ll llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;


vi D0, D1;
vvpi G;

bool comp(pi a, pi b) {
  return a.second - a.first > b.second - b.first;
}

void dfs(int x, int k, int p = -1) {
  vpi F;
  for (auto it : G[x]) {
    int y = it.first;
    if (y == p) continue;
    dfs(y, k, x);
    F.push_back(pi(D0[y], it.second + D1[y])); 
  }
  sort(F.begin(), F.end(), comp);
  for (int i = 0; i < (int)F.size(); ++i) {
    if (i < k-1 and F[i].second > F[i].first) D1[x] += F[i].second;
    else D1[x] += F[i].first;
    if (i < k and F[i].second > F[i].first) D0[x] += F[i].second;
    else D0[x] += F[i].first;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >>q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    G = vvpi(n);
    D0 = D1 = vi(n,0);
    for (int i = 0; i < n-1; ++i) {
      int x, y, k;
      cin >> x >> y >> k;
      --x; --y;
      G[x].push_back(pi(y,k));
      G[y].push_back(pi(x,k));
    }
    dfs(0,k);
    cout << D0[0] << '\n';
  }

}