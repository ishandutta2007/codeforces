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
int N;
vector<int> w(100010);
void solve(){
  cin>>N;
  set<pair<int,int> >vivi;
  vector<int> vicini(N+10,0);
  for(int i=0;i<N;i++){
      cin>>w[i];
  }
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    vicini[a]++;
    vicini[b]++;
  }
  int tot=0;
  for(int i=0;i<N;i++){
    tot+=vicini[i]*w[i];
    if(vicini[i]>1)vivi.insert({w[i],i});
  }
  vector<int> ans={tot};

  while(vivi.size()){
    auto [a,b]=*vivi.begin();
    tot-=a;
    ans.pb(tot);
    vicini[b]--;
    if(vicini[b]<2)vivi.erase({a,b});
  }
  reverse(ans.begin(),ans.end());
  for(int i:ans)cout<<i<<" ";
  cout<<'\n';

}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}