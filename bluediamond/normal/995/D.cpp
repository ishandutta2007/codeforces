#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long double ld;
typedef long long ll;

const int N=18;
int n,r,c[1<<N];
ll s=0;

ld get(){
  return (ld)s/(ld)(1<<n);
}


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif


  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n>>r;
  for(int i=0;i<(1<<n);i++){
    cin>>c[i];
    s+=c[i];
  }
  cout<<fixed<<setprecision(6)<<get()<<"\n";
  for(int it=1;it<=r;it++){
    int i,cc;
    cin>>i>>cc;
    s-=c[i];
    c[i]=cc;
    s+=c[i];
    cout<<fixed<<setprecision(6)<<get()<<"\n";
  }




  return 0;
}