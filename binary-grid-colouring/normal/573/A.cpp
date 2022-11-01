#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;


std::map<int, int> mp;


ll lcm(ll a, ll b)
{
  return 1LL*a / (1LL*__gcd(a,b)) * b;
}
ll a[maxn];
ll l;
bool ISOK(ll x)
{
  while(x%3==0) {
    x/=3;
  }
  if(x==1)return 1;
  else return 0;
}
bool fuck(ll x)
{
  while(x%2==0) {
    x/=2;
  }
  while(x%3==0) {
    x/=3;
  }
  if(x==1)return 1;
  else return 0;
}
bool check(ll x){
  if(x==l)return 1;
  if(l%x!=0)return 0;
  ll tmp = l / x;
   // std::cout << "tmp=" << tmp << '\n';
  if((tmp&(tmp-1))==0 || ISOK(tmp) || fuck(tmp)) return 1;
  return 0;
}
int main(int argc, char const *argv[]) {

  ll n ;
  std::cin >> n;
  l = 1;
  for(int i=0;i<n;i++) {
    std::cin >> a[i];
    l = lcm(l,a[i]);
  }
  // std::cout << "l =" << l << '\n';
  for(int i=0;i<n;i++) {
    if(check(a[i])==0) {
      std::cout << "No" << '\n';return 0;
    }
  }
  std::cout << "Yes" << '\n';
  return 0;
}