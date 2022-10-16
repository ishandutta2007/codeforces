#include <iostream>
#include <algorithm>

int ks[3];

bool good(){
  if(ks[0]==1){
    return true;
  }else if(ks[0]==2){
    if(ks[1]==2){
      return true;
    }else if(ks[1]==3){
      return false;
    }else if(ks[1]==4){
      return (ks[2]==4);
    }else{
      return false;
    }
  }else if(ks[0]==3){
    return (ks[1]==3)&&(ks[2]==3);
  }else{
    return false;
  }
}

int main(){
  std::cin>>ks[0]>>ks[1]>>ks[2];
  std::sort(ks,ks+3);
  if(good()){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}