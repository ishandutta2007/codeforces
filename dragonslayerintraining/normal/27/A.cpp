#include <iostream>

int used[3002];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int k;
    std::cin>>k;
    used[k]=1;
  }
  int i;
  for(i=1;used[i];i++);
  std::cout<<i<<std::endl;
  return 0;
}