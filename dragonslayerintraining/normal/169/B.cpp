#include <iostream>

int digit[10];

int main(){
  std::string A,S;
  std::cin>>A;
  std::cin>>S;
  for(int i=0;i<S.size();i++){
    digit[S[i]-'0']++;
  }
  for(int d=9;d>=0;d--){
    for(int i=0;(i<A.size())&&(digit[d]>0);i++){
      if(A[i]<('0'+d)){
	A[i]='0'+d;
	digit[d]--;
      }
    }
  }
  std::cout<<A<<std::endl;
  return 0;
}