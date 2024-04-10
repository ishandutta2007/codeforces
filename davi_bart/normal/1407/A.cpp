#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod=1e9+7;
int pot(int a,int b){
  if(b==0)return 1;
  int x=pot(a,b/2);
  if(b%2)return x*x%mod*a%mod;
  return x*x%mod;
}

void solve(){
    int N;
    cin>>N;
    vector<int> v(N);
    int s[2]={0,0};
    for(int i=0;i<N;i++){
      cin>>v[i];
      s[v[i]]++;
    }
    s[1]-=s[1]%2;
    int tot=max(s[0],s[1]);
    cout<<tot<<'\n';
    while(tot--){
      if(s[0]>s[1])cout<<0<<" ";
      else cout<<1<<" ";
    }
    cout<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}