#include <iostream>

int A,B,C,D,E;

std::string getsize(std::string size){
  if(size=="S"){
    if(A>0){A--;return "S";}
    if(B>0){B--;return "M";}
    if(C>0){C--;return "L";}
    if(D>0){D--;return "XL";}
    if(E>0){E--;return "XXL";}
  }else if(size=="M"){
    if(B>0){B--;return "M";}
    if(C>0){C--;return "L";}
    if(A>0){A--;return "S";}
    if(D>0){D--;return "XL";}
    if(E>0){E--;return "XXL";}
  }else if(size=="L"){
    if(C>0){C--;return "L";}
    if(D>0){D--;return "XL";}
    if(B>0){B--;return "M";}
    if(E>0){E--;return "XXL";}
    if(A>0){A--;return "S";}
  }else if(size=="XL"){
    if(D>0){D--;return "XL";}
    if(E>0){E--;return "XXL";}
    if(C>0){C--;return "L";}
    if(B>0){B--;return "M";}
    if(A>0){A--;return "S";}
  }else if(size=="XXL"){
    if(E>0){E--;return "XXL";}
    if(D>0){D--;return "XL";}
    if(C>0){C--;return "L";}
    if(B>0){B--;return "M";}
    if(A>0){A--;return "S";}
  }
  return "";
}

int main(){
  std::cin>>A>>B>>C>>D>>E;
  int K;
  std::cin>>K;
  for(int i=0;i<K;i++){
    std::string size;
    std::cin>>size;
    std::cout<<getsize(size)<<std::endl;
  }
  return 0;
}