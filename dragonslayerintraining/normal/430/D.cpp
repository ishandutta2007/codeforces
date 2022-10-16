#include <iostream>

int as[1002][1002];
int tl[1002][1002];
int tr[1002][1002];
int bl[1002][1002];
int br[1002][1002];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      std::cin>>as[i][j];
    }
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      tl[i][j]=as[i][j]+std::max(tl[i-1][j],tl[i][j-1]);
    }
  }
  for(int i=N;i>=1;i--){
    for(int j=1;j<=M;j++){
      tr[i][j]=as[i][j]+std::max(tr[i+1][j],tr[i][j-1]);
    }
  }
  for(int i=1;i<=N;i++){
    for(int j=M;j>=1;j--){
      bl[i][j]=as[i][j]+std::max(bl[i-1][j],bl[i][j+1]);
    }
  }
  for(int i=N;i>=1;i--){
    for(int j=M;j>=1;j--){
      br[i][j]=as[i][j]+std::max(br[i+1][j],br[i][j+1]);
    }
  }
  int gain=0;
  for(int i=2;i<=N-1;i++){
    for(int j=2;j<=M-1;j++){
      gain=std::max(gain,tl[i][j-1]+tr[i+1][j]+br[i][j+1]+bl[i-1][j]);
      gain=std::max(gain,tl[i-1][j]+tr[i][j-1]+br[i+1][j]+bl[i][j+1]);
    }
  }
  std::cout<<gain<<std::endl;
  return 0;
}