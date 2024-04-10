#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int c(int &a,int &b){
  int k=min(a,b);
  a-=k;
  b-=k;
  return k;
}
void solve(){
  int N;
  cin>>N;
  vector<int> a(3),b(3);
  cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2];
  vector<pair<int,int> > k={{0,2},{1,0},{2,1},{0,0},{1,1},{2,2}};
  int mi=1e9;
  for(int i=0;i<720;i++){
    vector<int> aa=a,bb=b;
    for(int j=0;j<6;j++)c(aa[k[j].fi],bb[k[j].se]);
    mi=min(mi,aa[0]+aa[1]+aa[2]);
    next_permutation(k.begin(),k.end());
  }

  cout<<mi<<" "<<c(a[0],b[1])+c(a[1],b[2])+c(a[2],b[0]);
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  int T=1;
  //cin>>T;
  while(T--)solve();
}