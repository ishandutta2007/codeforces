#include <cstdio>

int as[300005];

int reach[19][300005];

void build(int w,int L,int R){
  if(L>=R) return;
  int M=(L+R)/2;
  int active[19];
  for(int k=0;k<19;k++){
    active[k]=(1<<k);
  }
  for(int i=M;i>=L;i--){
    for(int k=0;k<19;k++){
      if(as[i]&(1<<k)){
	reach[w][i]|=active[k];
      }
    }
    for(int k=0;k<19;k++){
      if(as[i]&(1<<k)){
	active[k]|=reach[w][i];
      }
    }
  }
  for(int k=0;k<19;k++){
    active[k]=(1<<k);
  }
  for(int i=M+1;i<=R;i++){
    for(int k=0;k<19;k++){
      if(as[i]&(1<<k)){
	reach[w][i]|=active[k];
      }
    }
    for(int k=0;k<19;k++){
      if(as[i]&(1<<k)){
	active[k]|=reach[w][i];
      }
    }
  }
  build(w+1,L,M);
  build(w+1,M+1,R);
}

bool query(int w,int L,int R,int a,int b){
  int M=(L+R)/2;
  if(b<=M) return query(w+1,L,M,a,b);
  if(a>M) return query(w+1,M+1,R,a,b);
  return reach[w][a]&reach[w][b];
}

int main(){
  int N,Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  build(0,0,N-1);
  while(Q--){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    if(query(0,0,N-1,X,Y)){
      printf("Shi\n");
    }else{
      printf("Fou\n");
    }
  }
  return 0;
}