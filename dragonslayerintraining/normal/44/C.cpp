#include <iostream>

int N,M;

int days[100];

int main(){
  std::cin>>N>>M;
  for(int i=0;i<M;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    for(int j=A;j<=B;j++){
      days[j]++;
    }
  }
  for(int i=0;i<N;i++){
    if(days[i]!=1){
      std::cout<<i+1<<" "<<days[i]<<std::endl;
      return 0;
    }
  }
  std::cout<<"OK"<<std::endl;
  return 0;
}