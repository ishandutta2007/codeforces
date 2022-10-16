#include <iostream>

int N,V;

int a[100],b[100];
int total=0;

int main(){
  std::cin>>N>>V;
  for(int i=0;i<N;i++){
    std::cin>>a[i];
    total+=a[i];
  }
  for(int i=0;i<N;i++){
    std::cin>>b[i];
  }
  double cook=V;
  for(int i=0;i<N;i++){
    cook=std::min(cook,double(b[i])*total/a[i]);
  }
  std::cout<<cook<<std::endl;
  return 0;
}