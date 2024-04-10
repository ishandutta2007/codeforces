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
    string s;
    cin>>s;
    bool ok=1;
    for (int i=1;i<(int)s.size()-1;i++){
      if(s[i]!=s[i-1]&&s[i]!=s[i+1]) ok=0;
    }
    if((int)s.size()>=2);
    ok&=(s[0]==s[1]),ok&=(s[(int)s.size()-2]==s[(int)s.size()-1]);
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
  }

}