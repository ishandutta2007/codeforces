#include <bits/stdc++.h>

bool home = 1;

using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

home=0;

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int t;
  cin>>t;
  while (t--) {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    x-=a;
    y-=b;
    x=max(x,x-x);
    y=max(y,y-y);
    if(c>=x+y) cout<<"YES\n"; else cout<<"NO\n";
  }

}