#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

char S[500005];
char T[500005];

int border1[500005];
int border2[500005];
int match1[500005];
int match2[500005];

int N,M,K;

void kmp(const char* S,const char* T,int* border,int* match){
  border[0]=-1;
  for(int i=0;T[i];i++){
    int k=border[i];
    while((k>=0)&&(T[k]!=T[i])){
      k=border[k];
    }
    border[i+1]=k+1;
    //printf("border[%d]=%d\n",i+1,k+1);
  }
  int m=0;
  match[0]=0;
  for(int i=0;S[i];i++){
    while((m>=0)&&(S[i]!=T[m])){
      m=border[m];
    }
    match[i+1]=++m;
    if(!T[m]){
      m=border[m];
    }
  }
}

int pos[500005];

int main(){
  scanf("%d %d %d %s %s",&N,&M,&K,S,T);
  kmp(S,T,border1,match1);
  for(int i=M;i<=N;i++){
    if(match1[i]==M){
      printf("Yes\n%d %d\n",1,K+1);
      return 0;
    }
  }
  std::reverse(S,S+N);
  std::reverse(T,T+M);
  kmp(S,T,border2,match2);
  std::reverse(S,S+N);
  std::reverse(T,T+M);
  std::reverse(match2,match2+N+1);
  /*
  for(int i=0;i<=N;i++){
    printf("%c%c\t%d\t%d\n",S[i],S[N-i],match1[i],match2[i]);
  }
  printf("\n");
  */
  std::fill(pos,pos+500005,-1);
  for(int i=K;i<=N-K;i++){
    for(int x=match1[i];x>=0&&pos[x]<0;x=border1[x]){
      //printf("POS %d\n",x);
      pos[x]=i-K+1;
    }
    if(match2[i]<=K&&M-match2[i]<=K){
      if(pos[M-match2[i]]!=-1){
	printf("Yes\n%d %d\n",pos[M-match2[i]],i+1);
	return 0;
      }
    }
    //printf("%c%c\t%d\t%d\n",S[i],S[N-i],match1[i],match2[i]);
  }
  printf("No\n");
  return 0;
}