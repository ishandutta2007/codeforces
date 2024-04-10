#include <iostream>

unsigned long long a[36][36];

int main(){
  int N,H;
  std::cin>>N>>H;
  a[0][0]=1;
  for(int i=1;i<=N;i++){
    a[i][0]=1;
    for(int j=1;j<=N;j++){
      for(int k=0;k<j;k++){
	a[i][j]+=a[i-1][k]*a[i-1][j-1-k];
      }
    }
  }
  std::cout<<a[N][N]-a[H-1][N]<<std::endl;
  return 0;
}