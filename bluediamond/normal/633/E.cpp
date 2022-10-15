#include <bits/stdc++.h>

bool home = 1;
using namespace std;

typedef long long ll;
typedef double ld;
const int N=(int)1e6+7;
const int K=21;
const int INF=(int)1e9+7;
int n;
int k;
int v[N];
int c[N];
int opt[N];
int rv[K][N];
int rc[K][N];
int lg[N];

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


  cin>>n>>k;
  for(int i=1;i<=n;i++) {cin>>v[i]; v[i]*=100;}
  for(int i=1;i<=n;i++) cin>>c[i];

  for (int i=1;i<=n;i++){
    rv[0][i]=v[i];
    rc[0][i]=c[i];
  }
  for (int i=2;i<=n;i++) lg[i]=1+lg[i/2];
  for (int k=1;(1<<k)<=n;k++){
    for (int i=1;i+(1<<k)-1<=n;i++){
      rv[k][i]=max(rv[k-1][i],rv[k-1][i+(1<<(k-1))]);
      rc[k][i]=min(rc[k-1][i],rc[k-1][i+(1<<(k-1))]);
    }
  }
  for (int l=1;l<=n;l++){
    int low=l,high=n;
    while(low<=high){
      int r=(low+high)/2;
      int k=lg[r-l+1];
      int F=max(rv[k][l],rv[k][r-(1<<k)+1]),S=min(rc[k][l],rc[k][r-(1<<k)+1]);

      if(F<=S) opt[l] = max(opt[l], F), low=r+1; else opt[l] = max(opt[l], S), high=r-1;
    }
  }
  sort(opt+1,opt+n+1);
  ld sol=0;

  if(n==k){
    cout<<opt[1]<<"\n";
    return 0;
  }

  if(k==1){
    ll s=0;
    for (int i=1;i<=n;i++) s+=opt[i];
    cout<<fixed<<setprecision(6)<<(ld)s/(ld)n<<"\n";
    return 0;
  }

  k-=2;

  {
    ld prod=1;
    for (int i=1;i<=n-k-1;i++){
      prod/=(n-i+1);
      prod*=(n-i-k);
      sol+=opt[i]*prod;
    }
  }
  k+=2;
  sol*=k;
  sol/=(ld)(n-k+1);
  cout<<fixed<<setprecision(6)<<sol<<"\n";
}