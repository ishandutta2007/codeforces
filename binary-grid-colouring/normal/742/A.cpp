#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const ll INF =2e15;
int a[maxn],b[maxn];
int vis[maxn];
int ans[maxn];
std::map<int, int> mp;
ll qpower(ll a,ll b,ll md)
{
  ll ans = 1;
  while(b>0) {
    if(b&1) ans = ans * a % md;
    b>>=1;
    a = a * a  % md;
  }
  return ans;
}
int main(int argc, char const *argv[]) {

  int n;
  std::cin >> n;
  ll ans = qpower(1378,n,10);
  std::cout << ans << '\n';
  return 0;
}