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
int prova(int k,vector<string>v,int stampa){
  int N=v.size();
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]=='X' && (i+j)%3==k)v[i][j]='O';
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]=='O'){
        v[i][j]='X';
        bool ok=1;
        for(int a=max((ll)0,i-3);a<min(N-2,i+3);a++){
          if(v[a][j]=='X' && v[a+1][j]=='X' && v[a+2][j]=='X')ok=0;
        }
        for(int a=max((ll)0,j-3);a<min(N-2,j+3);a++){
          if(v[i][a]=='X' && v[i][a+1]=='X' && v[i][a+2]=='X')ok=0;
        }
        if(ok==0)v[i][j]='O';
      }
    }
  }
  if(stampa)for(auto i:v)cout<<i<<'\n';
  int t=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(v[i][j]=='O')t++;
    }
  }
  return t;
}
void solve(){
  int N;
  cin>>N;
  vector<string> v(N);
  for(auto &i:v)cin>>i;
  int a=prova(0,v,0),b=prova(1,v,0),c=prova(2,v,0);
  if(a<=b && a<=c){
    prova(0,v,1);
    return;
  }
  if(b<=c)prova(1,v,1);
  else prova(2,v,1);

}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}