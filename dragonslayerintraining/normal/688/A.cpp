#include <iostream>
#include <string>

int main(){
  int N,D;
  std::cin>>N>>D;
  int best=0;
  int run=0;
  for(int i=0;i<D;i++){
    std::string absent;
    std::cin>>absent;
    bool win=false;
    for(char c:absent){
      if(c=='0'){
	win=true;
      }
    }
    if(win){
      run++;
      best=std::max(best,run);
    }else{
      run=0;
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}