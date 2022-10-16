#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stdint.h>

struct Seg{
  int64_t end;
  int64_t A,B;
  Seg(int64_t end,int64_t A,int64_t B):end(end),A(A),B(B){
  }
};

struct PolyLine{
  std::vector<struct Seg> segs;
  PolyLine(){
  }
  PolyLine(int64_t X1,int64_t X2,int64_t Y1,int64_t A,int64_t B,int64_t Y2){
    segs.emplace_back(X1,0,Y1);
    segs.emplace_back(X2,A,B);
    segs.emplace_back(1e9,0,Y2);
  }
  struct PolyLine merge(struct PolyLine other)const{
    struct PolyLine ret;
    int i=0,j=0;
    int64_t x;
    do{
      x=std::min(segs[i].end,other.segs[j].end);

      ret.segs.emplace_back(x,
			    segs[i].A+other.segs[j].A,
			    segs[i].B+other.segs[j].B);
      if(segs[i].end==x){
	i++;
      }
      if(other.segs[j].end==x){
	j++;
      }
    }while(x<1e9);
    return ret;
  }
  int64_t eval(int64_t x){
    int low=-1,high=segs.size()-1;
    while(high-low>1){
      int mid=(low+high)/2;
      if(segs[mid].end<x){
	low=mid;
      }else{
	high=mid;
      }
    }
    //fprintf(stderr,"Eval(%d)=%dx+%d\n",x,segs[high].A,segs[high].B);
    return segs[high].A*x+segs[high].B;
  }
};

int N;

std::vector<struct PolyLine> seq;

struct PolyLine st[300000];

void build(int w,int L,int R){
  if(R-L==1){
    st[w]=seq[L];
  }else{
    int M=(L+R)/2;
    build(w*2+1,L,M);
    build(w*2+2,M,R);
    st[w]=st[w*2+1].merge(st[w*2+2]);
  }
  /*
  fprintf(stderr,"Polyline[%d]=\n",w);
  for(struct Seg seg:st[w].segs){
    fprintf(stderr,"%d: %dx+%d\n",seg.end,seg.A,seg.B);
  }
  fprintf(stderr,"\n");
  */
}
void build(){
  build(0,0,N);
}

int64_t query(int w,int L,int R,int a,int b,int64_t x){
  if((b<=L)||(a>=R)){
    return 0;
  }
  //fprintf(stderr,"query(%d,%d,%d,%d,%d,%d)\n",w,L,R,a,b,x);
  if((a<=L)&&(b>=R)){
    //fprintf(stderr,"Query: %d\n",w);
    return st[w].eval(x);
  }else{
    int M=(L+R)/2;
    return query(w*2+1,L,M,a,b,x)+query(w*2+2,M,R,a,b,x);
  }
}
int64_t query(int a,int b,int64_t x){
  return query(0,0,N,a,b,x);
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int X1,X2,Y1,A,B,Y2;
    scanf("%d %d %d %d %d %d",&X1,&X2,&Y1,&A,&B,&Y2);
    seq.emplace_back(X1,X2,Y1,A,B,Y2);
  }
  build();
  int M;
  scanf("%d",&M);
  int64_t last=0;
  for(int i=0;i<M;i++){
    int L,R,X;
    scanf("%d %d %d",&L,&R,&X);
    last=query(L-1,R,(X+last)%(1000*1000*1000));
    printf("%I64d\n",last);
  }
  return 0;
}