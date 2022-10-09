#include <bits/stdc++.h>
using namespace std;

#define llong long long/*{{{*/
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i, n) for (int i = -1; ++ i < n; )
#define rep1(i, n) for (int i = 0; i ++ < n; )
#define ii pair<int, int>

template<typename t> ostream& operator<<(ostream& cout, const vector<t>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<typename u, typename v> ostream& operator<< (ostream& cout, const pair<u, v> a) {
  return cout << "(" << a.first << ", " << a.second << ")";
}/*}}}*/

#define maxval 15000100
#define maxn 301010

map<int, int> cnt;
int n;
int a[maxn];
bitset<maxval> notprime, hasa;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i];
  int gcd = a[0];
  int ce = 1;
  rep1(i, n - 1) {
    gcd = __gcd(gcd, a[i]);
    ce += a[i] == a[0];
  }
  if (ce == n) {
    cout << -1;
    return 0;
  }

  rep(i, n) {
    a[i] /= gcd;
    cnt[a[i]] ++;
    hasa[a[i]] = 1;
  }

  int ans = n;
  for (int i = 2; i < maxval; ++i) {
    if (notprime[i]) continue;
    int cur = 0;
    if (hasa[i]) {
      cur += cnt[i];
      cnt.erase(i);
      hasa[i] = 0;
    }

    for (int f = (int)min((llong)i * i, (llong)maxval); f < maxval; f += i) {
      notprime[f] = 1;
      if (!hasa[f]) continue;
      int t = f;
      while (t % i == 0) t /= i;
      cur += cnt[f];
      cnt[t] += cnt[f];
      cnt.erase(f);
      hasa[f] = 0;
      hasa[t] = 1;
    }
    ans = min(ans, n - cur);
  }

  cout << ans;

  return 0;
}