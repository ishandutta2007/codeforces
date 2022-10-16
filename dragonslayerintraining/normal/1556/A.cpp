#include <cstdio>

int solve(){
  int C,D;
  scanf("%d %d",&C,&D);
  if((C==0)&&(D==0)){
    return 0;
  }else if(C==D){
    return 1;
  }else if((C+D)%2){
    return -1;
  }else{
    return 2;
  }
}   

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    printf("%d\n",solve());
  }
}