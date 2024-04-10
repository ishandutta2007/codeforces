#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef long double ld;

int n;
ll a[2005];
ll win_diff[10000]={0};
ll win_diff_sum[10000]={0};

//ways to get a sum smaller than sm during first 2 matches
ll ways(int sm) {
  ll ans = 0;
  for(int i = 1; i <= 5000; ++i) {
    if(sm - i - 1 <= 0) break;
    if(win_diff[i] == 0) continue;
    ans += win_diff[i]*win_diff_sum[sm-i-1];
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a+n);
  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      ++win_diff[a[j]-a[i]];
    }
  }
  for(int i = 1; i <= 5000; ++i) {
    win_diff_sum[i] = win_diff[i] + win_diff_sum[i-1];
  }

  ll num = 0;
  for(int i = 1; i <= 5000; ++i) {
    if(win_diff[i] == 0) continue;
    num += win_diff[i]*ways(i);
  }

  ll ttl = (n*(n-1))/2;
  ttl = ttl*ttl*ttl;
  ld ans = ld(num) / ld(ttl);
  cout << setprecision(15) << fixed;
  cout << ans << endl;
  return 0;
}