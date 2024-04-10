#include <iostream>

struct s{
  int A,B,M,R;
  s(int A,int B,int M,int R):A(A),B(B),M(M),R(R){
  }
  int operator()(){
    return R;
  }
  struct s& step(){
    R=(A*R+B)%M;
    return *this;
  }
};

int main(){
  int A,B,M,R;
  std::cin>>A>>B>>M>>R;
  struct s hare(A,B,M,R),tortoise(A,B,M,R);
  hare.step().step();
  tortoise.step();
  while(hare()!=tortoise()){
    hare.step().step();
    tortoise.step();
  }
  int N=0;
  do{
    hare.step().step();
    tortoise.step();
    N++;
  }while(hare()!=tortoise());
  std::cout<<N<<std::endl;
  return 0;
}