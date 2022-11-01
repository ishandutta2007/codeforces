#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 123;
ll n , L;
std::vector<pair<int,int> > v;
ll a[maxn];
int t[maxn];
int res[maxn];
int tmp[maxn];
int ans,last;
int main(int argc, char const *argv[]) {
 ll ans = 1000000000000000000LL;
 std::cin >> n >> L;
 for(int i=0;i<n;i++) {
   std::cin >> a[i];
 }
 for (size_t i = 1; i < n; i++) {
   /* code */
   a[i] = min(2*a[i-1],a[i]);
 }
 for(int i=n-2;i>=0;--i) {
   a[i] = min(a[i+1],a[i]);
 }
 ll tmp = 0;
 ll md = 0;
 ll lemonade  = L;
 for(int i=n-1;i>=0;--i) {
   tmp += a[i] * (lemonade / (1 << i));
  lemonade = lemonade % (1<<i);
  if(lemonade > 0) {
    md = a[i];
  }
  else md = 0;
  ans = min(tmp+md,ans);
 }
 std::cout << ans << '\n';
 // std::cout << '\n';
 cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}