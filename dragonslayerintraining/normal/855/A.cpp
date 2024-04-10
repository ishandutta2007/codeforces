#include <iostream>
#include <set>

int main(){
  std::set<std::string> appears;
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string name;
    std::cin>>name;
    if(appears.count(name)){
      std::cout<<"YES"<<std::endl;
    }else{
      std::cout<<"NO"<<std::endl;
      appears.insert(name);
    }
}
  return 0;
}