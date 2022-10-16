#include <iostream>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t pop[1001];
int64_t table[1001];

int64_t less[1001];

int main(){
  std::string N;
  int64_t K;
  std::cin>>N>>K;
  if(K==0){
    std::cout<<1<<std::endl;
    return 0;
  }
  K--;
  {
    N="0"+N;
    int64_t k=N.size()-1;
    while(N[k]=='1'){
      N[k]='0';
      k--;
    }
    N[k]='1';
    //std::cout<<"N="<<N<<std::endl;
  }
  for(int64_t i=1;i<=1000;i++){
    pop[i]=pop[i-(i&-i)]+1;
  }
  for(int64_t i=2;i<=1000;i++){
    table[i]=table[pop[i]]+1;
  }
  /*
    for(int64_t i=0;i<=1000;i++){
    std::cout<<i<<" "<<pop[i]<<" "<<table[i]<<std::endl;
    }
  */
  int64_t cnt=0;
  for(int64_t i=0;i<N.length();i++){
    for(int64_t k=1000;k>0;k--){
      less[k]=(less[k]+less[k-1])%MOD;
    }
    if(N[i]=='1'){
      less[cnt]=(less[cnt]+1)%MOD;
      cnt++;
    }
    /*
      std::cout<<"I="<<i<<"\t";
      for(int64_t k=0;k<10;k++){
      std::cout<<less[k]<<" ";
      }
      std::cout<<std::endl;
    */
  }
  
  less[1]--;
  int64_t sum=0;
  for(int64_t i=1;i<=1000;i++){
    if(table[i]==K){
      sum=(sum+less[i])%MOD;
    }
  }
  std::cout<<sum<<std::endl;
  return 0;
}