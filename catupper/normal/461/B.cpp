#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;
#define MOD 1000000007

Int pow(Int a,Int b){
  if(b == 0)return 1;
  Int res = pow(a, b / 2);
  res *= res;res %= MOD;
  if(b % 2 == 1)res *= a;
  return res % MOD;
}

Int rev(Int x){
  return pow(x, MOD - 2);
}

Int color[108000], p[108000];
Int dp[108000][2];
vector<int> edge[108000];

Int dfs(int x){
  for(int i = 0;i < edge[x].size();i++){
    int to = edge[x][i];
    dfs(to);
  }
  if(color[x] == 1){
    dp[x][0] = 0;
    dp[x][1] = 1;
    for(int i = 0;i < edge[x].size();i++){
      int to = edge[x][i];
      dp[x][1] *= dp[to][0] + dp[to][1];
      dp[x][1] %= MOD;
    }
  }
  else{
    dp[x][0] = 1;
    dp[x][1] = 0;
    for(int i = 0;i < edge[x].size();i++){
      int to = edge[x][i];
      dp[x][0] *= dp[to][0] + dp[to][1];
      dp[x][0] %= MOD;
    }
    for(int i = 0;i < edge[x].size();i++){
      int to = edge[x][i];
      dp[x][1] += (dp[x][0] * dp[to][1])%MOD * rev(dp[to][0] + dp[to][1]);
      dp[x][1] %= MOD;
    }
  }
  return dp[x][1];
}

int main(){
  int n;
  cin >> n;
  for(int i = 1;i <= n - 1;i++){
    cin >> p[i];
    edge[p[i]].push_back(i);
  }
  for(int i = 0;i < n;i++)cin >> color[i];
  cout << dfs(0) << endl;
  return 0;
}