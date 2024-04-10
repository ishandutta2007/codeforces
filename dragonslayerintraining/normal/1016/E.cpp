#include <cstdio>
#include <algorithm>
#include <stdint.h>

long double ls[200005];
long double rs[200005];
int prefix[200005];
int N;

long double query(long double x){
  auto it=std::upper_bound(ls,ls+N,x);
  if(it==ls) return 0;
  it--;
  int i=it-ls;
  return prefix[i]+std::min(x,rs[i])-ls[i];
}

int main(){
  int S,A,B;
  scanf("%d %d %d",&S,&A,&B);
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    ls[i]=L,rs[i]=R;
    prefix[i+1]=prefix[i]+R-L;
  }
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    long double tmp=query((long double)((int64_t)B*Y-(int64_t)S*X)/(Y-S))
      -query((long double)((int64_t)A*Y-(int64_t)S*X)/(Y-S));
    printf("%.10lf\n",(double)(tmp/Y*(Y-S)));
  }
  return 0;
}