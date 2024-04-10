#include <iostream>
#include <map>

char trump;
std::string card1,card2;

std::map<char,int> ranks;

bool f(){
  if((card1[1]==trump)&&(card2[1]!=trump)){
    return true;
  }else if((card1[1]!=trump)&&(card2[1]==trump)){
    return false;
  }else if(card1[1]!=card2[1]){
    return false;
  }else{
    ranks['6']=1;
    ranks['7']=2;
    ranks['8']=3;
    ranks['9']=4;
    ranks['T']=5;
    ranks['J']=6;
    ranks['Q']=7;
    ranks['K']=8;
    ranks['A']=9;
    return ranks[card1[0]]>ranks[card2[0]];
  }
}

int main(){
  std::cin>>trump;
  std::cin>>card1>>card2;
  if(f()){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}