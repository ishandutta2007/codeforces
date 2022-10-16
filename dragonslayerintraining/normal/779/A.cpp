#include <iostream>

int as[5],bs[5];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    A--;
    as[A]++;
  }
  for(int i=0;i<N;i++){
    int B;
    std::cin>>B;
    B--;
    bs[B]++;
  }
  int a2b=0;
  bool impossible=false;
  for(int i=0;i<5;i++){
    if(as[i]>bs[i]){
      int diff=as[i]-bs[i];
      if(diff%2==0){
	a2b+=diff/2;
      }else{
	impossible=true;
	break;
      }
    }
    if(as[i]<bs[i]){
      if((bs[i]-as[i])%2==1){
	impossible=true;
	break;
      }
    }
  }
  if(impossible){
    std::cout<<-1<<std::endl;
  }else{
    std::cout<<a2b<<std::endl;
  }
  return 0;
}