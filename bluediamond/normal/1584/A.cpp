#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long double ld;
typedef long long ll;
#define int ll

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  
  int t;
  cin>>t;
  while (t--){
    int a,b,x,y;
    cin>>a>>b;
    y=b*b;
    x=-a*a;
    cout<<x<<" "<<y<<"\n";
  }



  return 0;
}