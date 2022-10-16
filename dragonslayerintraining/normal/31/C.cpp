#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int N;

struct cendpoint{
  enum etype{
    OPEN=1,
    CLOSE=0,
  }type;
  int x;
  int id;
  cendpoint(enum etype type,int x,int id):type(type),x(x),id(id){
  }
  static struct cendpoint begin(int x,int id){
    return cendpoint(OPEN,x,id);
  }
  static struct cendpoint end(int x,int id){
    return cendpoint(CLOSE,x,id);
  }
  bool operator<(struct cendpoint other)const{
    if(x!=other.x){
      return x<other.x;
    }
    if(type!=other.type){
      return type<other.type;
    }
    return false;
  }
};

std::vector<struct cendpoint> points;

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    int l,r;
    std::cin>>l>>r;
    points.push_back(cendpoint::begin(l,i+1));
    points.push_back(cendpoint::end(r,i+1));
  }
  std::sort(points.begin(),points.end());

  std::vector<std::pair<int,int> > intersects;
  std::set<int> current;
  for(int i=0;i<points.size();i++){
    switch(points[i].type){
    case cendpoint::OPEN:
      current.insert(points[i].id);
      break;
    case cendpoint::CLOSE:
      current.erase(points[i].id);
      break;
    }
    if(current.size()>=3){
      std::cout<<0<<std::endl;
      return 0;
    }
    if(current.size()==2){
      intersects.push_back(std::pair<int,int>(*current.begin(),*current.rbegin()));
    }
  }
  if(intersects.empty()){
    std::cout<<N<<std::endl;
    for(int i=0;i<N;i++){
      if(i>0){
	std::cout<<" ";
      }
      std::cout<<i+1;
    }
    std::cout<<std::endl;
    return 0;
  }
  std::set<int> candidates;
  candidates.insert(intersects[0].first);
  candidates.insert(intersects[0].second);
  for(int i=1;i<intersects.size();i++){
    std::set<int> temp;
    if(candidates.count(intersects[i].first)){
      temp.insert(intersects[i].first);
    }
    if(candidates.count(intersects[i].second)){
      temp.insert(intersects[i].second);
    }
    candidates=temp;
  }
  std::cout<<candidates.size()<<std::endl;
  for(std::set<int>::iterator it=candidates.begin();it!=candidates.end();it++){
    if(it!=candidates.begin()){
      std::cout<<" ";
    }
    std::cout<<*it;
  }
  std::cout<<std::endl;
  
  return 0;
}