#include <iostream>
#include <algorithm>

int as[100000];
int bs[100000];
int N;

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::copy(as,as+N,bs);
  std::sort(bs,bs+N);
  int wrong=0;
  for(int i=0;i<N;i++){
    wrong+=(as[i]!=bs[i]);
  }
  std::cout<<((wrong==2||wrong==0)?"YES":"NO")<<std::endl;
  return 0;
}