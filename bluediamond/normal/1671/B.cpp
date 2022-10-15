#include <bits/stdc++.h>

bool home = 0;

using namespace std;

typedef long long ll;
typedef long double ld;



signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> v(n);
    for (auto &x:v){
      cin>>x;
    }
    sort(v.begin(),v.end());
    assert(!v.empty());
    bool ok=0;
    for(int st=v[0]-1;st<=v[0]+1;st++){
      bool acum=1;
      for (int i=0;i<n;i++){
        int want=st+i;
        acum&=(abs(want-v[i])<=1);
      }
      ok|=acum;
    }
    if(ok) cout<<"YES\n"; else cout<<"NO\n";
  }

}