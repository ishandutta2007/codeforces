#include <iostream>

int main(){
  int N;
  std::string str;
  std::cin>>N;
  std::cin>>str;
  int x=0,y=0;
  if(str[0]=='U'){
    y++;
  }else{
    x++;
  }
  bool low=(x>y);
  int cost=0;
  for(int i=1;i<str.length();i++){
    if(str[i]=='U'){
      y++;
    }else{
      x++;
    }
    if((x<y)&&low){
      cost++;
      low=false;
    }else if((x>y)&&!low){
      cost++;
      low=true;
    }
  }
  std::cout<<cost<<std::endl;
  return 0;
}