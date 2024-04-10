#include <iostream>
#include <algorithm>

int N,D;
int height[1000];

int main(){
  std::cin>>N>>D;
  for(int i=0;i<N;i++){
    std::cin>>height[i];
  }
  std::sort(height,height+N);
  int i=0;
  int cnt=0;
  for(int j=0;j<N;j++){
    while(height[j]-height[i]>D){
      i++;
    }
    cnt+=(j-i);
  }
  std::cout<<cnt*2<<std::endl;
  return 0;
}