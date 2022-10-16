#include <iostream>

long long combo[100][100];

int main(){
  combo[0][0]=1;
  for(long long i=1;i<100;i++){
    combo[i][0]=1;
    combo[0][i]=1;
  }
  for(long long i=1;i<100;i++){
    for(long long j=1;j<100;j++){
      combo[i][j]=combo[i-1][j]+combo[i][j-1];
    }
  }
  
  long long N,M,T;
  long long total=0;
  std::cin>>N>>M>>T;
  for(long long boys=4;boys<=(T-1);boys++){
    long long girls=T-boys;
    if((boys<=N)&&(girls<=M)){
      total+=combo[N-boys][boys]*combo[M-girls][girls];
    }
  }
  std::cout<<total<<std::endl;
  return 0;
}