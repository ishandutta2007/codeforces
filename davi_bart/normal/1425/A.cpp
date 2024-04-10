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
  int N;
  cin>>N;
  int a=0,b=0;
  while(N){
    if(N%2 || ((N/2)%2==0 && N>4)){
      N--;
      a++;
    }else{
      N/=2;
      a+=N;
    }
    if(N==0)break;
    if(N%2 || ((N/2)%2==0 && N>4)){
      N--;
    }else{
      N/=2;
    }
  }
  cout<<a<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  int T;
  cin>>T;
  while(T--)solve();
}