#include <cstdio>

int N,K;

char out[1000005];

int main(){
  scanf("%d %d",&N,&K);
  if(K>N){
    printf("-1\n");
    return 0;
  }
  if(K==1){
    if(N==1){
      printf("a\n");
    }else{
      printf("-1\n");
    }
  }else{
    for(int i=0;i<N-K+2;i++){
      out[i]='a'+i%2;
    }
    for(int i=0;i<K-2;i++){
      out[N-K+2+i]='c'+i;
    }
    out[N]='\0';
    printf("%s\n",out);
  }
  return 0;
}