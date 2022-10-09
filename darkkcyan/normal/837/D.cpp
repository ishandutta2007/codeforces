#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; ++i <= n; )

#define maxn 222
#define maxd 5555
int n, k;
ii a[maxn];

int b[maxn][maxd];
vector<int> wl[maxn];

void add(int i, int u, int v) {
  if (b[i][u] == -1) wl[i].push_back(u);
  b[i][u] = max(b[i][u], v);
  //clog << i << ' ' << u << ' ' << v << endl;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  rep(i, n) {
    llong x; cin >> x;
    while (x % 2 == 0) {
      x /= 2;
      ++a[i].yy;
    }
    while (x % 5 == 0) {
      x /= 5;
      ++a[i].xx;
    }
  }

  wl[0].push_back(0);
  memset(b, -1, sizeof(b));
  b[0][0] = 0;
  rep(i, n) {
    //clog << i << endl;
    for (int f = k - 1; f >= 0; --f) {
      for (auto x: wl[f]) {
        add(f + 1, x + a[i].xx, b[f][x] + a[i].yy);
      }
    }
  }

  int ans = 0;
  rep(i, maxd) {
    ans = max(ans, min(i, b[k][i]));
    //clog << i.xx << ' ' << i.yy << endl;
  }
  cout << ans;

  return 0;
}