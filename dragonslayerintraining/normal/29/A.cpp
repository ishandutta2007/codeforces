#include <iostream>

int N;
int camel[100];
int spit[100];

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>camel[i];
    std::cin>>spit[i];
    spit[i]+=camel[i];
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if((camel[i]==spit[j])&&(camel[j]==spit[i])){
	std::cout<<"YES"<<std::endl;
	return 0;
      }
    }
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}