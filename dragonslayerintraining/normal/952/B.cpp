#include <iostream>
#include <cassert>

int main(){
  int no=0;
  for(int i=0;i<10;i++){
    std::cout<<i<<std::endl;
    std::string response;
    std::getline(std::cin,response);
    if(response=="cool"||response=="not bad"||response=="great!"||response=="don't think so"||response=="don't touch me!"){
      std::cout<<"normal"<<std::endl;
      return 0;
    }else if(response=="terrible"||response=="worse"||response=="go die in a hole"||response=="are you serious?"||response=="don't even"||response=="no way"){
      std::cout<<"grumpy"<<std::endl;
      return 0;
    }else{
      no++;
    }
    if(no>3){
      std::cout<<"normal"<<std::endl;
      return 0;
    }
  }
  assert(false);
  return 0;
}