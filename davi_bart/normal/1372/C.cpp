#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  vector<int> k(N);
  for(int &i:k)cin>>i;
  int tot=0;
  bool prec=0;
  for(int i=0;i<N;i++){
    if(k[i]!=i+1 && prec==0){
      prec=1;
      tot++;
    }
    if(k[i]==i+1)prec=0;
  }
  cout<<min(tot,(ll)2)<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}