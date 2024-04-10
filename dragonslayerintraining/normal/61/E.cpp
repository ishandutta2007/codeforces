#include <iostream>
#include <cassert>

struct cnode{
  int v;
  int height;
  int size;
  struct cnode* left,*right;
  cnode(int v):v(v),height(1),size(1),left(NULL),right(NULL){
  }
  static int getheight(struct cnode* node){
    return node?node->height:0;
  }
  static int getsize(struct cnode* node){
    return node?node->size:0;
  }
  static int getbalance(struct cnode* node){
    return node?(getheight(node->left)-getheight(node->right)):0;
  }
  static void recalc(struct cnode* node){
    if(node){
      node->height=std::max(getheight(node->left),
			    getheight(node->right))+1;
      node->size=getsize(node->left)+getsize(node->right)+1;
    }
  }
  static struct cnode* rotateleft(struct cnode* node){
    assert(node);
    assert(node->right);
    struct cnode *p=node,*q=node->right,*r=node->right->left;
    q->left=p;
    p->right=r;
    recalc(p);
    recalc(q);
    return q;
  }
  static struct cnode* rotateright(struct cnode* node){
    assert(node);
    assert(node->left);
    struct cnode *p=node,*q=node->left,*r=node->left->right;
    q->right=p;
    p->left=r;
    recalc(p);
    recalc(q);
    return q;
  }
  static struct cnode* rebalance(struct cnode* node){
    assert(node);
    recalc(node);
    int bal=getbalance(node);
    if(bal<-1){
      if(getbalance(node->right)>=0){
	node->right=rotateright(node->right);
      }
      node=rotateleft(node);
    }else if(bal>1){
      if(getbalance(node->left)<=0){
	node->left=rotateleft(node->left);
      }
      node=rotateright(node);
    }
    return node;
  }
  static void destroy(struct cnode* node){
    if(node){
      destroy(node->left);
      destroy(node->right);
      delete node;
    }
  }
  static struct cnode* insert(struct cnode* node,int val){
    if(node==NULL){
      return new cnode(val);
    }
    if(val<node->v){
      node->left=insert(node->left,val);
      return rebalance(node);
    }else if(val>node->v){
      node->right=insert(node->right,val);
      return rebalance(node);
    }else{
      return node;
    }
  }
  static int countless(struct cnode* node,int val){
    if(node==NULL){
      return 0;
    }
    if(val<node->v){
      return countless(node->left,val);
    }else if(val>node->v){
      return getsize(node->left)+1+countless(node->right,val);
    }else{
      return getsize(node->left);
    }
  }
  static int countmore(struct cnode* node,int val){
    if(node==NULL){
      return 0;
    }
    if(val<node->v){
      return getsize(node->right)+1+countmore(node->left,val);
    }else if(val>node->v){
      return countmore(node->right,val);
    }else{
      return getsize(node->left);
    }
  }
};

struct cost{
  struct cnode* root;
  cost():root(NULL){
  }
  ~cost(){
    cnode::destroy(root);
  }
  void clear(){
    cnode::destroy(root);
    root=NULL;
  }
  void insert(int v){
    root=cnode::insert(root,v);
  }
  int countless(int v){
    return cnode::countless(root,v);
  }
  int countmore(int v){
    return cnode::countmore(root,v);
  }
};

int power[1000000];
int left[1000000];
int right[1000000];

int main(){
  struct cost ost;
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>power[i];
  }
  for(int i=0;i<N;i++){
    ost.insert(power[i]);
    left[i]=ost.countmore(power[i]);
  }
  ost.clear();
  for(int i=N-1;i>=0;i--){
    ost.insert(power[i]);
    right[i]=ost.countless(power[i]);
  }
  long long total=0;
  for(int i=0;i<N;i++){
    total+=(long long)left[i]*right[i];
  }
  std::cout<<total<<std::endl;
  return 0;
}