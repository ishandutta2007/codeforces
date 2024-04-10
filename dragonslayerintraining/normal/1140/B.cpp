#include <cstdio>
#include <algorithm>

char str[105];

int main(){
  int T;
  scanf("%d",&T);
  while(T-->0){
    int N;
    scanf("%d",&N);
    scanf("%s",str);
    int cost=N;
    for(int i=0;i<N;i++){
      if(str[i]=='>'){
	cost=std::min(cost,i);
      }else{
	cost=std::min(cost,N-i-1);
      }
    }
    printf("%d\n",cost);
  }
  return 0;
}