#include <cstdio>

int as[100005];
int where[100005];
int ws[100005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    where[as[i]]=i;
  }
  for(int v=N;v>0;v--){
    int i=where[v];
    for(int j=i;j<N;j+=v){
      if(as[j]>as[i]&&!ws[j]){
	ws[i]=1;
      }
    }
    for(int j=i;j>=0;j-=v){
      if(as[j]>as[i]&&!ws[j]){
	ws[i]=1;
      }
    }
  }
  for(int i=0;i<N;i++){
    printf("%c",ws[i]?'A':'B');
  }
  printf("\n");
  return 0;
}