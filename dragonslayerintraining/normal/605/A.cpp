#include <iostream>

int N;
int inv[100000];

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    int P;
    std::cin>>P;
    P--;
    inv[P]=i;
  }
  int run=1;
  int best=1;
  for(int i=1;i<N;i++){
    if(inv[i]>inv[i-1]){
      run++;
    }else{
      run=1;
    }
    best=std::max(best,run);
  }
  std::cout<<N-best<<std::endl;
  return 0;
}