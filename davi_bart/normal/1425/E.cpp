#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  int N,K;
  cin>>N>>K;
  vector<int> a(N),d(N);
  for(int &i:a)cin>>i;
  for(int &i:d)cin>>i;
  int x=d[N-1];
  int tot=0;
  for(int i=0;i<N;i++){
    tot+=a[i];
  }
  if(K==0){
    int ma=0;
    tot=0;
    for(int i=N-1;i>=0;i--){
      tot+=a[i];
      ma=max(ma,tot-d[i]);
    }
    cout<<ma;
    return 0;
  }
  if(K>=2){
    d[N-1]=1e8;
    cout<<max({(ll)0,tot-*min_element(d.begin(),d.end()),a[N-1]-x});
    return 0;
  }
  int ma=0;
  for(int i=0;i<N-1;i++){
    ma=max(ma,tot-d[i]-d[i+1]);
  }
  d[N-1]=1e8;
  ma=max({ma,tot-a[N-1]-*min_element(d.begin(),d.end()),a[N-1]-d[N-1]});
  d[N-1]=x;
  tot=0;
  for(int i=N-1;i>0;i--){
    tot+=a[i];
    ma=max(ma,tot-d[i]);
  }
  tot+=a[0];
  for(int i=0;i<N-1;i++){
    ma=max(ma,tot-d[0]-a[i+1]);
  }
  ma=max(ma,a[N-1]-d[N-1]);
  cout<<ma;
}