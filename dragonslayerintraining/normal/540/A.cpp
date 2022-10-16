#include <iostream>

int main(){
  int N;
  std::cin>>N;
  std::string str1,str2;
  std::cin>>str1>>str2;
  int cost=0;
  for(int i=0;i<N;i++){
    int shift=(str1[i]+10-str2[i])%10;
    cost+=std::min(shift,10-shift);
  }
  std::cout<<cost<<std::endl;
  return 0;
}