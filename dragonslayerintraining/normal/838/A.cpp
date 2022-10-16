#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t N,M;


int64_t grid[2501][2501];

void readinput(){
  scanf("%I64d %I64d",&N,&M);
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      grid[i][j]=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
      char c;
      for(c=getchar();(c!='0')&&(c!='1');c=getchar());
      if(c=='1'){
	grid[i][j]++;
      }
      //fprintf(stderr,"(%d,%d)=%I64d\n",i,j,grid[i][j]);
    }
  }
}

int64_t query(int64_t i,int64_t j){
  i=std::min(i,N);
  j=std::min(j,M);
  return grid[i][j];
}

int64_t query(int64_t x0,int64_t y0,int64_t x1,int64_t y1){
  int64_t q=query(x1,y1)-query(x1,y0)-query(x0,y1)+query(x0,y0);
  //fprintf(stderr,"Q(%I64d,%I64d,%I64d,%I64d)=%I64d\n",x0,y0,x1,y1,q);
  return q;
}

bool skip[3000];

int main(){
  std::fill(skip,skip+3000,false);
  for(int64_t i=2;i<3000;i++){
    for(int64_t k=i*2;k<3000;k+=i){
      skip[k]=true;
    }
  }
  
  readinput();
  int64_t best=N*M;
  for(int64_t k=2;k<=std::max(N,M);k++){
    if(skip[k]){
      continue;
    }
    int64_t sum=0;
    for(int64_t i=0;i<N;i+=k){
      for(int64_t j=0;j<M;j+=k){
	int64_t q=query(i,j,i+k,j+k);
	sum+=std::min(q,k*k-q);
      }
    }
    //fprintf(stderr,"Sum[%I64d]=%I64d\n",k,sum);
    best=std::min(best,sum);
  }
  printf("%I64d\n",best);
  return 0;
}