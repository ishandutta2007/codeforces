#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 1010
int n, k;
int cost[maxn];
vector<int> a[3];
vector<int> ans[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  rep1(i, n) {
    int t; cin >> cost[i] >> t;
    a[t].push_back(i);
  }
  sort(a[1].begin(), a[1].end(), [](int u, int v) { return cost[u] < cost[v]; });
  llong minc = 0;
  if (len(a[1]) < k) {
    int i = k;
    while (len(a[1])) {
      ans[--i].push_back(a[1].back());
      minc += cost[a[1].back()];
      a[1].pop_back();
    }
    rep(f, len(a[2])) {
      ans[f % i].push_back(a[2][f]);
      minc += cost[a[2][f]] * 2;
    }
  } else {
    rep(i, k - 1) {
      ans[i].push_back(a[1].back());
      minc += cost[a[1].back()];
      a[1].pop_back();
    }
    int mi = INT_MAX;
    for (auto i: a[1]) {
      ans[k - 1].push_back(i);
      minc += 2 * cost[i];
      mi = min(mi, cost[i]);
    }
    for (auto i: a[2]) {
      ans[k - 1].push_back(i);
      minc += 2 * cost[i];
      mi = min(mi, cost[i]);
    }
    minc -= mi;
  }
  cout << minc / 2 << '.' << 5 * (minc & 1) << '\n';
  rep(i, k) {
    cout << len(ans[i]) << ' ';
    for (auto f: ans[i]) cout << f << ' ' ;
    cout << '\n';
  }
  
  return 0;
}