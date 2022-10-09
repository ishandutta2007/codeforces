#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 501010
#define maxval 2010101
int n;
llong x, y;
llong s[maxval] = {0};
int cnt[maxval] = {0};
bool notprime[maxval];

template<class T> 
T getsum(T arr[], int l, int r) {
  if (l == 0) return arr[r];
  return arr[r] - arr[l - 1];
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> x >> y;
    rep(i, n) {
      int a; cin >> a;
      s[a] += a;
      cnt[a] ++;
    }
    rep1(i, maxval - 1) {
      s[i] += s[i - 1];
      cnt[i] += cnt[i - 1];
    }

    llong ans = LLONG_MAX;
    for (int i = 2; i < maxval; ++i) {
      if (notprime[i]) continue;
      llong curans = 0;
      for (int upper = i; upper < maxval; upper += i) {
        notprime[upper] = 1;
        int lower = upper - (int)min((llong)i - 1, x / y);
        curans += y * ((llong)getsum(cnt, lower, upper) * upper - getsum(s, lower, upper));
        curans += x * getsum(cnt, upper - i + 1, lower - 1);
      }
      // clog << i << ' ' << curans << endl;
      ans = min(ans, curans);
    }

    cout << ans;
    

    return 0;
}