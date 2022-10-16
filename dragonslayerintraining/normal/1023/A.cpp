#include <cstdio>
#include <cstdlib>
#include <cstring>

char S[200005];
char T[200005];

void fail(){
  printf("NO\n");
  exit(0);
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  scanf("%s %s",S,T);
  
  int wild=-1;
  for(int i=0;i<N;i++){
    if(S[i]=='*') wild=i;
  }
  if(wild==-1){
    if(strcmp(S,T)) fail();
  }else{
    if(M<N-1) fail();
    for(int i=0;i<N&&S[i]!='*';i++){
      if(S[i]!=T[i]){
	fail();
      }
    }
    for(int i=0;i<N&&S[N-1-i]!='*';i++){
      if(S[N-1-i]!=T[M-1-i]){
	fail();
      }
    }
  }
  printf("YES\n");
  return 0;
}