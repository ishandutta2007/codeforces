#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;
typedef long long Int;
typedef pair<Int, Int> P;
#define INF (1LL << 60);
Int n;
Int a[108000];
Int dp[64][108000];
Int hoge[64][108000];
Int cnt[64];
Int ans;
Int bias[64];
int main(){
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> a[i];
    if((a[i] & -a[i]) != a[i]){
      int p = 0;
      while(a[i] > (1LL << p)){
	p++;
      }
      bias[p-1]++;
    }
    else{
      int p = 0;
      while(a[i] != (1LL << p))p++;
      cnt[p]++;
    }
  }
  Int mxcnt = 0;
  for(int i = 0;i < 40;i++)mxcnt = max(mxcnt, cnt[i]);
  hoge[41][0] = 0;
  for(int i = 40;i >= 0;i--){
    for(int j = 0;j <= mxcnt;j++){
      dp[i][j] = 2 * j - cnt[i] + hoge[i+1][j] - bias[i];
      if(j == 0){
	if(dp[i][j] < 0){
	  hoge[i][j] = -INF;
	}
	if(dp[i][j] >= 0){
	  hoge[i][j] = dp[i][j] - j;
	}
      }
      else hoge[i][j] = hoge[i][j-1];
      if(dp[i][j] >= 0 && j){
	hoge[i][j] = max(hoge[i][j], dp[i][j] - j);
      } 
    }
    for(int j = cnt[i]+1;j <= mxcnt;j++){
      hoge[i][j] = hoge[i][j-1];
    }
  }

  for(int i = 0;i <= cnt[0];i++){
    if(dp[0][i] >= 0){
      ans++;
      printf("%d ",i);
    }
  }
  if(ans==0)printf("-1");
  puts("");
  return 0;
}