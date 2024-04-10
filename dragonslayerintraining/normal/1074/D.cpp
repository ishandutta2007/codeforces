#include <cstdio>
#include <cassert>
#include <map>

std::map<int,int> uf,delta,size;

void compress(int x){
  if(!uf.count(x)){
    uf[x]=x;
    delta[x]=0;
    size[x]=1;
  }
  if(x==uf[x]) return;
  compress(uf[x]);
  delta[x]^=delta[uf[x]];
  size[x]+=size[uf[x]];
  uf[x]=uf[uf[x]];
}

int main(){
  int Q;
  scanf("%d",&Q);
  int last=0;
  for(int i=0;i<Q;i++){
    int T;
    scanf("%d",&T);
    int L,R,X;
    scanf("%d %d",&L,&R);
    L^=last,R^=last;
    if(L>R) std::swap(L,R);
    compress(L),compress(++R);
    if(T==1){
      scanf("%d",&X);
      X^=last;
      if(uf[L]==uf[R]) continue;
      if(size[L]>size[R]) std::swap(L,R);
      X^=delta[L],L=uf[L];
      assert(uf[L]==L);
      assert(delta[L]==0);
      uf[L]=R;
      delta[L]=X;
    }else{
      if(uf[L]==uf[R]){
	printf("%d\n",last=(delta[L]^delta[R]));
      }else{
	printf("-1\n");
	last=1;
      }
    }
  }
  return 0;
}