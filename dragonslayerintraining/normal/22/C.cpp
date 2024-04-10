#include <iostream>

long long N,M,V;

int cnt=0;

void connect(int a,int b){
  a=(a+V)%N+1;
  b=(b+V)%N+1;
  std::cout<<a<<" "<<b<<std::endl;
  cnt++;
}

int main(){
  std::cin>>N>>M>>V;
  V--;
  if(M<N-1){
    std::cout<<-1<<std::endl;
    return 0;
  }
  if(M-1>((N-1)*(N-2)/2)){
    std::cout<<-1<<std::endl;
    return 0;
  }
  connect(0,N-1);
  for(int i=1;i<N-1;i++){
    if(cnt>=M){
      break;
    }
    for(int j=0;j<N-1;j++){
      if(cnt>=M){
	break;
      }
      connect(j,(i+j)%(N-1));
    }
  }
  
  return 0;
}