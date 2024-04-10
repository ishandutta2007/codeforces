#include <cstdio>
#include <stdint.h>

const int MOD=998244353;

int64_t plus,minus;

int as[200005];
int ws[200005];

int cs[3005][3005];
int ds[3005][3005];
int inv[6005];//1/(plus+minus+i-3000)

int modexp(int base,int exp){
  int ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1) ac=1LL*ac*base%MOD;
    base=1LL*base*base%MOD;
  }
  return ac;
}

int inverse(int base){
  return modexp(base,MOD-2);
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&ws[i]);
    if(as[i]){
      plus+=ws[i];
    }else{
      minus+=ws[i];
    }
  }
  //printf("W+=%ld W-=%ld\n",plus,minus);
  for(int i=0;i<=6000;i++){
    inv[i]=inverse(plus+minus+i-3000);
  }
  for(int i=0;i<=M;i++){
    cs[i][M-i]=plus+i;
    ds[M-i][i]=minus-i;
  }
  /*
  for(int i=0;i<=M;i++){
    for(int j=0;j<=M;j++){
      printf("(%d,%d)",cs[i][j],ds[i][j]);
    }
    printf("\n");
  }
  */
  for(int i=M;i>=0;i--){
    for(int j=M-i-1;j>=0;j--){
      int rcp=inverse(plus+minus+i-j);//inv[3000+i-j]
      cs[i][j]=((plus+i)*cs[i+1][j]+(minus-j)*cs[i][j+1])%MOD*rcp%MOD;
      ds[i][j]=((plus+i)*ds[i+1][j]+(minus-j)*ds[i][j+1])%MOD*rcp%MOD;
    }
  }
  /*
  for(int i=0;i<=M;i++){
    for(int j=0;j<=M;j++){
      printf("(%d,%d)",cs[i][j],ds[i][j]);
    }
    printf("\n");
  }
  printf("W+=%d W-=%d\n",cs[0][0],ds[0][0]);
  */
  int plus_base=1LL*cs[0][0]*inverse(plus)%MOD;
  int minus_base=1LL*ds[0][0]*inverse(minus)%MOD;
  for(int i=0;i<N;i++){
    int base=as[i]?plus_base:minus_base;
    printf("%d\n",int(1LL*base*ws[i]%MOD));
  }
  return 0;
}