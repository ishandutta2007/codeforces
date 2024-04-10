#include <cstdio>
#include <stdint.h>
#include <set>

int64_t as[1005];

int main(){
  int N;
  scanf("%d\n",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    as[i]=A;
  }
  for(int i=N-1;i>=0;i--){
    as[i]-=as[0];
  }
  for(int i=1;i<N;i++){
    std::set<int64_t> distinct;
    for(int j=1;j<N;j++){
      distinct.insert(i*as[j]-j*as[i]);
      if(distinct.size()>2){
	break;
      }
    }
    if(distinct.size()==2){
      printf("Yes\n");
      return 0;
    }
    if(distinct.size()==1){
      printf("No\n");
      return 0;
    }
  }
  for(int i=3;i<N;i++){
    if(as[i]+as[i-2]!=as[i-1]*2){
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}