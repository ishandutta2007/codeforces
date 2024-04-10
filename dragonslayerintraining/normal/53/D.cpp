#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
#include <set>
#include <vector>

template<class T>
struct cavl{
  T v;
  int height;
  int size;
  struct cavl* left,*right;
  cavl(T v):v(v),height(1),size(1),left(NULL),right(NULL){
  }
  static int getheight(struct cavl* node){
    return node?node->height:0;
  }
  static int getsize(struct cavl* node){
    return node?node->size:0;
  }
  static int getbalance(struct cavl* node){
    return node?(getheight(node->left)-getheight(node->right)):0;
  }
  static void recalc(struct cavl* node){
    if(node){
      node->height=std::max(getheight(node->left),getheight(node->right))+1;
      node->size=getsize(node->left)+getsize(node->right)+1;
    }
  }
  static struct cavl* rotateleft(struct cavl* node){
    assert(node);
    assert(node->right);
    struct cavl* p=node,*q=node->right,*r=node->right->left;
    p->right=r;
    q->left=p;
    recalc(p);
    recalc(q);
    return q;
  }
  static struct cavl* rotateright(struct cavl* node){
    assert(node);
    assert(node->left);
    struct cavl* p=node,*q=node->left,*r=node->left->right;
    p->left=r;
    q->right=p;
    recalc(p);
    recalc(q);
    return q;
  }
  static struct cavl* rebalance(struct cavl* node){
    assert(node);
    int bal=getbalance(node);
    if(bal>0){
      if(getbalance(node->left)<0){
	node->left=rotateleft(node->left);
      }
      return rotateright(node);
    }else if(bal<0){
      if(getbalance(node->right)>0){
	node->right=rotateright(node->right);
      }
      return rotateleft(node);
    }else{
      return node;
    }
  }
  static struct cavl* insert(struct cavl* node,T v){
    if(node==NULL){
      return new cavl(v);
    }
    if(v<node->v){
      node->left=insert(node->left,v);
      return rebalance(node);
    }else if(v>node->v){
      node->right=insert(node->right,v);
      return rebalance(node);
    }else{
      return node;
    }
  }
  static int rank(struct cavl* node,T v){
    assert(node);
    if(v<node->v){
      return rank(node->left,v);
    }else if(v>node->v){
      return getsize(node->left)+1+rank(node->right,v);
    }else{
      return getsize(node->left);
    }
  }
  static void destroy(struct cavl* node){
    if(node){
      destroy(node->left);
      destroy(node->right);
      delete node;
    }
  }
};

template<class T>
struct cost{
  std::multiset<T> counts;
  typedef std::pair<T,int> U;
  struct cavl<U>* root;
  cost():root(NULL){
  }
  ~cost(){
    cavl<U>::destroy(root);
  }
  void insert(T v){
    root=cavl<U>::insert(root,std::pair<T,int>(v,counts.count(v)));
    counts.insert(v);
  }
  int rank(U v){
    return cavl<U>::rank(root,v);
  }
};

int A[300];

std::map<int,std::map<int,int> > order;

int main(){
  int N;
  std::cin>>N;
  std::multiset<int> counts;
  for(int i=0;i<N;i++){
    int num;
    std::cin>>num;
    order[num][counts.count(num)]=i;
    counts.insert(num);
  }
  counts.clear();
  for(int i=0;i<N;i++){
    int num;
    std::cin>>num;
    A[i]=order[num][counts.count(num)];
    counts.insert(num);
    //std::cerr<<A[i]<<" ";
  }
  //std::cerr<<std::endl;
  std::vector<int> swaps;
  for(int i=0;i<N;i++){
    for(int j=i;j>0;j--){
      if(A[j-1]<A[j]){
	break;
      }
      std::swap(A[j-1],A[j]);
      swaps.push_back(j);
    }
  }
  std::cout<<swaps.size()<<std::endl;
  for(int i=0;i<swaps.size();i++){
    std::cout<<swaps[i]<<" "<<swaps[i]+1<<std::endl;
  }
  return 0;
}