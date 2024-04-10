#include <cstdio>

int as[5000],bs[5000];
int ans[5000];

int bit[15];

int query(int i,int j){
  printf("? %d %d\n",i,j);
  fflush(stdout);
  int res;
  scanf("%d",&res);
  return res;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    if(i>0){
      as[i]=query(i,i-1)^bs[i-1];
    }
    bs[i]=query(i,i)^as[i];
  }
  for(int i=0;i<N;i++){
    for(int k=0;k<15;k++){
      bit[k]+=((as[i]>>k)&1);
    }
  }
  int mask=0;
  for(int k=0;k<15;k++){
    if(bit[k]>N/2){
      mask|=(1<<k);
    }
  }
  for(int i=0;i<N;i++){
    as[i]^=mask;
    bs[i]^=mask;
  }
  int cnt=0;
  for(int mask=0;mask<(N&-N);mask++){
    bool good=true;
    for(int i=0;i<N;i++){
      good=(good&&((bs[as[i]^mask]^mask)==i));
    }
    if(good){
      if(cnt++==0){
	for(int i=0;i<N;i++){
	  ans[i]=as[i]^mask;
	}
      }
    }
  }
  printf("!\n%d\n",cnt);
  for(int i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",ans[i]);
  }
  printf("\n");
  return 0;
}