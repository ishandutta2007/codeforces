#include <iostream>
#include <stdint.h>

int64_t best=0;

//make as many Xs as possible while using up all Ys and Zs
void test(int64_t X,int64_t Y,int64_t Z){
  if(Y<Z){
    std::swap(Y,Z);
  }
  X+=Z,Y-=Z;
  if(Y%2==0){
    best=std::max(best,X);
  }
}

int main(){
  int64_t R,G,B;
  std::cin>>R>>G>>B;
  test(R,G,B);
  test(G,B,R);
  test(B,R,G);
  std::cout<<(R+G+B-best)<<std::endl;
  return 0;
}