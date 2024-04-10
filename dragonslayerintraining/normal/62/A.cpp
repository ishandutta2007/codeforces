#include <iostream>

bool test(int g,int b){
  return (b<=2*g+2)&&(g<=b+1);
}

int main(){
  int al,ar,bl,br;
  std::cin>>al>>ar>>bl>>br;
  if(test(al,br)||test(ar,bl)){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}