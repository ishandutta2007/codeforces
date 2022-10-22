#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().tempo_since_epoch().count());
ll mod=998244353;
string a,b;
vector<ll> pot;
ll memo[3009][3009];
bool vis[3009][3009];

ll memo1[3009][3009];
bool vis1[3009][3009];
ll sol(ll l,ll r,ll p){
  if(l==0 && r==b.size()-1)return a.size()-p+1;
  if(r==b.size()-1){
    if(p==a.size())return 0;
    if(vis1[l][p])return memo1[l][p];
    vis1[l][p]=1;
    memo1[l][p]+=sol(l,r,p+1);
    if(b[l-1]==a[p])memo1[l][p]+=sol(l-1,r,p+1);
    return memo1[l][p]%=mod;
  }
  if(vis[l][r])return memo[l][r];
  vis[l][r]=1;
  if(l>0 && b[l-1]==a[p])memo[l][r]+=sol(l-1,r,p+1);
  if(r<(b.size()-1) && b[r+1]==a[p])memo[l][r]+=sol(l,r+1,p+1);
  return memo[l][r]%=mod;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("output.txt","w",stdout);
		pot.push_back(1);
		for(int i=1;i<3010;i++){
      pot.push_back(pot[i-1]*2%mod);
		}
    cin>>a>>b;
    ll tot=0;
    for(int i=0;i<b.size();i++){
      if(a[0]==b[i])tot+=2*sol(i,i,1);
      tot%=mod;
    }
    for(int i=1;i<a.size();i++){
      if(a[i]==b.back())tot+=sol(b.size()-1,b.size()-1,i+1)*pot[i];
      tot%=mod;
    }
    cout<<tot;
    return 0;
}