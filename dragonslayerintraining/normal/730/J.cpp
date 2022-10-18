#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <deque>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF 1001001001
#define MOD 1000000007

int N;
int A[101],B[101];
vector<int>v;
int Asum=0;
int K;
pair<int,int> dp[101][10001]; //min bottles, -max current

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>N;
  for (int i=0;i<N;i++){
    cin>>A[i];
    Asum+=A[i];
  }
  for (int i=0;i<N;i++){
    cin>>B[i];
    v.push_back(-B[i]);
  }
  sort(v.begin(),v.end());
  for (int i=0;i<(int)v.size();i++){
    Asum+=v[i];
    if (Asum<=0){
      K=i+1;
      break;
    }
  }
  Asum=0;
  for (int i=0;i<N;i++)
    Asum+=A[i];
  for (int i=0;i<=N;i++)
    for (int j=0;j<=N*100;j++)
      dp[i][j]={INF,0};
  dp[0][0]={0,0};
  for (int i=0;i<N;i++)
    for (int j=0;j<=N*100;j++){
      dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
      dp[i+1][j+B[i]]=min(dp[i+1][j+B[i]],{dp[i][j].first+1,dp[i][j].second-A[i]});
    }
  int T=INF;
  for (int i=Asum;i<=N*100;i++)
    if (dp[N][i].first==K)
      T=min(T,Asum+dp[N][i].second);
  cout<<K<<' '<<T<<endl;
  return 0;
}