#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N;
string s;
int sol(int l,int r,char p){
  //cout<<l<<" "<<r<<" "<<p<<'\n';
  if(l==r)return s[l]!=p;
  int x=0,y=0;
  for(int i=l;i<=(l+r)/2;i++){
    if(s[i]!=p)x++;
  }
  for(int i=(l+r)/2+1;i<=r;i++){
    if(s[i]!=p)y++;
  }
  return min(sol(l,(l+r)/2,p+1)+y,sol((l+r)/2+1,r,p+1)+x);
}
void solve(){
  cin>>N>>s;
  cout<<sol(0,N-1,'a')<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}