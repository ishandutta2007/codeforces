#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;
int a[maxn],b[maxn];
int vis[maxn];
int ans[maxn];
std::map<int, int> mp;
ll lcm(ll a, ll b)
{
  return a / __gcd(a,b) * b;
}
int c[maxn];
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  ll k;
  std::cin >> k;
  ll g = 1;
  for(int i=1;i<=n;i++) {
    //std::cin >> c[i];
    scanf("%d",&c[i]);
    g = lcm(g,c[i]);
    g = __gcd(g,k);
    if(g==k) {
      std::cout << "Yes" << '\n';
      return 0;
    }
  }
  std::cout << "No" << '\n';
  return 0;
}