#include <iostream>

int grid[50][50];
int prefix[51][51];

int M,N;
int A,B;

int best=1e9;

void test(int x0,int y0,int x1,int y1){
  best=std::min(best,prefix[x1][y1]-prefix[x1][y0]-prefix[x0][y1]+prefix[x0][y0]);
}

int main(){
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    prefix[i][0]=0;
  }
  for(int j=0;j<M;j++){
    prefix[0][j]=0;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      std::cin>>grid[i][j];
      prefix[i+1][j+1]=prefix[i][j+1]+prefix[i+1][j]-prefix[i][j]+
	grid[i][j];
    }
  }
  std::cin>>A>>B;
  for(int i=A;i<=N;i++){
    for(int j=B;j<=M;j++){
      test(i-A,j-B,i,j);
    }
  }
  for(int i=B;i<=N;i++){
    for(int j=A;j<=M;j++){
      test(i-B,j-A,i,j);
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}