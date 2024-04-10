#include <cstdio>
#include <map>

const int MOD=1e9+7;

int dp[200005];

void solve(){
  int N;
  scanf("%d",&N);
  long long total=0;
  std::map<long long,int> last;
  dp[0]=1;
  dp[1]=1;
  last[total]=0;
  scanf("%lld",&total);
  for(int i=2;i<=N;i++){
    int exclude=last.count(total)?dp[last[total]]:0;
    dp[i]=(dp[i-1]*2LL-exclude)%MOD;
    //printf("dp[%d]=%d\n",i,(dp[i]+MOD)%MOD);
    int B;
    scanf("%d",&B);
    last[total]=i-1;
    total+=B;
  }
  printf("%d\n",(dp[N]+MOD)%MOD);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}