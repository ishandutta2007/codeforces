#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  vector<int> v(N),p(N);
  int a=0,b=0;
  for(int i=0;i<N;i++){
      cin>>v[i];
      a+=v[i];
  }
  for(int i=0;i<N;i++){
      cin>>p[i];
      b+=p[i];
  }
  if(b<a){
    cout<<"NO\n";
    return ;
  }
  v.push_back(v[0]);
  v.erase(v.begin());
  int sx=-1,dx=p[0];
  while(sx<dx-1){
    int m=(sx+dx)/2;
    int rim=m;
    bool ok=1;
    for(int i=1;i<N;i++){
      rim+=p[i]-v[i-1];
      if(rim<0){
        ok=0;
        break;
      }
      rim=min(rim,p[i]);
    }
    if(ok)dx=m;
    else sx=m;
  }
  int rim=dx;
  int primo=0;
  for(int i=1;i<N;i++){
    rim+=p[i]-v[i-1];
    if(rim<0){
      cout<<"NO\n";
      return ;
    }
    if(rim>p[i]){
      primo+=rim-p[i];
    }
    rim=min(rim,p[i]);
  }
  if(rim+p[0]-dx<v[N])cout<<"NO\n";
  else cout<<"YES\n";

}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}