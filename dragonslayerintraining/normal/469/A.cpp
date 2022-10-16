#include <iostream>
#include <set>

std::set<int> pass;

int main(){
  int N;
  std::cin>>N;
  int P;
  std::cin>>P;
  for(int i=0;i<P;i++){
    int l;
    std::cin>>l;
    pass.insert(l);
  }
  int Q;
  std::cin>>Q;
  for(int i=0;i<Q;i++){
    int l;
    std::cin>>l;
    pass.insert(l);
  }
  if(pass.size()==N){
    std::cout<<"I become the guy."<<std::endl;
  }else{
    std::cout<<"Oh, my keyboard!"<<std::endl;
  }
  return 0;
}