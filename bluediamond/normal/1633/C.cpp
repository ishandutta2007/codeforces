#include <bits/stdc++.h>


using namespace std;

bool home = 1;
#define int long long

bool wn(int hc,int dc,int hm,int dm){
  int t1=(hm+dc-1)/dc;
  int t2=(hc+dm-1)/dm;
  return t1<=t2;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  int tests;
  cin>>tests;
  while(tests--){
    int hc,dc,hm,dm,k,w,a;
    cin>>hc>>dc>>hm>>dm>>k>>w>>a;
    bool ok=0;
    for (int u=0;u<=k;u++){
      ok|=wn(hc+a*u,dc+w*(k-u),hm,dm);
    }
    if(ok){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }

  return 0;
}