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
void solve(){
  int N,M;
  cin>>N>>M;
  vector<int> a(N),q(M);
  for(int &i:a)cin>>i;
  for(int &i:q)cin>>i;
  int sum=accumulate(a.begin(),a.end(),(int)0);
  int ma=0,cur=0;
  vector<pair<int,int> >y;
  for(int i=0;i<N;i++){
    cur+=a[i];
    if(cur>ma){
      ma=cur;
      y.pb({ma,i});
    }
  }
  vector<pair<int,int> >query;
  vector<int> ans(M,0);

  for(int i=0;i<M;i++){
    if(q[i]>ma && sum<=0)ans[i]=-1;
    else{
      query.pb({q[i],i});
    }
  }
  sort(query.begin(),query.end());
  cur=0;
  int pos=0;
  for(int giri=0;;giri+=N){
    if(pos==query.size())break;
    if(cur+y.back().fi<query[pos].fi){
      cur+=sum;
      continue;
    }
    pair<int,int> l={query[pos].fi-cur,-1};
    int g=upper_bound(y.begin(),y.end(),l)-y.begin();
    ans[query[pos].se]=giri+y[g].se;
    pos++;
    giri-=N;
  }

  for(int i=0;i<M;i++)cout<<ans[i]<<" ";
  cout<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}