#include <cstdio>
#include <algorithm>

const int INf=1e9+7;

char grid[2][200005];

int dp[200005][2];

void solve(){
  int N;
  scanf("%d",&N);
  scanf("%s",grid[0]);
  scanf("%s",grid[1]);
  int L=0,R=N-1;
  while(grid[0][L]=='.'&&grid[1][L]=='.') L++;
  while(grid[0][R]=='.'&&grid[1][R]=='.') R--;
  dp[L][0]=0;
  dp[L][1]=0;
  for(int i=L;i<=R;i++){
    dp[i+1][0]=std::min(dp[i][0]+(grid[1][i]=='*'),dp[i][1]+1);
    dp[i+1][1]=std::min(dp[i][1]+(grid[0][i]=='*'),dp[i][0]+1);
  }
  printf("%d\n",R-L+std::min(dp[R+1][0],dp[R+1][1]));
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}