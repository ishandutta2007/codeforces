#include <iostream>
#include <cmath>
#include <stdint.h>

int64_t dir[1000001];
int64_t offset[1000001];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int64_t P;
    std::cin>>P;
    P--;
    if(P>=i){
      offset[0]+=P-i;
      dir[0]-=1;
      dir[P-i]+=2;
      offset[N-i]-=(N-P);
      offset[N-i]+=P;
      dir[N-i]-=2;
    }else{
      offset[0]+=i-P;
      dir[0]+=1;
      offset[N-i]-=(N-P);
      offset[N-i]+=P;
      dir[N-i]-=2;
      dir[P+N-i]+=2;
    }
  }
  int64_t curr=0,currdir=0;
  int64_t best=1e18;
  int index;
  for(int i=0;i<N;i++){
    curr+=offset[i];
    currdir+=dir[i];
    if(curr<best){
      best=curr;
      index=i;
    }
    curr+=currdir;
  }
  std::cout<<best<<" "<<index<<std::endl;
  return 0;
}