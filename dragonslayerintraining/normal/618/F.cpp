#include <cstdio>
#include <algorithm>

int as[1000006];
int bs[1000006];
int is[2000006];
int js[2000006];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&bs[i]);
  }
  std::fill(is,is+N*2,-1);
  int sum=N;
  int i=0,j=0;
  is[sum]=i;
  js[sum]=j;
  while(true){
    if(sum>=N){
      sum-=as[i++];
    }else{
      sum+=bs[j++];
    }
    if(is[sum]!=-1){
      printf("%d\n",i-is[sum]);
      for(int k=is[sum];k<i;k++){
	printf("%d ",k+1);
      }
      printf("\n");
      printf("%d\n",j-js[sum]);
      for(int k=js[sum];k<j;k++){
	printf("%d ",k+1);
      }
      printf("\n");
      return 0;
    }
    is[sum]=i;
    js[sum]=j;
  }
}