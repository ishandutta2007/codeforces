#include <iostream>
#include <vector>

int compress(int n){
  std::vector<int> digits;
  for(;n>0;n/=10){
    if(n%10!=0){
      digits.push_back(n%10);
    }
  }
  int num=0;
  while(!digits.empty()){
    num=num*10+digits.back();
    digits.pop_back();
  }
  return num;
}

int main(){
  int A,B;
  std::cin>>A>>B;
  if(compress(A)+compress(B)==compress(A+B)){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}