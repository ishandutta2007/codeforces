#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod=1e9+7;
int pot(int a,int b){
  if(b==0)return 1;
  int x=pot(a,b/2);
  if(b%2)return x*x%mod*a%mod;
  return x*x%mod;
}
vector<int> v;
int N;
int memo[300010];
int ma[300010],mi[300010];
vector<int> altri[300010];
int sol(int pos){
  if(pos==N-1)return 0;
  if(pos>=N)return 1e9;
  if(memo[pos])return memo[pos];
  int ans=min({sol(ma[pos]),sol(mi[pos]),sol(pos+1)})+1;
  for(int x:altri[pos]){
    ans=min(ans,sol(x)+1);
  }
  return memo[pos]=ans;
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>N;
  v.resize(N);
  for(int &i:v)cin>>i;
  stack<pair<int,int> >k;
  k.push({2e9,N+10});
  for(int i=N-1;i>=0;i--){
    while(v[i]>k.top().fi){
      k.pop();
    }
    ma[i]=k.top().se;
    k.push({v[i],i});
  }
  while(k.size())k.pop();
  k.push({-1,N+10});
  for(int i=N-1;i>=0;i--){
    while(v[i]<k.top().fi){
      k.pop();
    }
    mi[i]=k.top().se;
    k.push({v[i],i});
  }


  while(k.size())k.pop();
  k.push({2e9,-1});
  for(int i=0;i<N;i++){
    while(v[i]>k.top().fi){
      k.pop();
    }
    if(k.top().se>=0)altri[k.top().se].push_back(i);
    k.push({v[i],i});
  }
  while(k.size())k.pop();
  k.push({-1,-1});
  for(int i=0;i<N;i++){
    while(v[i]<k.top().fi){
      k.pop();
    }
    if(k.top().se>=0)altri[k.top().se].push_back(i);
    k.push({v[i],i});
  }
  cout<<sol(0);
}