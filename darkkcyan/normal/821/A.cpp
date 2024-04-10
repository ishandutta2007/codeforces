#include<bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )

#define maxn 55
int n;
int a[maxn][maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  rep(i, n) rep(f, n) cin >> a[i][f];

  rep(i, n) rep(f, n) {
    if (a[i][f] == 1) continue;
    bool ans = 0;
    rep(g, n) rep(h, n) {
      if (a[i][g] + a[h][f] == a[i][f]) ans = 1;
    }
    if (!ans) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";

  return 0;
}