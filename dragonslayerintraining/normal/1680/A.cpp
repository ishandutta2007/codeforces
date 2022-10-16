#include <cstdio>
#include <algorithm>

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int L1,R1,L2,R2;
    scanf("%d %d %d %d",&L1,&R1,&L2,&R2);
    if(std::max(L1,L2)<=std::min(R1,R2)){
      printf("%d\n",std::max(L1,L2));
    }else{
      printf("%d\n",L1+L2);
    }
  }
}