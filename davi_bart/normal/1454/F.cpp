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
  vector<int> v(N);
  vector<int> mass;
  vector<int> mass1;
  for(int i=0;i<N;i++){
    cin>>v[i];
    if(i==0)mass.pb(v[i]);
    else mass.pb(max(mass.back(),v[i]));
  }
  for(int i=N-1;i>=0;i--){
    if(i==N-1)mass1.pb(v[i]);
    else mass1.pb(max(mass1.back(),v[i]));
  }
  //reverse(mass1.begin(),mass1.end());
  deque<pair<int,int> > mi={{-2e9,-1}};
  vector<int> sx(N);
  for(int i=0;i<N;i++){
    while(mi.size() && mi.back().fi>=v[i])mi.pop_back();
    sx[i]=mi.back().se;
    mi.push_back({v[i],i});
  }
  vector<int> dx(N);
  mi.clear();
  mi={{-2e9,N}};
  for(int i=N-1;i>=0;i--){
    while(mi.size() && mi.back().fi>=v[i])mi.pop_back();
    dx[i]=mi.back().se;
    mi.push_back({v[i],i});
  }
  for(int i=1;i<N-1;i++){
    int x=max((int)0,sx[i]),y=min(N-1,dx[i]);
    //cout<<"bella:  "<<x<<" "<<i<<" "<<y<<endl;
    int p=lower_bound(mass.begin()+x,mass.begin()+i,v[i])-mass.begin();
    //cout<<p<<endl;
    if(p>=i || mass[p]!=v[i])continue;
    int s=lower_bound(mass1.begin()+N-y-1,mass1.begin()+N-i-1,v[i])-mass1.begin();
    if(s>=N-i-1)continue;
    /*for(int k:mass1)cout<<k<<" ";
    cout<<endl;
    cout<<s<<" "<<mass1[s]<<" "<<i<<endl;*/
    if(mass1[s]!=v[i])continue;
    s=N-s-1;
    cout<<"YES"<<'\n';
    cout<<p+1<<" "<<s-p-1<<" "<<N-s<<'\n';
    return;
  }

  cout<<"NO"<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T=1;
  cin>>T;
  while(T--)solve();
}