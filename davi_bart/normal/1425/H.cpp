#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(((a==0)+(b==0)+(c==0)+(d==0))==3){
    if(a){
      if(a%2)cout<<"Ya Tidak Tidak Tidak\n";
      else cout<<"Tidak Tidak Tidak Ya\n";
    }
    if(b){
      if(b%2)cout<<"Tidak Ya Tidak Tidak\n";
      else cout<<"Tidak Tidak Ya Tidak\n";
    }
    if(c)cout<<"Tidak Tidak Ya Tidak\n";
    if(d)cout<<"Tidak Tidak Tidak Ya\n";
    return;
  }
  if((a+b)%2==0){
    if(a+d==0)cout<<"Tidak Tidak Ya Tidak\n";
    else if(b+c==0)cout<<"Tidak Tidak Tidak Ya\n";
    else cout<<"Tidak Tidak Ya Ya\n";
  }
  else{
    if(a+d==0)cout<<"Tidak Ya Tidak Tidak\n";
    else if(b+c==0)cout<<"Ya Tidak Tidak Tidak\n";
    else cout<<"Ya Ya Tidak Tidak\n";
  }
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  int T;
  cin>>T;
  while(T--)solve();
}