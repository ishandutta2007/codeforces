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
  string v;
  cin>>N>>v;
  vector<int> p;
  for(int i=0;i<N;i++){
    if(i==0 || v[i]!=v[i-1])p.push_back(1);
    else p.back()++;
  }
  int c=0;
  int pos=0;
  while(1){
    c++;
    for(int i=pos;i<p.size();i++){
      if(p[i]>1){
        p[i]--;
        pos=i;
        break;
      }
      if(i==p.size()-1){
        p.pop_back();
        pos=p.size()-1;
      }
    }
    p[c-1]=0;
    if(c>=p.size())break;
  }
  cout<<c<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  int T;
  cin>>T;
  while(T--)solve();
}