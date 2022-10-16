#include <cstdio>
#include <algorithm>

int table[1000][1000];
int rows[1000];
int cols[1000];

int main(){
  int N,M,K;
  scanf("%d %d %d",&N,&M,&K);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%d",&table[i][j]);
    }
  }
  for(int i=0;i<N;i++){
    rows[i]=i;
  }
  for(int j=0;j<M;j++){
    cols[j]=j;
  }
  for(int i=0;i<K;i++){
    char Q[2];
    int X,Y;
    scanf("%s %d %d",Q,&X,&Y);
    X--,Y--;
    if(Q[0]=='c'){
      std::swap(cols[X],cols[Y]);
    }else if(Q[0]=='r'){
      std::swap(rows[X],rows[Y]);
    }else{
      printf("%d\n",table[rows[X]][cols[Y]]);
    }
  }
  
  
  return 0;
}