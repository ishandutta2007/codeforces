#include <cstdio>
#include <algorithm>
#include <stdint.h>

int as[200000];
int bs[200000];
int cs[200000];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N;i++){
    int low=0,high=32000;
    while(high-low>1){
      int mid=(low+high)/2;
      if(mid*mid<=as[i]){
	low=mid;
      }else{
	high=mid;
      }
    }
    cs[i]=std::min(as[i]-low*low,high*high-as[i]);
    if(as[i]==0){
      bs[i]=2;
    }else if(cs[i]==0){
      bs[i]=1;
    }else{
      bs[i]=0;
    }
  }
  std::sort(cs,cs+N);
  std::sort(bs,bs+N);
  if(cs[N/2]>0){
    int64_t sum=0;
    for(int i=0;i<N/2;i++){
      sum+=cs[i];
    }
    printf("%I64d\n",sum);
  }else{
    int64_t sum=0;
    for(int i=0;i<N/2;i++){
      sum+=bs[i];
    }
    printf("%I64d\n",sum);
  }
  return 0;
}