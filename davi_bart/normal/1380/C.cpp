#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N,X;
  cin>>N>>X;
  vector<int> v(N);
  for(int &i:v)cin>>i;
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  int tot=0;
  for(int i=0;i<N;i++){
    int pos=i;
    for(;i<N;i++){
      if((i-pos+1)*v[i]>=X){
        tot++;
        break;
      }
    }
  }
  cout<<tot<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}