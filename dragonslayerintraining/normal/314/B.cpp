#include <iostream>
#include <stdint.h>

int64_t B,D;
std::string A,C;

int64_t next[25][105];

int main(){
  std::cin>>B>>D>>A>>C;
  for(int64_t i=0;i<C.size();i++){
    int64_t nxt=0;
    for(char c:A){
      if(c==C[(i+nxt)%C.size()]){
	nxt++;
      }
    }
    next[0][i]=nxt;
  }
  for(int64_t k=1;k<25;k++){
    for(int64_t i=0;i<C.size();i++){
      next[k][i]=next[k-1][i]+next[k-1][(i+next[k-1][i])%C.size()];
    }
  }
  int64_t i=0;
  int64_t cnt=0;
  for(int64_t k=25-1;k>=0;k--){
    if(B&(1<<k)){
      i+=next[k][i];
      cnt+=i/C.size();
      i%=C.size();
    }
  }
  std::cout<<cnt/D<<std::endl;
  return 0;
}