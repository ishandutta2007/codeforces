#include <cstdio>
#include <vector>

std::vector<int> conn[100000];

int as[100000];
int depth[100000];
std::vector<int> bydepth[100000];

int pre[100000];
int post[100000];
int pre_max=0;

void dfs(int node,int parent,int d){
  depth[node]=d;
  bydepth[d].push_back(node);
  pre[node]=pre_max++;
  for(int child:conn[node]){
    if(child!=parent){
      dfs(child,node,d+1);
    }
  }
  post[node]=pre_max;
}

struct ST{
  int min;
  struct ST* left,*right;
  ST(int L,int R):min(1e9){
    if(R-L>1){
      int M=(L+R)/2;
      left=new ST(L,M);
      right=new ST(M,R);
    }else{
      left=NULL;
      right=NULL;
    }
  }
  ST(int v):min(v),left(NULL),right(NULL){
  }
  ST(struct ST* left,struct ST* right):
    min(std::min(left->min,right->min)),
    left(left),right(right){
  }
  int query(int L,int R,int a,int b){
    if((a>=R)||(b<=L)){
      return 1e9;
    }
    if((a<=L)&&(b>=R)){
      return min;
    }
    int M=(L+R)/2;
    return std::min(left->query(L,M,a,b),right->query(M,R,a,b));
  }
  struct ST* update(int L,int R,int i,int v){
    if((i<L)||(i>=R)){
      return this;
    }
    if(R-L==1){
      return new ST(v);
    }
    int M=(L+R)/2;
    return new ST(left->update(L,M,i,v),
		  right->update(M,R,i,v));
  }
  void dump(int L,int R){
    if(R-L==1){
      printf("%d",min);
    }else{
      int M=(L+R)/2;
      printf(" ");
      left->dump(L,M);
      printf(" ");
      right->dump(M,R);
    }
  }
};

struct ST* layer[100000];

int main(){
  int R,N;
  scanf("%d %d",&N,&R);
  R--;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=1;i<N;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    conn[X].push_back(Y);
    conn[Y].push_back(X);
  }
  dfs(R,R,0);
  /*
  for(int i=0;i<N;i++){
    printf("pre[%d]=%d\tpost[%d]=%d\n",i,pre[i],i,post[i]);
  }
  */
  struct ST* st=new ST(0,N);
  for(int l=0;l<100000;l++){
    for(int node:bydepth[l]){
      st=st->update(0,N,pre[node],as[node]);
    }
    layer[l]=st;
    //printf("%d: \n",l);
    //layer[l]->dump(0,N);
  }
  int M;
  scanf("%d",&M);
  int last=0;
  for(int i=0;i<M;i++){
    int P,Q;
    scanf("%d %d",&P,&Q);
    int X=(P+last)%N;//no ++ or --
    int K=(Q+last)%N;
    //printf("Q: %d %d\n",X,K);
    //layer[std::min(depth[X]+K,100000-1)]->dump(0,N);
    last=layer[std::min(depth[X]+K,100000-1)]->query(0,N,pre[X],post[X]);
    printf("%d\n",last);
  }
    
  return 0;
}