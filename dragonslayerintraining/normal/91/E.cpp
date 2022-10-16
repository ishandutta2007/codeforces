#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

struct Walrus{
  int64_t a,b,id;
  Walrus(int64_t a,int64_t b,int64_t id):a(a),b(b),id(id){
  }
  bool operator<(struct Walrus other)const{
    if(b!=other.b){
      return b<other.b;
    }
    return a<other.a;
  }
  int64_t height(int64_t t){
    return a+b*t;
  }
  static struct Walrus null(){
    return Walrus(0,0,-1);
  }
};

struct ConvexHull{
  std::vector<int64_t> xs;
  std::vector<struct Walrus> slopes;
  
  struct Walrus query(int64_t x){
    int64_t low=0,high=slopes.size();
    while(high-low>1){
      int64_t mid=(low+high)/2;
      if(xs[mid]<=x){
	low=mid;
      }else{
	high=mid;
      }
    }
    return slopes[low];
  }
  void insert(struct Walrus walrus){
    for(;slopes.size();xs.pop_back(),slopes.pop_back()){
      if(walrus.b==slopes.back().b){
	continue;
      }
      int64_t num=slopes.back().a-walrus.a;
      int64_t den=walrus.b-slopes.back().b;
      int64_t x=(num+den-1)/den;
      if(x>xs.back()){
	xs.push_back(x);
	slopes.push_back(walrus);
	return;
      }
    }
    xs.push_back(0);
    slopes.push_back(walrus);
  }
};

struct ConvexHull st[400000];
int64_t N;

void insert(int64_t w,int64_t L,int64_t R,struct Walrus walrus){
  if((walrus.id<L)||(walrus.id>=R)){
    return;
  }
  st[w].insert(walrus);
  if(R-L==1){
    return;
  }
  int64_t M=(L+R)/2;
  insert(w*2+1,L,M,walrus);
  insert(w*2+2,M,R,walrus);
}

void insert(struct Walrus walrus){
  insert(0,0,N,walrus);
}

struct Walrus query(int64_t w,int64_t L,int64_t R,int64_t a,int64_t b,int64_t t){
  if((b<=L)||(a>=R)){
    return Walrus::null();
  }
  if((a<=L)&&(b>=R)){
    return st[w].query(t);
  }
  int64_t M=(L+R)/2;
  struct Walrus w1=query(w*2+1,L,M,a,b,t);
  struct Walrus w2=query(w*2+2,M,R,a,b,t);
  if(w1.height(t)<w2.height(t)){
    return w2;
  }else{
    return w1;
  }
}

struct Walrus query(int64_t a,int64_t b,int64_t t){
  return query(0,0,N,a,b,t);
}

int main(){
  int64_t Q;
  std::cin>>N>>Q;
  std::vector<struct Walrus> walruses;
  for(int64_t i=0;i<N;i++){
    int64_t A,B;
    std::cin>>A>>B;
    walruses.emplace_back(A,B,i);
  }
  std::sort(walruses.begin(),walruses.end());
  for(struct Walrus walrus:walruses){
    insert(walrus);
  }
  for(int64_t i=0;i<Q;i++){
    int64_t L,R,T;
    std::cin>>L>>R>>T;
    std::cout<<query(L-1,R,T).id+1<<std::endl;
  }
  return 0;
}