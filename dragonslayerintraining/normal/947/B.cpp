#include <cstdio>
#include <algorithm>
#include <stdint.h>

const int64_t INF=1e9+7;

struct SegTree{
  int64_t cnt;
  int64_t sum;
  int64_t min;
  SegTree():cnt(0),sum(0),min(INF){
  }
}st[400000];

int64_t ts[100005];
int64_t vs[100005];

void pull(int64_t w,int64_t L,int64_t R){
  st[w].cnt=st[w*2+1].cnt+st[w*2+2].cnt;
  st[w].sum=st[w*2+1].sum+st[w*2+2].sum;
  st[w].min=std::min(st[w*2+1].min,st[w*2+2].min);
}

void update(int64_t w,int64_t L,int64_t R,int64_t i,int64_t v){
  if(i>=R||i<L) return;
  if(R-L==1){
    st[w].cnt=1;
    st[w].sum=v;
    st[w].min=v;
  }else{
    int64_t M=(L+R)/2;
    update(w*2+1,L,M,i,v);
    update(w*2+2,M,R,i,v);
    pull(w,L,R);
  }
}

int64_t kill(int64_t w,int64_t L,int64_t R,int64_t X,int64_t Y){
  if(st[w].cnt==0) return 0;
  if(st[w].min>=X){
    return (X-Y)*st[w].cnt;
  }
  if(R-L==1){
    int64_t res=st[w].sum-Y;
    st[w]=SegTree();
    return res;
  }else{
    int64_t M=(L+R)/2;
    int64_t res=kill(w*2+1,L,M,X,Y)+
      kill(w*2+2,M,R,X,Y);
    pull(w,L,R);
    return res;
  }
}
/*
void dump(int w,int L,int R){
  printf("st[%d,%d)=%I64d,%I64d,\n",L,R,st[w].min,st[w].cnt);
  if(R-L>1){
    int M=(L+R)/2;
    dump(w*2+1,L,M);
    dump(w*2+2,M,R);
  }
}
*/

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&vs[i]);
  }
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&ts[i]);
  }
  int64_t low=0;
  for(int64_t i=0;i<N;i++){
    update(0,0,N,i,low+vs[i]);
    //dump(0,0,N);
    if(i>0) printf(" ");
    printf("%I64d",kill(0,0,N,low+ts[i],low));
    //dump(0,0,N);
    low+=ts[i];
  }
  printf("\n");
  return 0;
}