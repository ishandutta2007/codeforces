#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
struct cnode{
  struct cnode* left,*right;
  int height;
  int size;
  T val;
  cnode(T val):left(NULL),right(NULL),height(1),size(1),val(val){
  }
  static int getheight(struct cnode* node){
    return node?node->height:0;
  }
  static int getsize(struct cnode* node){
    return node?node->size:0;
  }
  static int getbalance(struct cnode* node){
    return getheight(node->left)-getheight(node->right);
  }
  static void recalc(struct cnode* node){
    node->height=std::max(getheight(node->left),getheight(node->right))+1;
    node->size=getsize(node->left)+getsize(node->right)+1;
  }
  static struct cnode* rotateleft(struct cnode* node){
    struct cnode* p=node,*q=node->right,*r=node->right->left;
    p->right=r;
    q->left=p;
    recalc(p);
    recalc(q);
    return q;
  }
  static struct cnode* rotateright(struct cnode* node){
    struct cnode* p=node,*q=node->left,*r=node->left->right;
    p->left=r;
    q->right=p;
    recalc(p);
    recalc(q);
    return q;
  }
  static struct cnode* rebalance(struct cnode* node){
    int bal=getbalance(node);
    if(bal<-1){
      if(getbalance(node->right)>0){
	node->right=rotateright(node->right);
      }
      return rotateleft(node);
    }else if(bal>1){
      if(getbalance(node->left)<0){
	node->left=rotateleft(node->left);
      }
      return rotateright(node);
    }
    recalc(node);
    return node;
  }
  /*
  static struct cnode* insert(struct cnode* node,T val){
    if(node==NULL){
      return new cnode(val);
    }
    if(val<node->val){
      node->left=insert(node->left,val);
      return rebalance(node);
    }else if(node->val<val){
      node->right=insert(node->right,val);
      return rebalance(node);
    }else{
      return node;
    }
  }
   */
  static struct cnode* insertat(struct cnode* node,T val,int index){
    if(node==NULL){
      return new cnode(val);
    }
    if(index<=getsize(node->left)){
      node->left=insertat(node->left,val,index);
      return rebalance(node);
    }else{
      node->right=insertat(node->right,val,index-getsize(node->left)-1);
      return rebalance(node);
    }
  }
  static struct cnode* select(struct cnode* node,int index){
    if(node==NULL){
      return NULL;
    }
    if(index<getsize(node->left)){
      return select(node->left,index);
    }else if(index>getsize(node->left)){
      return select(node->right,index-getsize(node->left)-1);
    }else{
      return node;
    }
  }
  static void dump(struct cnode* node){
    if(node){
      dump(node->left);
      std::cout<<node->val<<" ";
      dump(node->right);
    }
  }
};

template<class T>
struct cavltree{
  struct cnode<T>* root;
  cavltree():root(NULL){
  }
  /*
  void insert(T val){
    root=cnode<T>::insert(root,val);
  }
  */
  void insertat(T val,int index){
    root=cnode<T>::insertat(root,val,index);
  }
  const T& select(int index){
    return cnode<T>::select(root,index)->val;
  }
  void dump(){
    cnode<T>::dump(root);
    std::cout<<std::endl;
  }
  int size(){
    return cnode<T>::getsize(root);
  }
};
/*

int main(){
  struct cavltree<int> tree;
  for(int i=0;i<1000000;i++){
    tree.insertat(i,i%4);
    tree.dump();
  }
  return 0;
}
*/

struct cman{
  std::string name;
  int A;
  int id;
  int height;
};
std::ostream& operator<<(std::ostream& out,struct cman man){
  return out<<"{"<<man.name<<","<<man.id<<"}";
}

struct cacmp{
  bool operator()(struct cman a,struct cman b)const{
    if(a.A!=b.A){
      return a.A<b.A;
    }
    return a.id<b.id;
  }
}acmp;
struct cidcmp{
  bool operator()(struct cman a,struct cman b)const{
    return a.id<b.id;
  }
}idcmp;

int main(){
  int N;
  std::cin>>N;
  std::vector<struct cman> men;
  for(int i=0;i<N;i++){
    struct cman man;
    std::cin>>man.name>>man.A;
    man.id=i; 
    men.push_back(man);
  }
  std::sort(men.begin(),men.end(),acmp);

  struct cavltree<struct cman> inorder;
  for(int i=0;i<N;i++){
    if(men[i].A>i){
      std::cout<<-1<<std::endl;
      return 0;
    }
    inorder.insertat(men[i],men[i].A);
    //inorder.dump();
  }
  std::sort(men.begin(),men.end(),idcmp);
  for(int i=0;i<N;i++){
    //std::cout<<i<<"\t"<<inorder.select(i).id<<std::endl;
    men[inorder.select(i).id].height=N-i;
  }
  std::sort(men.begin(),men.end(),acmp);
  for(int i=0;i<N;i++){
    std::cout<<men[i].name<<" "<<men[i].height<<std::endl;
  }
  return 0;
}