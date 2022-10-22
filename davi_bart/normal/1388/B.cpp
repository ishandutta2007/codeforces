#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  string a(N,'9');
  int x=N;
  for(int i=N-1;i>=0;i--){
    if(x<=0){
       break;
    }
    x-=4;
    a[i]='8';
  }
  cout<<a<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)solve();
}