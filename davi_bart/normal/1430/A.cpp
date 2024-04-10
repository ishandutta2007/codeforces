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
  if(N<3 || N==4){
    cout<<-1<<'\n';
    return;
  }
  if(N%3==0)cout<<N/3<<" 0 0\n";
  if(N%3==1)cout<<N/3-2<<" 0 1\n";
  if(N%3==2)cout<<N/3-1<<" 1 0\n";
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ifstream cin("simboli.txt");
  //ofstream cout("html.txt");
  int T;
  cin>>T;
  while(T--)solve();
}