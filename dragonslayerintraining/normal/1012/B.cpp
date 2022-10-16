#include <cstdio>
#include <algorithm>

int uf[400000];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

int main(){
  int N,M,Q;
  scanf("%d %d %d",&N,&M,&Q);
  std::iota(uf,uf+N+M,0);
  for(int i=0;i<Q;i++){
    int R,C;
    scanf("%d %d",&R,&C);
    R--,C--;
    uf[find(R)]=find(C+N);
  }
  int ans=-1;
  for(int i=0;i<N+M;i++){
    if(uf[i]==i){
      ans++;
    }
  }
  printf("%d\n",ans);
  return 0;
}