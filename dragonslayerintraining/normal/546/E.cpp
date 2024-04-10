#include <iostream>
#include <vector>
#include <set>
#include <cassert>

namespace maxflow{
  struct cedge{
    int other;
    int width;
    cedge(int other,int width):other(other),width(width){
    }
  };
  struct cpath{
    int wide;
    int prev,curr;
    cpath(int wide,int prev,int curr):wide(wide),prev(prev),curr(curr){
    }
    bool operator<(struct cpath other)const{
      if(wide!=other.wide)return wide<other.wide;
      if(prev!=other.prev)return prev<other.prev;
      if(curr!=other.curr)return curr<other.curr;
      return false;
    }
  };
  struct cflow{
    int N;
    int source;
    int sink;

    std::vector<std::vector<int> >res;
    std::vector<std::vector<struct cedge> > edges;
    std::vector<int> widest;
    std::vector<int> from;
    cflow(int N,int source,int sink):
      N(N),source(source),sink(sink),
      res(N,std::vector<int>(N,0)),
      edges(N,std::vector<struct cedge>()),
      widest(N,0),from(N,0){
    }

    void addedge(int a,int b,int cap){
      edges[a].push_back(cedge(b,cap));
      edges[b].push_back(cedge(a,0));
      res[a][b]=cap;
    }

    int calculate_flow(){
      int total=0;
      while(true){
	std::set<struct cpath> queue;
	for(int i=0;i<N;i++){
	  widest[i]=0;
	  from[i]=-1;
	}
	queue.insert(cpath(1<<30,-1,source));
	while(!queue.empty()){
	  int wide=(*--queue.end()).wide;
	  int prev=(*--queue.end()).prev;
	  int curr=(*--queue.end()).curr;
	  queue.erase(--queue.end());

	  if(wide<=widest[curr]){
	    continue;
	  }
	  widest[curr]=wide;
	  from[curr]=prev;
	  for(unsigned int i=0;i<edges[curr].size();i++){
	    int other=edges[curr][i].other;
	    queue.insert(cpath(std::min(wide,res[curr][other]),
			       curr,other));
	  }
	}
	int delta=widest[sink];
	if(delta<=0){
	  break;
	}
	total+=delta;
	for(int i=sink;i!=source;i=from[i]){
	  if(i<0){
	    break;
	  }
	  res[i][from[i]]+=delta;
	  res[from[i]][i]-=delta;
	  assert(res[from[i]][i]>=0);
	}
      }
      return total;
    }
  };
}

int main(){
  int N,M;
  int soldier_cnt=0;
  std::cin>>N>>M;
  struct maxflow::cflow flow(2*N+2,0,2*N+1);
  
  for(int i=0;i<N;i++){
    flow.addedge(i+1,i+N+1,1<<30);
  }
  int asum=0;
  for(int i=0;i<N;i++){
    int a;
    std::cin>>a;
    asum+=a;
    flow.addedge(0,i+1,a);
  }
  int bsum=0;
  for(int i=0;i<N;i++){
    int b;
    std::cin>>b;
    bsum+=b;
    flow.addedge(i+N+1,2*N+1,b);
  }
  if(asum!=bsum){
    std::cout<<"NO"<<std::endl;
    return 0;
  }
  soldier_cnt=asum;
  for(int i=0;i<M;i++){
    int A,B;
    std::cin>>A>>B;
    flow.addedge(A,B+N,1<<30);
    flow.addedge(B,A+N,1<<30);
  }
  int best=flow.calculate_flow();
  if(best==soldier_cnt){
    std::cout<<"YES"<<std::endl;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	if(j>0){
	  std::cout<<" ";
	}
	int val=flow.res[i+1][j+N+1];
	if(val==0){
	  std::cout<<0;
	}else{
	  std::cout<<(1<<30)-val;
	}
      }
      std::cout<<std::endl;
    }
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}