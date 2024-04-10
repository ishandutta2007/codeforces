#include <iostream>
#include <algorithm>
#include <queue>

struct cseg{
  int l,r;
  int id;
  int day;
  cseg(int l,int r,int id):l(l),r(r),id(id){
  }
  bool operator<(struct cseg other)const{
    return id<other.id;
  }
};

struct cseglcmp{
  bool operator()(struct cseg a,struct cseg b){
    if(a.l!=b.l){return a.l>b.l;}
    return a<b;
  }
}lcmp;

struct csegrcmp{
  bool operator()(struct cseg a,struct cseg b){
    if(a.r!=b.r){return a.r>b.r;}
    return a<b;
  }
}rcmp;

int days[100];

std::priority_queue<struct cseg,std::vector<struct cseg>,cseglcmp> p;
std::priority_queue<struct cseg,std::vector<struct cseg>,csegrcmp> q;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int l,r;
    std::cin>>l>>r;
    p.push(cseg(l,r,i));
  }
  int last=-1e9;
  while(!p.empty()||!q.empty()){
    int l=1e9;
    if(!q.empty()){
      l=last+1;
    }
    if(!p.empty()){
      l=std::min(l,p.top().l);
      while(!p.empty()&&(p.top().l<=l)){
	q.push(p.top());
	p.pop();
      }
    }
    days[q.top().id]=l;
    q.pop();
    last=l;
  }
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<days[i];
  }
  std::cout<<std::endl;
  
  return 0;
}