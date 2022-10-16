#include <cstdio>
#include <algorithm>

char S[100000];
char T[100000];

int match[100000];

int main(){
  int N,M,Q;
  scanf("%d %d %d",&N,&M,&Q);
  scanf("%s %s",S,T);
  for(int i=0;i<=N-M;i++){
    match[i+1]=match[i];
    if(std::equal(T,T+M,S+i)){
      match[i+1]++;
    }
  }
  for(int i=0;i<Q;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    printf("%d\n",(M>N)?0:((L-1>R-M+1)?0:std::max(0,match[R-M+1]-match[L-1])));
  }
  return 0;
}