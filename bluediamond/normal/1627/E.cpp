#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N=(int)1e5+7;
const int INF=(int)1e18+7;
int n,wantf,cntof,cost[N];

struct OF{
  int r1,c1;
  int r2,c2;
  int gain;
}ofs[N];

map<int,int>dp[N];
vector<int>la[N];


signed main() {
 ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input","r",stdin);

  int ttt;
  cin>>ttt;
  while(ttt--){
    cin>>n>>wantf>>cntof;
    for (int i=1;i<=n;i++){
      cin>>cost[i];
    }
    for (int i=1;i<=cntof;i++){
      cin>>ofs[i].r1>>ofs[i].c1>>ofs[i].r2>>ofs[i].c2>>ofs[i].gain;
      dp[ofs[i].r1][ofs[i].c1]=INF;
      dp[ofs[i].r2][ofs[i].c2]=INF;
      la[ofs[i].r1].push_back(i);
    }
    dp[1][1]=0;
    dp[n][wantf]=INF;

    for (int i=1;i<=n;i++){
      vector<int>g;
      for (auto &it:dp[i])g.push_back(it.first);
      for (int j=1;j<(int)g.size();j++){
        dp[i][g[j]]=min(dp[i][g[j]],dp[i][g[j-1]]+abs(g[j]-g[j-1])*cost[i]);
      }
      for (int j=(int)g.size()-2;j>=0;j--){
        dp[i][g[j]]=min(dp[i][g[j]],dp[i][g[j+1]]+abs(g[j]-g[j+1])*cost[i]);
      }
      for (auto &it:la[i]){
        if(dp[ofs[it].r1][ofs[it].c1]==INF)continue;
        dp[ofs[it].r2][ofs[it].c2]=min(dp[ofs[it].r2][ofs[it].c2],dp[ofs[it].r1][ofs[it].c1]-ofs[it].gain);
      }
    }

    if(dp[n][wantf]==INF){
      cout<<"NO ESCAPE\n";

    for (int i=1;i<=n;i++)dp[i].clear(),la[i].clear();
      continue;
    }
    cout<<dp[n][wantf]<<"\n";

    for (int i=1;i<=n;i++)dp[i].clear(),la[i].clear();
  }

  ///cout<<"change back N\n";
  return 0;
}