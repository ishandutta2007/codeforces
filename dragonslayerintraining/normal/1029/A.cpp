#include <cstdio>
#include <cstring>

char T[64];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  scanf("%s",T);
  int match;
  for(match=N-1;match>0;match--){
    if(!strncmp(T,T+N-match,match)){
      break;
    }
  }
  for(int i=0;i<match;i++){
    putchar(T[i]);
  }
  while(K-->0){
    for(int i=match;i<N;i++){
      putchar(T[i]);
    }
  }
  putchar('\n');
  return 0;
}