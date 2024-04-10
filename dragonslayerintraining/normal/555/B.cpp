#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

long long N,M;

struct crange{
  long long l,r;
  crange(){
  }
  crange(long long l,long long r):l(l),r(r){
  }
}islands[200005];
long long lengths[200005];
long long bs[200005];

struct cevent{
  enum etype{
    TYPE_LEFT=0,
    TYPE_BRIDGE=1,
    TYPE_RIGHT=2,
  }type;
  long long pos;
  long long index;
  long long data;
  cevent(enum etype type,long long pos,long long index,long long data):type(type),pos(pos),index(index),data(data){
  }
  bool operator<(struct cevent other)const{
    if(pos!=other.pos){
      return pos<other.pos;
    }
    if(type!=other.type){
      return type<other.type;
    }
    return index<other.index;
  }
};

int main(){
  std::cin>>N>>M;
  for(long long i=0;i<N;i++){
    std::cin>>islands[i].l>>islands[i].r;
  }
  std::vector<struct cevent> events;
  for(long long i=0;i<M;i++){
    std::cin>>lengths[i];
    events.push_back(cevent(cevent::TYPE_BRIDGE,lengths[i],i,0));
  }
  for(long long i=0;i<N-1;i++){
    long long L=islands[i+1].l-islands[i].r;
    long long R=islands[i+1].r-islands[i].l;
    //std::cout<<"Range: "<<L<<"\t"<<R<<std::endl;
    events.push_back(cevent(cevent::TYPE_LEFT,L,i,R));
    events.push_back(cevent(cevent::TYPE_RIGHT,R,i,0));
  }
  std::sort(events.begin(),events.end());
  //(endpolong long,index)
  std::set<std::pair<long long,long long> > active;
  for(struct cevent event:events){
    /*
      std::cout<<"Event: "<<event.type<<"\t"<<event.pos<<"\t"<<event.index<<std::endl;
      std::cout<<"Active:";
      for(std::pair<long long,long long> pair:active){
      std::cout<<" "<<pair.first;
      }
      std::cout<<std::endl;
    */
    switch(event.type){
    case cevent::TYPE_LEFT:
      active.insert(std::make_pair(event.data,event.index));
      break;
    case cevent::TYPE_RIGHT:
      if(active.count(std::make_pair(event.pos,event.index))){
	std::cout<<"No"<<std::endl;
	return 0;
      }
      break;
    case cevent::TYPE_BRIDGE:
      if(!active.empty()){
	bs[active.begin()->second]=event.index;
	active.erase(active.begin());
      }
      break;
    }
  }
  std::cout<<"Yes"<<std::endl;
  for(long long i=0;i<N-1;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<bs[i]+1;
  }
  std::cout<<std::endl;
  return 0;
}