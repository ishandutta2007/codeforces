#include <cstdio>
#include <algorithm>
int N;
char str[105];

int main(){
  scanf("%d %s",&N,str);
  int run=0;
  int cost=0;
  for(int i=0;i<=N;i++){
    if(str[i]=='x'){
      run++;
    }else{
      cost+=std::max(0,run-2);
      run=0;
    }    
  }
  printf("%d\n",cost);
  return 0;
}