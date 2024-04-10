#include <iostream>
#include <cassert>
#include <set>

int N,Q;

struct cbar{
  int begin,end;
  int left,top;
  cbar(int begin,int end,int left,int top):begin(begin),end(end),left(left),top(top){
  }
  bool operator<(struct cbar other)const{
    return (begin<other.begin)&&(end<other.end);
  }
};

std::set<struct cbar> choc;

int main(){
  std::cin>>N>>Q;
  choc.insert(cbar(1,N,0,N+1));
  for(int i=0;i<Q;i++){
    int X,Y;
    char C;
    std::cin>>X>>Y>>C;
    /*
      std::cout<<"Query: ("<<X<<","<<Y<<")\t"<<C<<std::endl;
      for(auto it:choc){
      std::cout<<"["<<it.begin<<","<<it.end<<"]\t"<<it.left<<"\t"<<it.top<<std::endl;
      }
    */
    std::set<struct cbar>::iterator it=choc.find(cbar(X,X,-1,-1));
    if(it==choc.end()){
      std::cout<<0<<std::endl;
      continue;
    }
    struct cbar seg=*it;
      
    choc.erase(seg);
    if(C=='L'){
      std::cout<<X-seg.left<<std::endl;
      if((X-1-seg.begin)>=0){
	choc.insert(cbar(seg.begin,X-1,seg.left,X));
      }
      if((seg.end-X-1)>=0){
	choc.insert(cbar(X+1,seg.end,seg.left,seg.top));
      }
    }
    if(C=='U'){
      std::cout<<seg.top-X<<std::endl;
      if((X-1-seg.begin)>=0){
	choc.insert(cbar(seg.begin,X-1,seg.left,seg.top));
      }
      if((seg.end-X-1)>=0){
	choc.insert(cbar(X+1,seg.end,X,seg.top));
      }
    }
  }
  
  return 0;
}