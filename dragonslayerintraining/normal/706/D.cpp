#include <iostream>

struct ctrie{
  struct ctrie* child[2];
  int cnt;
  ctrie():cnt(0){
    child[0]=child[1]=NULL;
  }
  struct ctrie* getchild(int index){
    if(child[index]==NULL){
      child[index]=new ctrie();
    }
    return child[index];
  }
  void insert(int val){
    struct ctrie* curr=this;
    curr->cnt++;
    for(int k=30;k>=0;k--){
      curr=curr->getchild((val>>k)&1);
      curr->cnt++;
    }
  }
  void erase(int val){
    struct ctrie* curr=this;
    curr->cnt--;
    for(int k=30;k>=0;k--){
      curr=curr->getchild((val>>k)&1);
      curr->cnt--;
    }
  }
  int query(int val){
    struct ctrie* curr=this;
    int res=0;
    for(int k=30;k>=0;k--){
      int bit=(val>>k)&1;
      if(curr->getchild(bit^1)->cnt>0){
	curr=curr->getchild(bit^1);
	res=res*2+1;
      }else{
	curr=curr->getchild(bit);
	res=res*2;
      }
    }
    return res;
  }
}root;

int main(){
  int Q;
  std::cin>>Q;
  root.insert(0);
  for(int i=0;i<Q;i++){
    std::string op;
    int val;
    std::cin>>op>>val;
    switch(op[0]){
    case '+':root.insert(val);break;
    case '-':root.erase(val);break;
    case '?':std::cout<<root.query(val)<<std::endl;break;
    }
  }
  return 0;
}