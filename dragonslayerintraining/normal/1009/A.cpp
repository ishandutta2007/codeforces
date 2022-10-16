#include <cstdio>

int cs[1000];
int as[1000];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&cs[i]);
  }
  for(int i=0;i<M;i++){
    scanf("%d",&as[i]);
  }
  int j=0;
  for(int i=0;i<N;i++){
    if(cs[i]<=as[j]){
      if(++j==M){
	break;
      }
    }
  }
  printf("%d\n",j);
  return 0;
}