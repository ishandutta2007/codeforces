#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 111
#define maxval 100100
int n, m;
int a[maxn];
long double cnt[maxval];
long double presum[maxval];

void compPreSum() {
    presum[0] = 0;
    rep(i, n * m)
      presum[i + 1] = presum[i] + cnt[i];
}

// [l; r)
long double getSum(int l, int r) {
  l = max(l, 0);
  r = max(r, 0);
  return presum[r] - presum[l];
}


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if (m == 1) {
      cout << 1;
      return 0;
    }
    int s = 0;
    rep(i, n) {
      cin >> a[i];
      s += a[i];
    }

    cnt[0] = 1;
    rep(comp, n) {
      compPreSum();
      for (int i = n * m + 1; i--;) {
        cnt[i] = getSum(i - m, i);
        if (i >= a[comp]) cnt[i] -= cnt[i - a[comp]];
        cnt[i] /= m - 1;
      }
    }
    compPreSum();
    cout << fixed << setprecision(12) << getSum(0, s) * (m - 1) + 1;

    return 0;
}