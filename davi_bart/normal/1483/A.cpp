#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> v[200010];
void solve(){
  int N,M;
  cin>>N>>M;
  vector<int> volte(N+10,0);
  for(int i=0;i<M;i++){
    v[i].clear();
    int k;
    cin>>k;
    while(k--){
      int a;
      cin>>a;
      v[i].pb(a);
    }
    if(v[i].size()==1)volte[v[i][0]]++;
  }
  if(*max_element(volte.begin(),volte.end())>(M+1)/2){
    cout<<"NO"<<'\n';
    return;
  }
  cout<<"YES"<<'\n';
  for(int i=0;i<M;i++){
    int mi=1e8,best;
    for(int j:v[i]){
      if(volte[j]<mi){
        mi=volte[j];
        best=j;
      }
    }
    cout<<best<<" ";
    if(v[i].size()>1)volte[best]++;
  }
  cout<<'\n';

}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}