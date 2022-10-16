#include <iostream>

int main(){
  int A,B;
  std::cin>>A>>B;
  if(A>B) std::swap(A,B);
  int best=1e9;
  for(int x=A;x<=B;x++){
    int da=x-A,db=B-x;
    best=std::min(best,da*(da+1)/2+db*(db+1)/2);
  }
  std::cout<<best<<std::endl;
  return 0;
}