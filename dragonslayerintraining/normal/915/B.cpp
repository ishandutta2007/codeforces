#include <iostream>
#include <algorithm>

int main(){
  int N,pos,L,R;
  std::cin>>N>>pos>>L>>R;
  int best=std::min(std::abs(pos-L)+std::abs(R-L)+2,
		    std::abs(pos-R)+std::abs(R-L)+2);
  if(R==N){
    best=std::min(best,std::abs(pos-L)+1);
  }
  if(L==1){
    best=std::min(best,std::abs(pos-R)+1);
  }
  if((L==1)&&(R==N)){
    best=0;
  }
  std::cout<<best<<std::endl;
  return 0;
}