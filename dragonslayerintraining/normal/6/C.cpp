#include <iostream>

int cost[100000];
int N;

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>cost[i];
  }
  int a=0,b=0;
  int at=0,bt=0;
  while(a+b<N){
    if(at<=bt){
      at+=cost[a];
      a++;
    }else{
      bt+=cost[N-b-1];
      b++;
    }
  }
  std::cout<<a<<" "<<b<<std::endl;
  
  return 0;
}