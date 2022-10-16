#include <iostream>
#include <stdint.h>

int64_t pascal[1000][1000];

int main(){
  for(int64_t i=0;i<1000;i++){
    pascal[i][0]=1;
    pascal[0][i]=1;
  }
  for(int64_t i=1;i<1000;i++){
    for(int64_t j=1;j<1000;j++){
      pascal[i][j]=pascal[i][j-1]+pascal[i-1][j];
    }
  }
  int64_t N;
  std::cin>>N;
  std::cout<<pascal[N-7][7]+pascal[N-6][6]+pascal[N-5][5]<<std::endl;
  return 0;
}