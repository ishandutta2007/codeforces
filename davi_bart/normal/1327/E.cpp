#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll N,mod=998244353;
vector<ll> pot;
ll sol(ll g){
  if(g==N)return 10;
  ll tot=0;
  tot+=2*10*9*pot[N-g-1];
  if(g==N-1)return tot%mod;
  tot+=(N-g-1)*9*9*10*pot[N-g-2];
  return tot%mod;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    pot.push_back(1);
    for(ll i=0;i<200010;i++)pot.push_back((pot[i]*10)%mod);
    for(ll i=1;i<=N;i++){
      cout<<sol(i)<<" ";
    }
    return 0;
}