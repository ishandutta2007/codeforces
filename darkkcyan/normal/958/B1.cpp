#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

int n;
int cnt[1010] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n - 1) {
    int u, v; cin >> u >> v;
    ++cnt[u], ++cnt[v];
  }
  int ans = 0;
  rep1(i, n) ans += cnt[i] == 1;
  cout << ans;

  return 0;
}