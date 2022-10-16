#include <cstdio>

bool use[45005];

int main(){
  int N;
  scanf("%d",&N);
  if(N<3){
    printf("No\n");
    return 0;
  }else{
    printf("Yes\n");
  }
  int target=(N+1)/2;
  int used=0;
  for(int i=N;i>0;i--){
    if(target>=i){
      use[i]=true;
      used++;
      target-=i;
    }
  }
  printf("%d",used);
  for(int i=1;i<=N;i++){
    if(use[i]) printf(" %d",i);
  }
  printf("\n");
  printf("%d",N-used);
  for(int i=1;i<=N;i++){
    if(!use[i]) printf(" %d",i);
  }
  printf("\n");
  return 0;
}