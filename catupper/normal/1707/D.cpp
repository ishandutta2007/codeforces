#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using Int = long long;
using Real = long double;
using CP = complex<Real>;
using P = pair<Int, Int>;

const Int MOD = 1000000007;
const Int MOD2 = 998244353;
const Int LINF = (1LL << 60);
const int INF = (1000000007);
const Real EPS = 1e-10;
const long double PI = 3.141592653589793238462643383279502884L;



Int N, mod;

vector<int> edge[2002];
vector<Int> dp[2002];
void dfs(int x, int last = -1){
  if(last != -1)edge[x].erase(find(edge[x].begin(), edge[x].end(), last));
  vector<vector<Int>> l_dp(edge[x].size()), r_dp;
  for(int i = 0;i < edge[x].size();i++){
    int to = edge[x][i];
    dfs(to, x);
    l_dp[i] = dp[to];
    auto &vecto = l_dp[i];
    for(int i = 1;i < N;i++){
      (vecto[i] += vecto[i-1]) %= mod;
    }
  }
  r_dp = l_dp;  
  for(int i = 0;i + 1 < edge[x].size();i++){
    for(int j = 0;j < N;j++){
      (l_dp[i+1][j] *= l_dp[i][j]) %= mod;
    }
    for(int j = 0;j < N;j++){
      (r_dp[edge[x].size() - i - 2][j] *= r_dp[edge[x].size() - i - 1][j]) %= mod;
    }
  }

  auto &vec = dp[x];
  
  if(edge[x].size() == 0){
    vec.resize(N, 1);
  }
  else{
    vec = r_dp[0];
  }
  if(last == -1)return;
  for(int i = 0;i < edge[x].size();i++){
    int to = edge[x][i];
    vector<Int> tmp(N);
    for(int j = 0;j < N;j++){
      tmp[j] = 1;
      if(i > 0)(tmp[j] *= l_dp[i-1][j]) %= mod;
      if(i + 1 < edge[x].size())(tmp[j] *= r_dp[i+1][j]) %= mod;
      if(j > 0)(tmp[j] += tmp[j-1]) %= mod;
    }
    Int larger = 0;
    for(int j = N-1;j > 0;j--){
      (vec[j] += (dp[to][j] * tmp[j-1]) % mod) %= mod;
    }
  }
  
}

Int nCk[2002][2002];

void init(){
  for(int i = 0;i < 2002;i++){
    for(int j = 0;j <= i;j++){
      if(j == 0)nCk[i][j] = 1;
      else nCk[i][j] = (nCk[i-1][j-1] + nCk[i-1][j]) % mod;
      
    }
  }
} 

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> mod;
    init();
    for(int i = 0;i < N-1;i++){
      int u, v;
      cin >> u >> v;
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    dfs(1);
    auto &ans = dp[1];
    for(int i = 0;i < N-1;i++){
      for(int j = i+1;j < N;j++){
	(ans[j] -= (ans[i] * nCk[j+1][i+1]) % mod) %= mod;
      }
      if(ans[i] < 0)ans[i] += mod;
      cout << ans[i] << " ";
    }cout << endl;
    return 0;
}