#include <cstdio>

char str[200005];
char ans[200005];
int len=0;

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  scanf("%s",str);
  for(int i=0;i<N;i++){
    if(str[i]=='('){
      ans[len++]='(';
    }else if(K<N){
      ans[--len]='\0';
      K+=2;
    }else{
      ans[len++]=')';
    }
  }
  printf("%s\n",ans);
  return 0;
}