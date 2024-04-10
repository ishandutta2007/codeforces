#include <cstdio>
#include <cassert>
#include <map>

int as[200000];

struct SegTree{
  struct SegTree* left,*right;
  SegTree():left(NULL),right(NULL){
  }
  static void insert(struct SegTree*& node,int L,int R,int i){
    assert((i>=L)&&(i<R));
    if(node==NULL){
      node=new SegTree();
    }
    if(R-L==1){
      return;
    }
    int M=(L+R)/2;
    if(i<M){
      insert(node->left,L,M,i);
    }else{
      insert(node->right,M,R,i);
    }
  }
  //After a call to transfer with a<=L and R<=b, x becomes NULL
  static void transfer(struct SegTree*& x,struct SegTree*& y,int L,int R,int a,int b){
    if((a>=R)||(b<=L)){
      return;
    }
    if((a<=L)&&(b>=R)){
      //transfer entire range
      if(x==NULL){
	return;
      }
      if(y==NULL){
	std::swap(x,y);
	return;
      }
      int M=(L+R)/2;
      transfer(x->left,y->left,L,M,a,b);
      transfer(x->right,y->right,M,R,a,b);
      assert(x->left==NULL);
      assert(x->right==NULL);
      delete x;
      x=NULL;
    }else{
      assert(R-L>1);
      int M=(L+R)/2;
      struct SegTree* xleft=x?x->left:NULL;
      struct SegTree* yleft=y?y->left:NULL;
      struct SegTree* xright=x?x->right:NULL;
      struct SegTree* yright=y?y->right:NULL;
      transfer(xleft,yleft,L,M,a,b);
      transfer(xright,yright,M,R,a,b);
      if(x){
	if((xleft==NULL)&&(xright==NULL)){
	  delete x;
	  x=NULL;
	}else{
	  x->left=xleft;
	  x->right=xright;
	}
      }
      if((yleft||yright)&&(y==NULL)){
	y=new SegTree();
      }
      if(y){
	y->left=yleft;
	y->right=yright;
      }
    }
  }
  static void recover(struct SegTree* node,int L,int R,int v){
    if(node==NULL){
      return;
    }
    if(R-L==1){
      as[L]=v;
      return;
    }
    int M=(L+R)/2;
    recover(node->left,L,M,v);
    recover(node->right,M,R,v);
  }
};

std::map<int,struct SegTree*> value;

int main(){
  int N,Q;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    SegTree::insert(value[A],0,N,i);
  }
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int L,R,X,Y;
    scanf("%d %d %d %d",&L,&R,&X,&Y);
    if(X!=Y){
      SegTree::transfer(value[X],value[Y],0,N,L-1,R);
    }
  }
  for(std::pair<const int,struct SegTree*> pair:value){
    SegTree::recover(pair.second,0,N,pair.first);
  }
  for(int i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",as[i]);
  }
  printf("\n");
  return 0;
}