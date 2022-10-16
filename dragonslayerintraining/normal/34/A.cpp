#include <iostream>
#include <algorithm>

int N;
int height[100];

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>height[i];
  }
  int best=1e9;
  int besti=0;
  for(int i=0;i<N;i++){
    int diff=std::abs(height[(i+1)%N]-height[i]);
    if(diff<best){
      best=diff;
      besti=i;
    }
  }
  std::cout<<besti+1<<" "<<(besti+1)%N+1<<std::endl;
  return 0;
}