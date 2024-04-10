#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

#define maxn 301010
int n;
int sum[maxn] = {0};
llong cnt[maxn][2] = {0};

int gets(int l, int r) {
  return sum[r] - sum[l - 1];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  //n = 4;
  rep1(i, n) {
    llong u; cin >> u;
    //u = i & 1 ? (unsigned llong) -2 : 1;
    sum[i] = sum[i - 1] + __builtin_popcountll(u);
  }
  

  for (int i = n + 1; --i; ) {
    cnt[i][0] = cnt[i + 1][0];
    cnt[i][1] = cnt[i + 1][1];
    cnt[i][sum[i] & 1]++;
  }
  llong ans = 0;
  rep1(i, n) {
    int maxv = 0;
    rep(f, 128) {
      if (i + f > n) break;
      maxv = max(maxv, gets(i + f, i + f));
      int rs = gets(i, i + f);
      if (maxv * 2 <= rs and (~rs & 1)) ++ans;
    }
    if (i + 128 > n) continue;
    ans += cnt[i + 128][sum[i - 1] & 1];
  }
  cout << ans;

  return 0;
}