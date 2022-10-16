#include <iostream>

int N;

int norm(int x,int y){
  if(y==0){
    return x;
  }else if(y==N){
    return N*3-x;
  }else if(x==0){
    return N*4-y;
  }else{
    return N+y;
  }
}

int main(){
  int X1,Y1,X2,Y2;
  std::cin>>N>>X1>>Y1>>X2>>Y2;
  int diff=(N*4+norm(X1,Y1)-norm(X2,Y2))%(N*4);
  if(diff>N*2){
    diff=N*4-diff;
  }
  std::cout<<diff<<std::endl;
  return 0;
}