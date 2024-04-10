#include <bits/stdc++.h>
#define int long long 
 
using namespace std;
 
int Solve(vector<int>& v, int x) {
  int n = v.size();
 
  vector<int> divs;
  for (int d = 1; d * d <= x; ++d) {
    if (x % d == 0) {
      divs.push_back(d);
      if (d != x / d)
        divs.push_back(x / d);
    }
  }
  sort(divs.begin(), divs.end());
  vector<int> cnt(divs.size(), 0);
  for (int i = 0; i < n; ++i) {
    int now = __gcd(v[i], x);
    int pos = lower_bound(divs.begin(), divs.end(), now) - divs.begin();
    cnt[pos] += 1;
  }
  
  int best = 1;
  for (int i = 0; i < (int)divs.size(); ++i) {
    int now = 0;
    for (int j = 0; j < (int)divs.size(); ++j) {
      if (divs[j] % divs[i] == 0)
        now += cnt[j];
    }
    if (now * 2 >= n)
      best = max(best, divs[i]);
  }
  return best;
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  srand(time(0));
  
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];
  random_shuffle(v.begin(), v.end());
 
  int ans = 1;
  int lim = (n <= 100 ? 1e9 : 8);
  for (int i = 0; i < n; ++i) {
    ans = max(ans, Solve(v, v[i]));
    if (i > lim) break;
  }
  cout << ans << endl;
 
  return 0;
}