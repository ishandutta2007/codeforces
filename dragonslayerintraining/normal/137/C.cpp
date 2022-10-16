#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

struct cevent{
  enum etype{
    BEGIN,
    END,
  }type;
  int t1,t2;
  int id;
  cevent(enum etype type,int t1,int t2,int id):type(type),
					       t1(t1),t2(t2),id(id){
  }
  int gettime()const{
    switch(type){
    case BEGIN:return t1;
    case END:return t2;
    }
  }
  bool operator<(struct cevent other)const{
    return gettime()<other.gettime();
  }
};

std::vector<struct cevent> events;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    events.push_back(cevent(cevent::BEGIN,A,B,i));
    events.push_back(cevent(cevent::END,A,B,i));
  }
  std::sort(events.begin(),events.end());
  std::set<int> active;
  int cnt=0;
  for(int i=0;i<events.size();i++){
    switch(events[i].type){
    case cevent::BEGIN:
      active.insert(events[i].t1);
      break;
    case cevent::END:
      active.erase(events[i].t1);
      if(active.size()&&(*active.begin()<events[i].t1)){
	cnt++;
      }
      break;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}