#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 1000000009
#define MOD3 1000000021
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;
Int _dp[3240];
char c;
Int m;
bool ban(string str){
  if(str == "1100")return true;
  if(str == "1010")return true;
  if(str == "0111")return true;
  if(str == "1111")return true;
  return false;
}

string rev(string hoge){
  string res = "";
  for(int i = hoge.size() - 1;i >= 0;i--)res += hoge[i];
  return res;
}

Int solve(string str, int b){
  fill(_dp, _dp + 3240, 0);
  Int *dp = &_dp[1];
  dp[-1] = 1;
  Int res = 0;
  for(Int i = 0;i < str.size();i++){
    string tmp = "";
    for(int j = 0;j < 4;j++){
      if(i-j < 0)continue;
      tmp = str[i-j] + tmp;
      if(ban(tmp))continue;
      dp[i] = (dp[i] + dp[i-j-1]) % MOD;
    }
    if(i >= b)(res += dp[i]) %= MOD;
    //    cout << i << " " << dp[i] << endl;
  }
  return res;
}
int common[3240][3240];
int main(){
  cin >> m;
  Int acum = 0;
  string str = "";
  for(int i = 0;i < m;i++){
    cin >> c;str += c;
    int tmp = 0;
    for(int j = 0;j < i;j++){
      if(str[j] == str[i]){
	if(j > 0)common[j][i] = common[j-1][i-1] + 1;
	else common[j][i] = 1;
      }
      else common[j][i] = 0;
      tmp = max(tmp, common[j][i]);
    }
    (acum += solve(rev(str), tmp)) %= MOD;
    cout << acum << endl;
  }
  return 0;
}