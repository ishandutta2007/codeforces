#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  if(N>=31 && N!=36 && N!=40 && N!=44)cout<<"YES\n"<<6<<" "<<10<<" "<<14<<" "<<N-30<<'\n';
  else if(N==36)cout<<"YES\n6 10 15 5\n";
  else if(N==40)cout<<"YES\n6 10 15 9\n";
  else if(N==44)cout<<"YES\n6 7 10 21\n";
  else cout<<"NO\n";
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)solve();
}