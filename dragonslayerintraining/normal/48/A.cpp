#include <iostream>

int choices[3];

int main(){
  for(int i=0;i<3;i++){
    std::string str;
    std::cin>>str;
    choices[i]=(str=="rock")?0:(str=="paper")?1:2;
  }
  for(int i=0;i<3;i++){
    if(((choices[i]+3-choices[(i+1)%3])%3==1)&&
       ((choices[i]+3-choices[(i+2)%3])%3==1)){
      std::cout<<((i==0)?"F":(i==1)?"M":"S")<<std::endl;
      return 0;
    }
  }
  std::cout<<"?"<<std::endl;
  return 0;
}