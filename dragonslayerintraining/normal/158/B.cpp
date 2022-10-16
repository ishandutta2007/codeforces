#include <iostream>

int a[5];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int x;
    std::cin>>x;
    a[x]++;
  }
  int cnt=0;
  cnt+=a[4];
  cnt+=a[3];
  a[1]=std::max(0,a[1]-a[3]);
  cnt+=a[2]/2;
  a[2]%=2;
  cnt+=a[2];
  a[1]=std::max(0,a[1]-2*a[2]);
  cnt+=(a[1]+3)/4;
  std::cout<<cnt<<std::endl;
  
  return 0;
}