#include <cstdio>
#include <cassert>

struct LCT{
  struct LCT* chd[2];
  struct LCT* parent;
  int size;
  LCT():size(1){
    chd[0]=chd[1]=parent=NULL;
  }
  static int get_size(struct LCT* x){
    return x?x->size:0;
  }
  void pull(){
    size=1+get_size(chd[0])+get_size(chd[1]);
  }
  static int which(struct LCT* x){
    assert(x);
    if(x&&x->parent&&x==x->parent->chd[0]) return 0;
    if(x&&x->parent&&x==x->parent->chd[1]) return 1;
    return 2;
  }
  static void set_child(struct LCT* x,int d,struct LCT* y){
    if(x&&d<2) x->chd[d]=y;
    if(y) y->parent=x;
  }
  static void rotate(struct LCT* x){
    struct LCT* y=x->parent;
    assert(y);
    int d=which(x);
    assert(d<2);
    struct LCT* z=x->chd[d^1];
    set_child(y->parent,which(y),x);
    set_child(x,d^1,y);
    set_child(y,d,z);
    y->pull();
    x->pull();
  }
  static void splay(struct LCT* x){
    assert(x);
    while(which(x)!=2){
      if(which(x->parent)!=2) rotate(which(x)==which(x->parent)?x->parent:x);
      rotate(x);
    }
  }
  static void access(struct LCT* x){
    assert(x);
    splay(x);
    set_child(x,1,NULL);
    x->pull();
    while(x->parent){
      splay(x->parent);
      set_child(x->parent,1,x);
      splay(x);
    }
  }
  static struct LCT* kth(struct LCT* x,int k){
    assert(x);
    assert(k>=0&&k<x->size);
    int lsize=get_size(x->chd[0]);
    if(k<lsize){
      return kth(x->chd[0],k);
    }else if(k>lsize){
      return kth(x->chd[1],k-lsize-1);
    }else{
      splay(x);
      return x;
    }
  }
  static struct LCT* link(struct LCT* x,struct LCT* y){
    access(x);
    if(y) access(y);
    assert(x!=y);
    assert(x->parent==NULL);
    assert(y==NULL||x->chd[0]==NULL);
    if(x->chd[0]){
      x->chd[0]->parent=NULL;
    }
    set_child(x,0,y);
    x->pull();
  }
}nodes[100005];

void dump(struct LCT* x){
  if(x){
    printf("(");
    dump(x->chd[0]);
    printf(" %d[#%d]",int(x-nodes),x->size);
    dump(x->chd[1]);
    printf(")");
  }
}

int N,M;

void set_power(int A,int B){
  LCT::link(&nodes[A],NULL);
  if(A+B<N){
    LCT::link(&nodes[A],&nodes[A+B]);
  }
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    int B;
    scanf("%d",&B);
    set_power(i,B);
  }
  for(int i=0;i<M;i++){
    int T;
    scanf("%d",&T);
    if(T==0){
      int A,B;
      scanf("%d %d",&A,&B);
      A--;
      set_power(A,B);
    }else{
      int A;
      scanf("%d",&A);
      A--;
      LCT::access(&nodes[A]);
      int jumps=nodes[A].size;
      int last=LCT::kth(&nodes[A],0)-nodes;
      printf("%d %d\n",last+1,jumps);
    }
  }
  return 0;
}