#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

const string f0 ="What are you doing at the end of the world? Are you busy? Will you save us?";
const string fn0 = "What are you doing while sending \"";
const string fn1 = "\"? Are you busy? Will you send \"";
const string fn2 = "\"?";

#define maxn 101010
llong dp[maxn];

char findchar(int n, llong k) {
  if (k >= dp[n]) return '.';
  if (n == 0) return f0[k];
  if (k < len(fn0)) return fn0[k];
  k -= len(fn0);
  if (k < dp[n - 1]) return findchar(n - 1, k);
  k -= dp[n - 1];
  if (k < len(fn1)) return fn1[k];
  k -= len(fn1);
  if (k < dp[n - 1]) return findchar(n - 1, k);
  k -= dp[n - 1];
  return fn2[k];
}

const int ov = 56;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  dp[0] = len(f0);
  rep1(i, ov - 1) {
    dp[i] = (llong)len(fn0) + (llong)len(fn1) + (llong)len(fn2) + 2 * dp[i - 1];
  }
  for (int i = ov; i < maxn; ++i) dp[i] = LLONG_MAX;
  int q; cin >> q;
  while (q--) {
    llong n, k; cin >> n >> k;
    cout << findchar((int)n, k - 1);
  }

  return 0;
}