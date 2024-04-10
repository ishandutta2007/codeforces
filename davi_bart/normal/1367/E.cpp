#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N,K;
  cin>>N>>K;
  string a;
  cin>>a;
  sort(a.begin(),a.end());
  vector<int>p(26,0);
  for(int i=0;i<a.size();i++)p[a[i]-'a']++;
  sort(p.begin(),p.end(),greater<int>());
  int ma=0;
  for(int i=1;i<=K;i++){
    if(K%i==0){
      for(int j=1;j<=N;j++){
        int x=0;
        for(int z=0;z<26;z++){
          x+=p[z]/j;
        }
        if(x>=i)ma=max(ma,i*j);
        else break;
      }
    }
  }
  cout<<ma<<'\n';

}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--){
      solve();
    }
}