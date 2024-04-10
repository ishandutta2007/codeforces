#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;


const int N=5000+7;
const int INF=(int)1e9;
int n,root,tot[N],dp[N][N][2],nw[N][2];
vector<int> g[N];

void dfs(int a,int p=-1){
  vector<int>kids;
  for (auto &b:g[a]){
    if (b==p)continue;
    kids.push_back(b);
    dfs(b,a);
  }
  g[a]=kids;

  if (g[a].empty()){
    dp[a][0][0]=0;
    dp[a][1][1]=0;
    tot[a]=1;
    return;
  }
  dp[a][0][0]=0;
  dp[a][0][1]=0;
  for (auto &b:g[a]){
    for (int j=0;j<=tot[a]+tot[b];j++){
      nw[j][0]=nw[j][1]=INF;
    }
    for (int bef=0;bef<=tot[a];bef++){
      for (int cb=0;cb<=1;cb++){
        for (int now=0;now<=tot[b];now++){
          for (int cnow=0;cnow<=1;cnow++){
            nw[bef+now][cb]=min(nw[bef+now][cb],dp[a][bef][cb]+dp[b][now][cnow]+(cnow!=cb));
          }
        }
      }
    }
    tot[a]+=tot[b];
    for (int j=0;j<=tot[a];j++){
      dp[a][j][0]=nw[j][0];
      dp[a][j][1]=nw[j][1];
    }
  }
}

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

  for (int i=0;i<N;i++) for (int j=0;j<N;j++) dp[i][j][0]=dp[i][j][1]=INF;

  cin>>n;
  for (int i=1;i<n;i++) {
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  if (n==2){
    cout<<"1\n";
    return 0;
  }

  root=1;
  while ((int)g[root].size()==1){
    root++;
    assert(root<=n);
  }

  dfs(root);

  cout<<min(dp[root][tot[root]/2][0],dp[root][tot[root]/2][1])<<"\n";

  return 0;
}