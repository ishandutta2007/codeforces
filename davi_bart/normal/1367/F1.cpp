#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int sol(vector<int>k){
  int N=k.size();
  int mi=1000000;
  vector<int> d(N+1,0);
  vector<int> a(N+1,0);
  vector<int> b(N+1,0);
  for(int i=0;i<N;i++)a[k[i]]++;
  for(int i=N-1;i>=0;i--){
    b[k[i]]++;
    if(a[k[i]+1]==b[k[i]+1]){
      d[k[i]]=max(d[k[i]+1]+1,d[k[i]]+1);
    }else{
      d[k[i]]=max(b[k[i]+1]+1,d[k[i]]+1);
    }
    mi=min(mi,N-d[k[i]]);
  }
  return mi;
}
void solve(){
  int N;
  cin>>N;
  vector<pair<int,int> >v;
  vector<int>p(N);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    v.push_back({a,i});
  }
  sort(v.begin(),v.end());
  int y=0;
  for(int i=0;i<N;i++){
      p[v[i].second]=y;
      if(i<N-1 && v[i+1].first!=v[i].first)y++;
  }
  //cout<<"p: ";
  //for(int i=0;i<N;i++)cout<<p[i]<<" ";
    //cout<<'\n';
  int mi=sol(p);
  //for(int i=0;i<N;i++)p[i]=N-1-p[i];
  //mi=min(mi,sol(p));
  cout<<mi<<'\n';
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--){
      solve();
    }
}