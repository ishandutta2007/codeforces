#include <cstdio>
#include <stdint.h>
#include <cstring>
     
const int MOD=998244353;
const int HALF=(MOD+1)/2;
     
int N;
     
int64_t bs[1<<18][19];
     
int forbid[1<<18];
     
int64_t colorings[19][1<<18];
     
int poly[20];
     
int main(){
  int M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    forbid[(1<<A)|(1<<B)]=1;
  }
  for(int k=0;k<N;k++){
    for(int i=0;i<(1<<N);i++){
      if(i&(1<<k)) continue;
      forbid[i|(1<<k)]|=forbid[i];
    }
  }
  //init bs
  for(int i=0;i<(1<<N);i++){
    bs[i][__builtin_popcount(i)]=!forbid[i];
  }
  for(int k=0;k<N;k++){
    for(int i=0;i<(1<<N);i++){
      if(i&(1<<k)) continue;
      for(int j=0;j<=N;j++){
    	bs[i|(1<<k)][j]+=bs[i][j];
      }
    }
  }
  int ans=0;
  for(int i=0;i<(1<<N);i++){
    int sgn=((__builtin_popcount(i)&1)?1:MOD-1);
    /*
    for(int l=1;l<=N;l++){
      int64_t tmp[19]={};
      for(int x=0;x<=N;x++){
    	for(int y=0;y<=N-x;y++){
    	  tmp[x+y]=(tmp[x+y]+as[i][x]*bs[i][y])%MOD;
    	}
      }
      for(int x=0;x<=N;x++){
    	as[i][x]=tmp[x];
      }
      poly[l]=(poly[l]+sgn*tmp[N])%MOD;
    }
    */
    /*
    for(int j=0;j<=N;j++){
      printf("bs[%d]=%ld\n",j,bs[i][j]);
    }
    */
    int64_t as[19]={};
    as[0]=1;
    for(int j=1;j<=N;j++){
      for(int k=0;k<j;k++){
	as[j]=(as[j]+(MOD-as[k])*bs[i][j-k])%MOD;
      }
    }
    /*
    for(int j=0;j<=N;j++){
      printf("as[%d]=%ld\n",j,as[j]);
    }
    */
    ans=(ans+sgn*as[N])%MOD;
  }
  /*
  for(int i=0;i<N;i++){
    for(int j=N;j>i;j--){
      poly[j]=(poly[j]+MOD-poly[j-1])%MOD;
    }
  }
  int x=0;
  for(int i=N;i>=0;i--){
    x=(poly[i]+MOD-x)%MOD;
  }
  */
  int x=ans;
  //printf("-1 colors: %d=-%d\n",x,(MOD-x)%MOD);
  x=(MOD-x)%MOD;
  printf("%I64d\n",1LL*x*M%MOD*HALF%MOD);
}