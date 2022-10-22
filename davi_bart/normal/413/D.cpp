#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N,K;
vector<int> v;
int memo[2009][2][2500];
bool vis[2009][2][2500];
const int mod=1e9+7;
vector<int> pot={1};
int vuoti[3000];
int sol(int pos,int last,int sum){
  if(sum>=(1<<K))return pot[vuoti[pos]];
  sum=min(sum,(int)2200);
  if(pos==N && sum>=(1<<K))return 1;
  if(pos==N)return 0;
  if(vis[pos][last][sum])return memo[pos][last][sum];
  vis[pos][last][sum]=1;
  if(v[pos]){
    if(v[pos]==4 && last==0)return memo[pos][last][sum]=sol(pos+1,1,4);
    if(v[pos]==2 && last==1)return memo[pos][last][sum]=sol(pos+1,0,sum+2);
    if(v[pos]==4 && last==1)return memo[pos][last][sum]=sol(pos+1,1,sum+4);
    if(v[pos]==2 && last==0)return memo[pos][last][sum]=sol(pos+1,1,sum+2);
  }
  if(last==0)return memo[pos][last][sum]=(sol(pos+1,1,sum+2)+sol(pos+1,1,4))%mod;
  return memo[pos][last][sum]=(sol(pos+1,0,sum+2)+sol(pos+1,1,sum+4))%mod;
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=0;i<3000;i++)pot.pb(pot.back()*2%mod);
  cin>>N>>K;
  int ans=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    v.pb(a);
  }
  for(int i=N-1;i>=0;i--){
    vuoti[i]=vuoti[i+1]+(v[i]==0);
  }
  cout<<sol(0,1,0);
}