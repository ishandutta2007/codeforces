#include <cstdio>

int N;
char S[1000005];
char T[1000005];

int main(){
  scanf("%d",&N);
  scanf("%s %s",S,T);
  int cost=0;
  for(int i=0;i<N;i++){
    if(S[i]==T[i]) continue;
    cost++;
    if(i<N-1&&S[i+1]!=T[i+1]&&S[i]!=S[i+1]){
      i++;
    }
  }
  printf("%d\n",cost);
  return 0;
}