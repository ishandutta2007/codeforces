#include <cstdio>
#include <cassert>
#include <algorithm>

const int INF=1e9+7;

struct Node{
  int min,max;
  int low,high;
  int lcnt,rcnt,cnt;
}st[2000000];
int as[500005];

//[low,high]
int query(int w,int L,int R,int& low,int& high){
  //printf("query[%d,%d): [%d,%d]\n",L,R,low,high);
  if(R-L==1){
    return as[L]>=low&&as[L]<=high;
  }
  int M=(L+R)/2;
  if(low>st[w].max) return 0;
  if(high<st[w].min) return 0;
  if(low<=st[w].min&&high>=st[w].max) return st[w].cnt;
  if(low>st[w].high){
    return query(w*2+1,L,M,low,high);
  }else if(high<st[w].low){
    return query(w*2+2,M,R,low,high);
  }else{
    high=std::max(high,st[w].high);
    low=std::min(low,st[w].low);
    int res=0;
    int ign1,ign2;
    if(high>st[w].high) res+=query(w*2+1,L,M,ign1=st[w].high+1,high);
    if(low<st[w].low) res+=query(w*2+2,M,R,low,ign2=st[w].low-1);
    if(low<=st[w].low&&high>=st[w].high&&st[w].low<=st[w].high) res++;
    //printf("query[%d,%d): [%d,%d]=%d\n",L,R,low,high,res);
    return res;
  }
}

void pull(int w,int L,int R){
  int ign1,ign2;
  assert(R-L>1);
  int M=(L+R)/2;
  st[w].min=std::min(st[w*2+1].min,st[w*2+2].min);
  st[w].max=std::max(st[w*2+1].max,st[w*2+2].max);
  st[w].high=st[w*2+2].max;
  st[w].low=st[w*2+1].min;
  //printf("pull[%d,%d)\n",L,R);
  query(w*2+1,L,M,st[w].low,st[w].high);
  query(w*2+2,M,R,st[w].low,st[w].high);
  //printf("pull[%d,%d)*\n",L,R);
  if(st[w].low<=st[w].high){
    //intersects
    st[w].lcnt=query(w*2+1,L,M,ign1=st[w].high+1,ign2=INF);
    st[w].rcnt=query(w*2+2,M,R,ign1=-INF,ign2=st[w].low-1);
    st[w].cnt=st[w].lcnt+st[w].rcnt+1;
  }else{
    st[w].lcnt=st[w*2+1].cnt;
    st[w].rcnt=st[w*2+2].cnt;
    st[w].cnt=st[w].lcnt+st[w].rcnt;
  }
}

void build(int w,int L,int R,int a,int b){
  if(a>=R||b<=L) return;
  if(R-L==1){
    st[w].min=st[w].max=as[L];
    st[w].cnt=1;
  }else{
    int M=(L+R)/2;
    build(w*2+1,L,M,a,b);
    build(w*2+2,M,R,a,b);
    pull(w,L,R);
  }
}

void dump(int w,int L,int R){
  int M=(L+R)/2;
  if(R-L>1){
    printf("[%d,%d): min=%d max=%d low=%d high=%d lcnt=%d rcnt=%d cnt=%d\n",L,R,
	   st[w].min,st[w].max,st[w].low,st[w].high,st[w].lcnt,st[w].rcnt,st[w].cnt);
    dump(w*2+1,L,M);
    dump(w*2+2,M,R);
  }
}


int main(){
  int N,Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  build(0,0,N,0,N);
  for(int i=0;i<Q;i++){
    int I,X;
    scanf("%d %d",&I,&X);
    I--;
    as[I]=X;
    build(0,0,N,I,I+1);
    printf("%d\n",st[0].cnt);
    //dump(0,0,N);
  }
}