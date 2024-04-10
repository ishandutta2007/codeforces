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
  int N;
  cin>>N;
  vector<pair<int,int> > v(N);
  for(int i=0;i<N;i++){
    cin>>v[i].fi;
    v[i].se=i+1;
  }
  sort(v.begin(),v.end());
  int l=0,r=N-1;
  while(l<r){
    int m=(l+r)/2;
    int cur=v[m].fi;
    bool vin=1;
    for(int i=0;i<N;i++){
      if(i==m)continue;
      if(cur>=v[i].fi){
        cur+=v[i].fi;
      }else vin=0;
    }
    if(vin)r=m;
    else l=m+1;
  }
  set<int> ok;
  for(int i=l;i<N;i++){
    ok.insert(v[i].se);
  }
  cout<<ok.size()<<'\n';
  for(int x:ok)cout<<x<<" ";
  cout<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}