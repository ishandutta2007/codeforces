#include <cstdio>
#include <algorithm>

int uf[500005];
int size[500005];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    uf[i]=i;
  }
  while(M-->0){
    int K;
    scanf("%d",&K);
    int prev=-1;
    while(K-->0){
      int X;
      scanf("%d",&X);
      X--;
      if(prev!=-1){
	uf[find(X)]=find(prev);
      }
      prev=X;
    }
  }
  for(int i=0;i<N;i++){
    size[find(i)]++;
  }
  for(int i=0;i<N;i++){
    printf("%d\n",size[find(i)]);
  }
  return 0;
}