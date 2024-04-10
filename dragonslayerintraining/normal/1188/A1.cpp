#include <cstdio>

int deg[100005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    deg[A]++,deg[B]++;
  }
  for(int i=0;i<N;i++){
    if(deg[i]==2){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}