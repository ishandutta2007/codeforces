#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  vector<int> p(2,0);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    if(a%2!=i%2)p[a%2]++;
  }
  if(p[0]!=p[1])cout<<-1<<'\n';
  else cout<<p[0]<<'\n';
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--){
      solve();
    }
}