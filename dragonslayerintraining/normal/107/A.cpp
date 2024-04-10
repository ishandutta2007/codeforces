#include <iostream>
#include <set>

struct pipe{
  int src,dest,diam;
  pipe(){
  }
  pipe(int src,int dest,int diam):src(src),dest(dest),diam(diam){
  }
};

struct pipecmpsrc{
  //all sources are unique
  bool operator()(const struct pipe& pipe1,const struct pipe& pipe2)const{
    return pipe1.src<pipe2.src;
  }
};
  
struct pipecmpdest{
  //all destination are unique
  bool operator()(const struct pipe& pipe1,const struct pipe& pipe2)const{
    return pipe1.dest<pipe2.dest;
  }
};
  
std::set<struct pipe,struct pipecmpsrc> pipes1;
std::set<struct pipe,struct pipecmpdest> pipes2;

int main(){
  int N,P;
  std::cin>>N>>P;
  for(int i=0;i<P;i++){
    struct pipe curr;
    std::cin>>curr.src>>curr.dest>>curr.diam;
    struct pipe rev(curr.dest,curr.src,curr.diam);
    while(true){
      if(pipes1.count(rev)){
	struct pipe conn=*pipes1.find(rev);
	pipes1.erase(conn);
	pipes2.erase(conn);
	curr.dest=conn.dest;
	curr.diam=std::min(curr.diam,conn.diam);
      }else if(pipes2.count(rev)){
	struct pipe conn=*pipes2.find(rev);
	pipes1.erase(conn);
	pipes2.erase(conn);
	curr.src=conn.src;
	curr.diam=std::min(curr.diam,conn.diam);
      }else{
	if(curr.src!=curr.dest){
	  pipes1.insert(curr);
	  pipes2.insert(curr);
	}
	break;
      }
    }
  }
  std::cout<<pipes1.size()<<std::endl;
  for(std::set<struct pipe,struct pipecmpsrc>::iterator it=pipes1.begin();it!=pipes1.end();it++){
    std::cout<<(it->src)<<" "<<(it->dest)<<" "<<(it->diam)<<std::endl;
  }
  return 0;
}