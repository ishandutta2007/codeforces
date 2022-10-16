#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int ds[100];
int hs[100];

int solve(){
  int N,X;
  scanf("%d %d",&N,&X);
  for(int i=0;i<N;i++){
    scanf("%d %d",&ds[i],&hs[i]);
  }
  int last=*std::max_element(ds,ds+N);
  if(last>=X) return 1;
  int dec=0;
  for(int i=0;i<N;i++){
    dec=std::max(dec,ds[i]-hs[i]);
  }
  if(dec==0) return -1;
  //X-?*dec<=last
  //?*dec>=X-last
  //?>=(X-last)/dec
  return (X-last+dec-1)/dec+1;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    printf("%d\n",solve());
  }
}