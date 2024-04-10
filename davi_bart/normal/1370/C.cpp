#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  if((N%2 && N!=1) || N==2){
      cout<<"Ashishgup"<<'\n';
      return ;
  }
  vector<int> t;
  for(int i=2;i*i<=N;i++){
    if(N%i==0){
        if(i%2)t.push_back(i);
        if((N/i)%2)t.push_back(N/i);
    }
  }
  sort(t.begin(),t.end());
  if(t.size()==0){
     cout<<"FastestFinger"<<'\n';
     return;
  }
  if(t.size()==1){
    if(N/t[0]==2)cout<<"FastestFinger"<<'\n';
    else cout<<"Ashishgup"<<'\n';
    return;
  }
  if(t.size()>1){
      cout<<"Ashishgup"<<'\n';
      return;
  }

  cout<<"FastestFinger"<<'\n';
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}