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
#define maxk 22
#define inf ((llong)1e15)
int n, k;
int a[maxn];
llong dp[2][maxn];

int cnt[maxn];
llong curcost, cl, cr;
llong move(int l, int r) {
  while (cl > l) curcost += cnt[a[--cl]]++;
  while (cr < r) curcost += cnt[a[++cr]]++;
  while (cl < l) curcost -= --cnt[a[cl++]];
  while (cr > r) curcost -= --cnt[a[cr--]];
  // clog << "cost " << cl << ' ' << cr << ' ' << curcost << endl;
  return curcost;
}

void compdp(int ck, int jl, int jr, int kl, int kr) {
  if (jl > jr) return;
  int mid = jl + (jr - jl) / 2;
  
  int bk = -1;
  dp[ck][mid] = inf;
  int mi = min(mid, kr);
  for (int i = mi; i >= kl; --i) {
    // clog << "cost " << cl << ' ' << cr << ' ' << curcost << endl;
    llong t = dp[ck ^ 1][i] + move(i + 1, mid);
    if (dp[ck][mid] > t) {
      bk = i;
      dp[ck][mid] = t;
    }
  }
  // clog << mid << ' ' << bk << endl;
  compdp(ck, jl, mid - 1, kl, bk);
  compdp(ck, mid + 1, jr, bk, kr);
}

llong solve() {
  curcost = cl = cr = 0;
  memset(cnt, 0, sizeof(cnt));
  cnt[a[0]] = 1;
  rep(i, n) {
    dp[1][i] = move(0, i);
    // clog << 1 << ' ' << i << ' ' << dp[1][i] << endl;
  }
  for (int i = 2; i <= k; ++i) {
    curcost = cl = cr = 0;
    memset(cnt, 0, sizeof(cnt));
    cnt[a[0]] = 1;
    compdp(i & 1, 0, n - 1, 0, n - 1);
    // rep(f, n)
      // clog << i << ' ' << f << ' ' << dp[i & 1][f] << endl;
  }
  return dp[k & 1][n - 1];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  rep(i, n) cin >> a[i];
  // rep(i, n) clog << a[i] << ' '; clog << endl;
  cout << solve();
  
  return 0;
}