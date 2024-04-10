#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  string a,b;
  cin>>a>>b;
  int ma=0;
  int x=0,y=0,curx=0,cury=0;
  a+=a;
  b+=b;
  for(int i=0;i<N;i++){
    if(a[i]=='0' && b[i]=='1'){
      x++;
      curx++;
      cury=max(cury-1,(ll)0);
    }else if(a[i]=='1' && b[i]=='0'){
      y++;
      cury++;
      curx=max(curx-1,(ll)0);
    }
    ma=max(max(ma,curx),cury);
  }
  if(x!=y)cout<<-1<<'\n';
  else cout<<ma;
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
    int T=1;
    //cin>>T;
    while(T--)solve();
}