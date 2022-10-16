#include <cstdio>
#include <stdint.h>

int bad[1005][105];
int good[1005];

int64_t MOD;

void addmod(int& x,int64_t y){
  x=(x+y)%MOD;
}

int pow10[1005];

int main(){
  int N,K;
  scanf("%d %d %I64d",&N,&K,&MOD);
  pow10[0]=1;
  bad[0][0]=1;
  for(int len=0;len<N;len++){
    pow10[len+1]=pow10[len]*10LL%K;
    //printf("good[%d]=%d\n",len,good[len]);
    for(int rem=0;rem<K;rem++){
      //printf("bad[%d][%d]=%d\n",len,rem,bad[len][rem]);
      for(int d=(len==N-1);d<10;d++){
	int rem2=(rem+1LL*d*pow10[len])%K;
	if(rem2==0&&(rem!=0||d!=0)){
	  addmod(good[len+1],bad[len][rem]);
	}else{
	  addmod(bad[len+1][rem2],bad[len][rem]);
	}
      }
    }
    for(int d=(len==N-1);d<10;d++){
      addmod(good[len+1],good[len]);
    }
  }
  printf("%I64d\n",good[N]%MOD);
  return 0;
}