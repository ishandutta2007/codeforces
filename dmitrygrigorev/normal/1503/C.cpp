#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}



int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector<pair<int, int> > v(n);
  for (auto &x : v) cin >> x.x >> x.y;

  sort(all(v));

  ll ans = 0;
  for (auto x : v) ans += x.y;

  set<pair<int, int> > stop;
  multiset<ll> open;

  ll opt = 1e18;

  stop.insert(mp(v[0].x + v[0].y, 0));
  open.insert(0);

  vector<ll> dp(n, 0);

  for (int i = 1; i < n; ++i) {
    while (stop.size()) {
      auto it = stop.begin();
      int T = (*it).x;

      if (T >= v[i].x) break;
      int index = (*it).y;

      stop.erase(it);
      open.erase(open.find(dp[index]));
      opt = min(opt, dp[index] - (v[index].x + v[index].y));
     // cout << opt << " " << i < " " << index << endl;
    }

    ll cur = opt + v[i].x;
    if (open.size()) {
      auto it = open.begin();
      cur = min(cur, (*it));
    }

    dp[i] = cur;
    stop.insert(mp(v[i].x + v[i].y, i));
    open.insert(cur);

  }

  cout << ans + dp.back();



}