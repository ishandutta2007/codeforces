#include <iostream>

int ds[1000];
int ss[1000];

int main(){
  int M,K;
  std::cin>>M>>K;
  for(int i=0;i<M;i++){
    std::cin>>ds[i];
  }
  for(int i=0;i<M;i++){
    std::cin>>ss[i];
  }
  int best=0;
  int time=0;
  int fuel=0;
  for(int i=0;i<M;i++){
    fuel+=ss[i];
    best=std::max(best,ss[i]);
    time+=ds[i];
    fuel-=ds[i];
    //loop can be replaced by arithmetic, but isn't necessary
    while(fuel<0){
      time+=K;
      fuel+=best;
    }
  }
  std::cout<<time<<std::endl;
  return 0;
}