#include <cstdio>
#include <vector>

const int MOD=1e9+7;

std::vector<int> factors[1000001];

int dp[1000001]={1};

int main(){
  for(int i=1000000;i>0;i--){
    for(int j=i;j<=1000000;j+=i){
      factors[j].push_back(i);
    }
  }
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    for(int f:factors[A]){
      dp[f]+=dp[f-1];
      dp[f]%=MOD;
    }
  }
  int total=0;
  for(int i=1;i<=N;i++){
    total+=dp[i];
    total%=MOD;
  }
  printf("%d\n",total);
  return 0;
}