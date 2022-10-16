#include <iostream>
#include <vector>
#include <set>

int as[300000];

std::vector<std::pair<int,int> > segs;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::set<int> curtypes;
  int start=0;
  for(int i=0;i<N;i++){
    if(curtypes.count(as[i])){
      curtypes.clear();
      segs.push_back(std::make_pair(start,i));
      start=i+1;
    }else{
      curtypes.insert(as[i]);
    }
  }
  if(segs.empty()){
    std::cout<<-1<<std::endl;
    return 0;
  }
  if(start<N){
    segs.back().second=N-1;
  }
  std::cout<<segs.size()<<std::endl;
  for(int i=0;i<segs.size();i++){
    std::cout<<segs[i].first+1<<" "<<segs[i].second+1<<std::endl;
  }
  return 0;
}