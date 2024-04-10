#include <iostream>
#include <algorithm>
#include <vector>

struct cseg{
  int a,b;
  bool operator<(struct cseg other)const{
    if(b!=other.b){return b<other.b;}
    if(a!=other.a){return a<other.a;}
    return false;
  }
}segs[1000];

std::vector<int> nails;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>segs[i].a>>segs[i].b;
    if(segs[i].a>segs[i].b){
      std::swap(segs[i].a,segs[i].b);
    }
  }
  std::sort(segs,segs+N);
  int nail=-1e9;
  for(int i=0;i<N;i++){
    if(segs[i].a>nail){
      nail=segs[i].b;
      nails.push_back(nail);
    }
  }
  std::cout<<nails.size()<<std::endl;
  for(int i=0;i<nails.size();i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<nails[i];
  }
  std::cout<<std::endl;
  return 0;
}