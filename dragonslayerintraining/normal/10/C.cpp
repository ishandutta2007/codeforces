#include <iostream>
#include <stdint.h>

int main(){
  int N;
  std::cin>>N;
  int64_t sum=0;
  for(int x=1;x<=N;x++){
    sum-=N/x;
  }
  int64_t cnt[9];
  for(int i=1;i<=9;i++){
    cnt[i%9]=(N+9-i)/9;
  }
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      sum+=cnt[i]*cnt[j]*cnt[(i*j)%9];
    }
  }
  std::cout<<sum<<std::endl;
  return 0;
}