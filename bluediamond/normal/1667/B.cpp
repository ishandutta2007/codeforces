#include <bits/stdc++.h>

bool home=1;

using namespace std;

typedef long long ll;

const int N=(int)5e5+7;
const int INF=(int)1e9+7;
int n;
ll simi[N];
int dp[N];
int big[N];
int s[N];
int t1[N];
int t2[N];

void upd(int t[],int i,int value) {
  while(i<=n+1) t[i]=max(t[i],value), i+=i&(-i);
}

int get(int t[],int i){
  int sol=-INF;
  while(i) sol=max(sol,t[i]), i-=i&(-i);
  return sol;
}

signed main() {
#ifdef ONLINE_JUDGE
  home=0;
#endif


  if(home) {
    freopen("I_am_iron_man","r",stdin);
   /// freopen ("output.txt","w",stdout);
  }
  else{
    ios::sync_with_stdio(0);cin.tie(0);
  }


  int tests;
  cin>>tests;
  while(tests--){
    cin>>n;
    for (int i=1;i<=n;i++){
      int x;
      cin>>x;
      simi[i]=simi[i-1]+x;
    }
    for(int i=0;i<=n+1;i++){
      big[i]=-INF;
      dp[i]=-INF;
      t1[i]=-INF;
      t2[i]=-INF;
    }
    {
      vector<ll> guys(n+1),uguys;
      for(int i=0;i<=n;i++) guys[i]=simi[i];
      sort(guys.begin(),guys.end()); assert(!guys.empty());
      uguys.push_back(guys[0]);
      for(int i=1;i<(int)guys.size();i++) if(guys[i]!=guys[i-1]) uguys.push_back(guys[i]);
      guys=uguys;
      for (int i=0;i<=n;i++){
        s[i]=lower_bound(guys.begin(),guys.end(),simi[i])-guys.begin();
        assert(0<=s[i]&&s[i]<=n);
        s[i]++;
      }
    }
    dp[0]=0;
    for (int i=0;i<=n;i++){
      dp[i]=max(dp[i],big[s[i]]);
      dp[i]=max(dp[i],get(t1,s[i] - 1) + i);
      dp[i]=max(dp[i],get(t2,n + 2 - s[i] - 1) - i);
      upd(t1,s[i],dp[i] - i);
      upd(t2,n + 2 - s[i],dp[i] + i);
      big[s[i]]=max(big[s[i]],dp[i]);
    }
    cout<<dp[n]<<"\n";
  }
}