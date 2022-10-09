#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 101010
unsigned llong s[maxn];
unsigned llong diff[maxn];
unsigned llong sumdiff[maxn];
int n;

unsigned llong solve(unsigned llong length) {
  unsigned llong pos = (unsigned llong)(upper_bound(diff, diff + n - 1, length) - diff);
  unsigned llong ans = sumdiff[pos] + (n - pos) * length;
  return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> s[i];
    sort(s, s + n);
    n = (int)(unique(s, s + n) - s);

    int q; cin >> q;

    if (n == 1) {
      while (q--) {
        unsigned llong l, r; cin >> l >> r;
        cout << (r - l + 1) << ' ';
      }
      return 0;
    }

    rep(i, n - 1) diff[i] = s[i + 1] - s[i];
    sort(diff, diff + n - 1);
    sumdiff[0] = 0;
    rep(i, n - 1) sumdiff[i + 1] = sumdiff[i] + diff[i];

    while (q--) {
      unsigned llong l, r; cin >> l >> r;
      cout << solve(r - l + 1) << ' ';
    }

    return 0;
}