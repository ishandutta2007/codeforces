#include <bits/stdc++.h>

using namespace std;

#define int long long
bool home = 1;

signed main() {
 // ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
    //freopen ("testing place","w",stdout);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int x,y;
  cin>>x>>y;

  if(__gcd(x,y)>1){
    cout<<"Impossible\n";
    exit(0);
  }

  vector<pair<int,string>>sol;

  while (max(x,y)>1) {
    if(x>y){
      sol.push_back({x/y,"A"});
      x%=y;
    }else{
      sol.push_back({y/x,"B"});
      y%=x;
    }
  }
  if(!sol.empty())sol.back().first--;

  for (auto &it:sol){
    cout<<it.first<<it.second;
  }

  return 0;
}