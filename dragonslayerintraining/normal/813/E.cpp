#include <iostream>
#include <vector>

int as[100000];

std::vector<int> back[100001];
int kth[100000];

struct segtree{
  struct segtree* left,*right;
  int sum;
  static int getsum(struct segtree* st){
    return st?st->sum:0;
  }
  segtree():sum(0){
  }
  segtree(struct segtree* left,struct segtree* right):left(left),right(right),sum(getsum(left)+getsum(right)){
  }
  static struct segtree* build(int L,int R){
    if(R-L==1){
      return new segtree();
    }else{
      int M=(L+R)/2;
      return new segtree(build(L,M),build(M,R));
    }
  }
  struct segtree* update(int L,int R,int index,int value){
    if(R-L==1){
      struct segtree* ret=new segtree();
      ret->sum=sum+value;
      return ret;
    }
    int M=(L+R)/2;
    if(index<M){
      return new segtree(left->update(L,M,index,value),right);
    }else{
      return new segtree(left,right->update(M,R,index,value));
    }
  }
  int query(int L,int R,int a,int b){
    if((a>=R)||(b<=L)){
      return 0;
    }
    if((a<=L)&&(b>=R)){
      return sum;
    }
    int M=(L+R)/2;
    return left->query(L,M,a,b)+right->query(M,R,a,b);
  }
};

struct segtree* snap[100000];
struct segtree* root;

int main(){
  int N,K;
  std::cin>>N>>K;
  root=segtree::build(0,N);
  for(int i=0;i<N;i++){
    std::cin>>as[i];
    std::vector<int>& curback=back[as[i]];
    kth[i]=(static_cast<int>(curback.size())>=K)?(curback[curback.size()-K]):-1;
    curback.push_back(i);
  }
  for(int i=0;i<N;i++){
    root=root->update(0,N,i,1);
    if(kth[i]>=0){
      root=root->update(0,N,kth[i],-1);
    }
    snap[i]=root;
  }
  int Q;
  std::cin>>Q;
  int last=0;
  for(int i=0;i<Q;i++){
    int X,Y;
    std::cin>>X>>Y;
    int L=(X+last)%N;
    int R=(Y+last)%N;
    if(L>R){
      std::swap(L,R);
    }
    last=snap[R]->query(0,N,L,N);
    std::cout<<last<<std::endl;
  }
  return 0;
}