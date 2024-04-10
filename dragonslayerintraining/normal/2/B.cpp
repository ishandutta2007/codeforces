#include <cstdio>
#include <string>
#include <algorithm>

int N;

int pow2[1000][1000];
int pow5[1000][1000];
int dist[1000][1000];

char path[2005];

std::pair<int,std::string> shortest(int mat[1000][1000]){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      dist[i][j]=((i==0)&&(j==0))?0:1e9;
      if(j>0){
	dist[i][j]=std::min(dist[i][j],dist[i][j-1]);
      }
      if(i>0){
	dist[i][j]=std::min(dist[i][j],dist[i-1][j]);
      }
      dist[i][j]+=mat[i][j];
    }
  }
  int i=N-1,j=N-1;
  while((i>0)||(j>0)){
    if((i>0)&&(dist[i-1][j]+mat[i][j]==dist[i][j])){
      i--;
      path[i+j]='D';
    }else{
      j--;
      path[i+j]='R';
    }
  }
  return std::make_pair(dist[N-1][N-1],std::string(path));
}

int zero=-1;

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      int X;
      scanf("%d",&X);
      if(X){
	for(;X%2==0;X/=2){
	  pow2[i][j]++;
	}
	for(;X%5==0;X/=5){
	  pow5[i][j]++;
	}
      }else{
	pow2[i][j]=1e9;
	pow5[i][j]=1e9;
	zero=i;
      }
    }
  }
  auto res=std::min(shortest(pow2),shortest(pow5));
  if((res.first>1)&&(zero!=-1)){
    printf("1\n%s\n",(std::string(zero,'D')+std::string(N-1,'R')+std::string(N-1-zero,'D')).c_str());
  }else{
    printf("%d\n%s\n",res.first,res.second.c_str());
  }
  return 0;
}