#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  string a;
  cin>>a;
  int pos=-1;
  bool k=0;
  string sol="";
  for(int i=a.size()-1;i>=0;i--){
    sol+=a[i];
    if(a[i]=='0')k=1;
    else{
      if(k){
        sol.pop_back();
        while(sol.size() && sol.back()=='0')sol.pop_back();
        sol.push_back('0');
      }
    }
  }
  reverse(sol.begin(),sol.end());
  cout<<sol<<'\n';
  return;
  /*if(pos==-1){
    cout<<a<<'\n';
    return;
  }
  int k=1e6;
  for(int i=a.size()-1;i>=0;i--){
    if(a[i]=='0'){
      k=i;
      break;
    }
  }
  if(pos>k || k==1e6){
    cout<<a<<'\n';
    return;
  }
  for(int i=0;i<pos;i++)cout<<a[i];
  cout<<"01"<<'\n';*/

}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
}