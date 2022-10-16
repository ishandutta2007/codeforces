#include <iostream>

int N,M;

int best=0;

void test(int A,int B){
  int P=0;
  while(A+B>0){
    if(B>0){
      B--;
    }
    if(A>0){
      A--;
      P++;
    }
  }
  best=std::max(best,P);
}

int main(){
  std::cin>>N>>M;
  test(N-1,M);
  test(M-1,N);
  std::cout<<best<<" "<<N+M-best-1<<std::endl;
  return 0;
}