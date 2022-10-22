#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;
double dp[2][1080];
double hoge[108000];
Int k, q, p;
#define EPS (1e-7)
int main(){
  cin >> k >> q;
  dp[0][0] = 1;
  int mx;
  for(int i = 0;i < 108000;i++){
    int id = i % 2;
    int nid = id ^ 1;
    for(int j = 0;j <= k;j++){
      if(dp[id][j] == 0)continue;
      dp[nid][j] += dp[id][j] * j / k;
      dp[nid][j+1] += dp[id][j] * (k - j) / k;
      dp[id][j] = 0;
    }
    hoge[i+1] = dp[nid][k];
    mx = i+1;
    if(dp[nid][k] > 0.5)break;
  }
  while(q--){
    cin >> p;
    int bottom = 1, top = mx;
    while(top - bottom > 1){
      int mid = (top + bottom) / 2;
      if(hoge[mid] >= (p - EPS) / 2000)top = mid;
      else bottom = mid;
    }
    cout << top << endl;
  }
  return 0;
}