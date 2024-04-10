#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long double ld;
typedef long long ll;

int get(int n,int m){
  assert(n*m>1);
  int sol=(n/3)*m;

  if(n%3){
    sol+=(n%3)*(m/3+(m%3>0));
  }
  return sol;
}

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
    int n,m;
    cin>>n>>m;
    cout<<min(get(n,m),get(m,n))<<"\n";
  }
  return 0;
}