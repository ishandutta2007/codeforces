#include <cstdio>

int as[1005];
int bs[1005];

int main(){
  int N,S;
  scanf("%d %d",&N,&S);
  S--;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&bs[i]);
  }
  if(!as[0]){
    printf("NO\n");
    return 0;
  }
  if(as[S]){
    printf("YES\n");
    return 0;
  }
  if(!bs[S]){
    printf("NO\n");
    return 0;
  }
  for(int i=S+1;i<N;i++){
    if(as[i]&&bs[i]){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}