#include <iostream>

int h[1000];
int inc[1000];
int dec[1000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>h[i];
  }
  inc[0]=0;
  for(int i=1;i<N;i++){
    inc[i]=(h[i-1]<=h[i])?(inc[i-1]+1):0;
  }
  dec[N-1]=0;
  for(int i=N-2;i>=0;i--){
    dec[i]=(h[i]>=h[i+1])?(dec[i+1]+1):0;
  }
  int best=0;
  for(int i=0;i<N;i++){
    best=std::max(best,inc[i]+dec[i]+1);
  }
  std::cout<<best<<std::endl;
  return 0;
}