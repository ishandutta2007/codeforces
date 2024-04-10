#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;

int vis[maxn];
int ans[maxn];
std::map<int, int> mp;
int red[maxn],blue[maxn];
int both[maxn];
ll lcm( ll a, ll b){
  return a / __gcd(a,b) * b;
}
int main(int argc, char const *argv[]) {
  ll n,a,b,p,q;

  std::cin >> n >> a >> b >> p >> q;
  ll ans = (n / a) * p;
  ans += (n / b) * q;
  ans -= min(p,q) * (n  / lcm(a,b));
  std::cout << ans << '\n';
  return 0;
}