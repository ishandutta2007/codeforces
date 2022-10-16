#include <cstdio>
#include <cstring>
#include <cassert>

const int MOD=1e9+7;

char buffer[1000006];
char* str=buffer;
int N;

int lead[1000006];
int dp[1000006];
int dp1sum[1000006];
int recent[1000006];

int solve(){
  assert(str[0]=='1');
  dp[0]=1;
  dp1sum[0]=1;
  int zero_run=0;
  for(int i=1;i<N;i++){
    if(str[i]=='1'){
      lead[i]=zero_run;
      for(int k=1;k<=zero_run;k++){
	recent[k]=i;
      }
      zero_run=0;
      int j=i;
      do{
	j--;
	dp[i]=(dp[i]+dp[j])%MOD;
      }while(str[j]!='1');
      dp1sum[i]=(dp1sum[i-1]+dp[i])%MOD;
    }else{
      zero_run++;
      dp[i]=((dp1sum[i-1]-dp1sum[recent[zero_run]]+MOD)%MOD+dp[recent[zero_run]])%MOD;
      dp1sum[i]=dp1sum[i-1];
    }
    //printf("dp[%d]=%d\n",i,dp[i]);
  }
  return dp1sum[N-1];
}

int main(){
  scanf("%s",buffer);
  int head=0,tail=0;
  while(*str=='0'){
    head++;
    str++;
  }
  if(*str==0){
    printf("%d\n",head);
    return 0;
  }
  N=strlen(str);
  while(str[N-1]=='0'){
    tail++;
    N--;
  }
  assert(str[N-1]=='1');
  str[N]='\0';
  printf("%d\n",int(solve()*(head+1LL)%MOD*(tail+1LL)%MOD));
}