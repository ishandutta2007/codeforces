#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  vector<int> v[2];
  for(int i=0;i<2*N;i++){
    int a;
    cin>>a;
    v[a%2].push_back(i);
  }
  bool p=v[0].size()%2;
  if(p)v[0].pop_back();
  int o=0;
  for(int i=0;i<(int)v[0].size();i+=2){
    if(o==N-1)break;
      o++;
    cout<<v[0][i]+1<<" "<<v[0][i+1]+1<<'\n';
  }

  if(v[1].size()%2)v[1].pop_back();
  for(int i=0;i<(int)(v[1].size());i+=2){
    if(o==N-1)break;
    o++;
    cout<<v[1][i]+1<<" "<<v[1][i+1]+1<<'\n';
  }
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}