#include <iostream>

int fs[5000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>fs[i];
    fs[i]--;
  }
  for(int i=0;i<N;i++){
    if(fs[fs[fs[i]]]==i){
      std::cout<<"YES"<<std::endl;
      return 0;
    }
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}