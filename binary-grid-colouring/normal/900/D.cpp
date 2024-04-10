#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;
#define ll long long

std::map<int, int> mp;
ll qpower(ll a,ll b,ll mod)
{
    ll ans = 1;
    while(b>0)
    {
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
ll solve(int x)
{
  if(x==1)return 1;
  if (mp.count(x)) {
    return mp[x];
  }
  mp[x] = qpower(2,x-1,mod);
  for(int i=2;i*i<=x;i++) {
    if(x%i==0){
      mp[x] = (mp[x] - solve(x/i) + mod) % mod;
      if(i!=x/i){
        mp[x] = (mp[x] - solve(i) + mod) % mod;
      }
    }
  }
  mp[x] = (mp[x] - solve(1) + mod) % mod;
  return mp[x];
}
int x,y;
int main(int argc, char const *argv[]) {
  std::cin >> x >> y;
  if(y%x>=1){
    std::cout << "0" << '\n';
    return 0;
  }
  std::cout << solve(y/x) << '\n';
  return 0;
}