#include <cstdio>

const int SQRT=500;

int xs[200005];
int ys[200005];
int last[200005];

int delta[200005];
int periodic[SQRT][SQRT];

int curr=0;
int t=0;
int N,M;

void add(int start,int end,int period,int cnt){
  if(period<SQRT){
    periodic[period][start%period]+=cnt;
    periodic[period][end%period]-=cnt;
    if(start%period<end%period){
      if((t%period>=start%period)&&(t%period<end%period)){
	curr+=cnt;
      }
    }else{
      if((t%period>=start%period)||(t%period<end%period)){
	curr+=cnt;
      }
    }
  }else{
    for(;start<M;start+=period,end+=period){
      delta[start]+=cnt;
      if(end<M){
	delta[end]-=cnt;
      }
      if(t>=start&&t<end){
	curr+=cnt;
      }
    }
  }
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d %d",&xs[i],&ys[i]);
  }
  for(t=0;t<M;t++){
    for(int i=1;i<SQRT;i++){
      curr+=periodic[i][t%i];
    }
    curr+=delta[t];
    int T,K;
    scanf("%d %d",&T,&K);
    K--;
    if(T==1){
      add(t+xs[K],t+xs[K]+ys[K],xs[K]+ys[K],1);
      last[K]=t;
    }else{
      add(last[K]+xs[K],last[K]+xs[K]+ys[K],xs[K]+ys[K],-1);
    }
    printf("%d\n",curr);
  }
}