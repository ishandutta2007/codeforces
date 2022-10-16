#include <iostream>
#include <stdint.h>

struct aa{
  struct aa* left,*right;
  int64_t level;
  int64_t val;
  int64_t size;
  int64_t sum[5];
  static struct aa* nil;
private:
  aa():left(this),right(this),level(0),size(0){
    for(int64_t i=0;i<5;i++){
      sum[i]=0;
    }
  }
public:
  aa(int64_t val):left(nil),right(nil),level(1),val(val),size(1){
    for(int64_t i=0;i<5;i++){
      sum[i]=0;
    }
    sum[0]=val;
  }
  static struct aa* recalculate(struct aa* node){
    if(node!=nil){
      for(int64_t i=0;i<5;i++){
	node->sum[i]=0;
      }
      for(int64_t i=0;i<5;i++){
	node->sum[i]+=node->left->sum[i];
	node->sum[(node->left->size+i+1)%5]+=node->right->sum[i];
      }
      node->sum[node->left->size%5]+=node->val;
      node->size=node->left->size+node->right->size+1;
    }
    return node;
  }
  static struct aa *skew(struct aa* node){
    if((node!=nil)&&(node->left->level==node->level)){
      struct aa* next=node->left;
      node->left=next->right;
      next->right=node;
      recalculate(node);
      recalculate(next);
      return next;
    }
    return node;
  }
  static struct aa* split(struct aa* node){
    if((node!=nil)&&(node->right->right->level==node->level)){
      struct aa* next=node->right;
      node->right=next->left;
      next->left=node;
      next->level++;
      recalculate(node);
      recalculate(next);
      return next;
    }
    return node;
  }
  static struct aa* insert(struct aa* node,int64_t val){
    if(node==nil){
      return new aa(val);
    }
    if(val<node->val){
      node->left=insert(node->left,val);
      recalculate(node);
    }else if(val>node->val){
      node->right=insert(node->right,val);
      recalculate(node);
    }
    node=skew(node);
    node=split(node);
    return node;
  }
  static struct aa* erase(struct aa* node,int64_t val){
    if(node==nil){
      return node;
    }
    if(val<node->val){
      node->left=erase(node->left,val);
      recalculate(node);
    }else if(val>node->val){
      node->right=erase(node->right,val);
      recalculate(node);
    }else{
      if(node->left==nil){
	struct aa* tmp=node->right;
	delete node;
	return tmp;
      }else{
	struct aa* pred;
	for(pred=node->left;pred->right!=nil;pred=pred->right);
	node->val=pred->val;
	node->left=erase(node->left,pred->val);
	recalculate(node);
      }
    }
    if((node->left->level<node->level-1)||
       (node->right->level<node->level-1)){
      if(node->right->level==node->level--){
	node->right->level--;
      }
      node=skew(node);
      node->right=skew(node->right);
      node->right->right=skew(node->right->right);
      node=split(node);
      node->right=split(node->right);
    }
    return node;
  }
  static void dump(struct aa* node){
    if(node!=nil){
      dump(node->left);
      std::cout<<node->val<<" ";
      dump(node->right);
    }
  }
};

struct aa* aa::nil=new aa();

int main(){
  struct aa* root=aa::nil;
  int64_t N;
  std::cin>>N;
  for(int64_t i=0;i<N;i++){
    std::string type;
    std::cin>>type;
    if(type=="add"){
      int64_t X;
      std::cin>>X;
      root=aa::insert(root,X);
    }else if(type=="del"){
      int64_t X;
      std::cin>>X;
      root=aa::erase(root,X);
    }else{
      std::cout<<root->sum[2]<<std::endl;
    }
  }
  return 0;
}