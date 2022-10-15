#include <bits/stdc++.h>

bool home = 1;

using namespace std;

typedef long long ll;

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  //home=0;

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int t;
  cin>>t;
  while (t--){
    int n,c=0;
    cin>>n;
    vector<int> v(n);
    for (auto &x:v){
      cin>>x;
      if(x<0){
        x*=-1;
        c++;
      }
    }
    for (int i=0;i<c;i++) v[i]*=-1;
    vector<int> so=v;
    sort(so.begin(),so.end());
    cout<<((so==v)?("YES"):("NO"))<<"\n";
  }

}