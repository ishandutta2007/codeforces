#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  vector<int> v(N);
  for(int &i:v)cin>>i;
  for(int i=0;i<N;i++){
    int ma=v[i],best=i;
    for(int j=i;j<N;j++){
      if(v[j]>ma){
        ma=v[j];
        best=j;
      }
      if(v[j]<ma && best!=i){
        cout<<"YES\n";
        cout<<i+1<<" "<<best+1<<" "<<j+1<<'\n';
        return;
      }
    }
  }
  cout<<"NO\n";
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}