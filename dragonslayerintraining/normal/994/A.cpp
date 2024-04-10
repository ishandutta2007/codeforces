#include <cstdio>

int xs[10];

bool good[10];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&xs[i]);
  }
  for(int i=0;i<M;i++){
    int Y;
    scanf("%d",&Y);
    good[Y]=true;
  }
  bool first=true;
  for(int i=0;i<N;i++){
    if(good[xs[i]]){
      if(first) first=false; else printf(" ");
      printf("%d",xs[i]);
    }
  }
  printf("\n");
  return 0;
}