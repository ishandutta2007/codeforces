#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

const int N=(int)1e5+7;
const int M=(int)2e3+7;

int n,m,init[N],pref[N];
pair<int,int>a[N];
int b[M];

int dp[N];

int cntksmaller(int limit){
  int l=1,r=m,sol=0;
  while (l<=r){
    int k=(l+r)/2;
    if(b[k]<=limit){
      sol=k;
      l=k+1;
    }else r=k-1;
  }
  return sol;
}

int cntk(int lft,int rgh){
  if (lft>rgh)return 0;
  return cntksmaller(rgh)-cntksmaller(lft-1);
}

int sc[M],ff[M];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
    //freopen ("testing place","w",stdout);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n>>m;


  for (int i=1;i<=n;i++) cin>>init[i];
  for (int i=1;i<=m;i++) cin>>b[i];

  sort(init+1,init+n+1);
  sort(b+1,b+m+1);


  {
    int y=0;
    for (int i=1;i<=n;i++){
      if(i==1||init[i]-init[i-1]!=1){
        a[++y]={init[i],init[i]};
      }else{
        a[y].second++;
      }
      pref[y]=i;
    }
    n=y;
  }


  for (int i=1;i<=m;i++){
    ff[i]=sc[i]=n;
  }

  for (int i=1;i<=n;i++){

    int kmax=0,l=1,r=m;
    while (l<=r){
      int k=(l+r)/2;
      if(b[k]<=a[i].second){
        kmax=k;
        l=k+1;
      }else r=k-1;
    }

    int stop=0;

    for (int k=1;k<=kmax;k++){
      if (a[i].second-pref[i]+1>b[k])continue;
      while (a[i].second-(pref[i]-pref[ff[k]-1])+1>b[k])ff[k]--;
      stop=max(stop,dp[ff[k]-1]+kmax-k+1);
    }
    stop=max(stop,dp[i-1]);

    int kmin=m+1;
    l=1,r=m;
    while (l<=r){
      int k=(l+r)/2;
      if(a[i].second+1<=b[k]){
        kmin=k;
        r=k-1;
      }else l=k+1;
    }

    for (int k=kmin;k<=m;k++){
      if (b[k]>a[i].second+pref[n]-pref[i])continue;
      while (sc[k]-1>=1&&b[k]<=a[i].second+(pref[sc[k]-1]-pref[i]))sc[k]--;
      dp[sc[k]]=max(dp[sc[k]],stop+k-kmin+1);
    }

    dp[i]=max(dp[i],dp[i-1]);
    dp[i]=max(dp[i],stop);

  }
  cout<<dp[n]<<"\n";

  return 0;
}