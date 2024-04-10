#include <iostream>
#include <iomanip>

int win[64][64];
double reach[7][64];
double champ[7][64];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<(1<<N);i++){
    for(int j=0;j<(1<<N);j++){
      std::cin>>win[i][j];
    }
  }
  for(int i=0;i<(1<<N);i++){
    reach[0][i]=1;
  }
  for(int k=1;k<=N;k++){
    for(int i=0;i<(1<<N);i++){
      for(int j=(1<<(k-1));j<(1<<k);j++){
	reach[k][i]+=reach[k-1][i^j]*(win[i][i^j]/100.);
      }
      reach[k][i]*=reach[k-1][i];
    }
  }
  for(int i=0;i<(1<<N);i++){
    reach[0][i]=0;
  }
  for(int k=1;k<=N;k++){
    for(int i=0;i<(1<<N);i++){
      reach[k][i]=(1<<(k-1))*reach[k][i]+reach[k-1][i];
    }
  }
  for(int i=0;i<(1<<N);i++){
    champ[0][i]=0;
  }
  for(int k=1;k<=N;k++){
    for(int i=0;i<(1<<N);i++){
      double score=reach[k][i];
      for(int l=1;l<k;l++){
	score+=champ[l][(i>>l)^1];
      }
      champ[k][i>>k]=std::max(champ[k][i>>k],score);
    }
  }
  std::cout<<std::fixed<<std::setprecision(10)<<champ[N][0]<<std::endl;
  return 0;
}