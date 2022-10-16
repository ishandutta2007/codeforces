#include <cstdio>
#include <cstring>
#include <vector>

int N;

std::vector<int> children[200000];
int pre[200000],post[200000];
int time=0;

void dfs(int node){
  pre[node]=time++;
  for(int child:children[node]){
    dfs(child);
  }
  post[node]=time;
}

int ts[200000];

int on[800000];
int off[800000];
int lazy[800000];

void push(int w,int L,int R){
  if(lazy[w]){
    std::swap(on[w],off[w]);
    lazy[w]=0;
    if(R-L>1){
      lazy[w*2+1]^=1;
      lazy[w*2+2]^=1;
    }
  }
}
void build(int w,int L,int R){
  if(R-L==1){
    on[w]=ts[L];
    off[w]=!ts[L];
    return;
  }
  int M=(L+R)/2;
  build(w*2+1,L,M);
  build(w*2+2,M,R);
  on[w]=on[w*2+1]+on[w*2+2];
  off[w]=off[w*2+1]+off[w*2+2];
}

int query(int w,int L,int R,int a,int b){
  push(w,L,R);
  if((b<=L)||(a>=R)){
    return 0;
  }
  if((a<=L)&&(b>=R)){
    return on[w];
  }
  int M=(L+R)/2;
  return query(w*2+1,L,M,a,b)+
    query(w*2+2,M,R,a,b);
}

int query(int a,int b){
  return query(0,0,N,a,b);
}

void toggle(int w,int L,int R,int a,int b){
  push(w,L,R);
  if((b<=L)||(a>=R)){
    return;
  }
  if((a<=L)&&(b>=R)){
    lazy[w]^=1;
    push(w,L,R);
    return;
  }
  int M=(L+R)/2;
  toggle(w*2+1,L,M,a,b);
  toggle(w*2+2,M,R,a,b);
  on[w]=on[w*2+1]+on[w*2+2];
  off[w]=off[w*2+1]+off[w*2+2];
}

void toggle(int a,int b){
  toggle(0,0,N,a,b);
}

int main(){
  scanf("%d",&N);
  for(int i=1;i<N;i++){
    int P;
    scanf("%d",&P);
    children[P-1].push_back(i);
  }
  dfs(0);
  for(int i=0;i<N;i++){
    scanf("%d",&ts[pre[i]]);
  }
  build(0,0,N);
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    char str[10];
    int X;
    scanf("%s %d",str,&X);
    if(!strcmp(str,"get")){
      printf("%d\n",query(pre[X-1],post[X-1]));
    }else if(!strcmp(str,"pow")){
      toggle(pre[X-1],post[X-1]);
    }else{
      fprintf(stderr,"INVALID QUERY\n");
    }
  }
  return 0;
}