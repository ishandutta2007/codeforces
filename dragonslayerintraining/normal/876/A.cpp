#include <cstdio>
#include <algorithm>

int main(){
  int N,A,B,C;
  scanf("%d %d %d %d",&N,&A,&B,&C);
  int min=std::min(A,std::min(B,C));
  if(N==1){
    printf("%d\n",0);
  }else if(min!=C){
    printf("%d\n",min*(N-1));
  }else{
    printf("%d\n",std::min(A,B)+min*(N-2));
  }
  return 0;
}