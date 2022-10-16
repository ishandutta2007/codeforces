#include <cstdio>

int as[10005];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  double low=0,high=1000;
  while(true){
    double mid=(low+high)/2;
    if(mid==low||mid==high) break;
    double excess=0;
    for(int i=0;i<N;i++){
      if(as[i]>mid){
	excess+=(as[i]-mid)*(100-K)/100;
      }else{
	excess+=(as[i]-mid);
      }
    }
    if(excess>=0){
      low=mid;
    }else{
      high=mid;
    }
  }
  printf("%.10f\n",low);
  return 0;
}