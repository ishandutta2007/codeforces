#include <cstdio>
#include <algorithm>

const int MOD=998244353;

char str[200005];

int freq[23][26];

int subset_min[1<<23];

int dp[1<<23];//number of distinct subsequences of subset

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%s",str);
    for(int j=0;str[j];j++){
      freq[i][str[j]-'a']++;
    }
  }
  std::fill(dp+1,dp+(1<<N),1);
  for(int c=0;c<26;c++){
    for(int k=0;k<N;k++){
      subset_min[1<<k]=freq[k][c];
      for(int mask=1;mask<(1<<k);mask++){
	subset_min[mask+(1<<k)]=std::min(subset_min[mask],freq[k][c]);
      }
    }
    for(int mask=1;mask<(1<<N);mask++){
      dp[mask]=1LL*dp[mask]*(subset_min[mask]+1)%MOD;
    }
  }
  for(int k=0;k<N;k++){
    for(int mask=0;mask<(1<<N);mask++){
      if(mask&(1<<k)) continue;
      dp[mask|(1<<k)]=(dp[mask|(1<<k)]+MOD-dp[mask])%MOD;
    }
  }
  long long ans=0;
  for(int mask=0;mask<(1<<N);mask++){
    int pop=__builtin_popcount(mask);
    int idxsum=0;
    for(int k=0;k<N;k++){
      if(mask&(1<<k)){
	idxsum+=k+1;
      }
    }
    int res=(pop&1)?dp[mask]:(MOD-dp[mask])%MOD;
    ans^=1LL*res*idxsum*pop;
  }
  printf("%lld\n",ans);
}