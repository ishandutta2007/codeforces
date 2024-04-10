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
  vector<int> q(N+10,0);
  int m=0;
  for(int &i:v){
      cin>>i;
      q[i]++;
      m=max(m,q[i]);
  }
  if(m>(N+1)/2){
    cout<<-1<<'\n';
    return ;
  }
  vector<int> p=v;
  vector<int> bad(N+10,0);
  int tot=0;
  int ma=0,tutti=0,pos;
  for(int i=0;i<N-1;i++){
    if(v[i]==v[i+1]){
        bad[v[i]]++;
        tutti++;
        if(bad[v[i]]>ma){
          ma=bad[v[i]];
          pos=v[i];
        }
    }
  }
  if(ma+ma<=tutti)tot=tutti;
  else{
    ma=ma-(tutti-ma);
    tot=tutti+ma;
    int k=0;
    if(pos!=v[0])k++;
    if(pos!=v.back())k++;
    if(ma==1)k=min(k,(int)1);
    tot-=k;
  }

  cout<<tot<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}