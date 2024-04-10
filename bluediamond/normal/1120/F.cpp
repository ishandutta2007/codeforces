
#include <bits/stdc++.h>

using namespace std;

#define int long long
bool home = 1;
const int N=(int)1e5+7;
const int INF=(int)1e18+7;
int n,c,d,t[N],guy[N],dp[N],nxtdif[N];

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

  cin>>n>>c>>d;
  for (int i=1;i<=n;i++){
    string s;
    cin>>t[i]>>s;
    assert(s=="P"||s=="W");
    guy[i]=(s=="P");
    dp[i]=d*(i-1);
  }
  dp[n+1]=d*n;
  cin>>t[n+1];
  guy[n+1]=-1;
  for (int i=n;i>=1;i--){
    if(guy[i]==guy[i+1]) {
      nxtdif[i]=nxtdif[i+1];
    }else{
      nxtdif[i]=i+1;
    }
  }

  int pivot=0;

  for (int i=1;i<=n;i++){
    int nxt=nxtdif[i];
    int cost=dp[i]+c*(t[nxt]-t[i]);
    while(c*t[pivot+1]<=c*t[nxt]-d) pivot++;
    cost+=d*max(0LL,pivot-i);
    for (int j=max(pivot,i)+1;j<nxt;j++){
      cost+=c*(t[nxt]-t[j]);
    }
    dp[nxt]=min(dp[nxt],cost);
  }


  cout<<min(dp[n+1],n*d)<<"\n";


  return 0;
}