#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <stdint.h>

class Matrix{
  int64_t N;
  std::vector<int64_t> elems;
public:
  Matrix(int64_t N):N(N),elems(N*N,0){
  }
  int64_t& get(int64_t row,int64_t col){
    return elems[row*N+col];
  }
  int64_t get(int64_t row,int64_t col)const{
    return elems[row*N+col];
  }
  struct Matrix operator*(struct Matrix other)const{
    assert(N==other.N);
    Matrix res(N);
    for(int64_t i=0;i<N;i++){
      for(int64_t j=0;j<N;j++){
	int64_t best=1e18;
	for(int64_t k=0;k<N;k++){
	  best=std::min(best,get(i,k)+other.get(k,j));
	}
	res.get(i,j)=best;
      }
    }
    return res;
  }
  std::vector<int64_t> operator*(std::vector<int64_t> other)const{
    assert(other.size()==N);
    std::vector<int64_t> res(N,1e18);
    for(int64_t i=0;i<N;i++){
      for(int64_t j=0;j<N;j++){
	res[j]=std::min(res[j],other[i]+get(i,j));
      }
    }
    return res;
  }
};

int64_t id[256];
std::vector<int64_t> states;
int64_t cost[8];
std::vector<std::pair<int64_t,int64_t> > special;

void skip(const std::vector<struct Matrix>& moves,std::vector<int64_t>& cs,int64_t exp){
  for(int64_t k=0;k<27;k++){
    if((exp>>k)&1){
      cs=moves[k]*cs;
    }
  }
}

int64_t extra=0;

int main(){
  int64_t X,K,N,Q;
  std::cin>>X>>K>>N>>Q;
  for(int64_t i=0;i<K;i++){
    std::cin>>cost[i];
  }
  for(int64_t i=0;i<Q;i++){
    int64_t P,W;
    std::cin>>P>>W;
    if(P<=N-X){
      special.emplace_back(P,W);
    }else{
      extra+=W;
    }
  }
  std::sort(special.begin(),special.end());
  for(int64_t mask=1;mask<(1<<K);mask++){
    id[mask]=id[mask&(mask-1)]+1;
  }
  for(int64_t mask=0;mask<(1<<K);mask++){
    if(id[mask]==X){
      id[mask]=states.size();
      states.push_back(mask);
    }else{
      id[mask]=-1;
    }
    //std::cout<<mask<<" "<<id[mask]<<std::endl;
  }
  std::vector<struct Matrix> moves(27,Matrix(states.size()));
  for(int64_t from=0;from<states.size();from++){
    for(int64_t to=0;to<states.size();to++){
      moves[0].get(from,to)=1e18;
    }
  }
  for(int64_t from=0;from<states.size();from++){
    int64_t mask=states[from];
    if(mask&1){
      for(int64_t dist=0;dist<K;dist++){
	if(((mask>>1)&(1<<dist))==0){
	  int64_t to=id[(mask>>1)|(1<<dist)];
	  moves[0].get(from,to)=cost[dist];
	  //std::cout<<"MOVE: "<<states[from]<<" "<<states[to]<<" "<<cost[dist]<<std::endl;
	}
      }
    }else{
      int64_t to=id[mask>>1];
      moves[0].get(from,to)=0;
      //std::cout<<"MOVE: "<<states[from]<<" "<<states[to]<<" "<<0<<std::endl;
    }
  }
  for(int64_t k=1;k<27;k++){
    moves[k]=moves[k-1]*moves[k-1];
    /*
    for(int64_t i=0;i<states.size();i++){
      for(int64_t j=0;j<states.size();j++){
	if(moves[k].get(i,j)<1e18){
	  std::cout<<"MOVE(1<<"<<k<<"): "<<states[i]<<"=>"<<states[j]<<": "<<moves[k].get(i,j)<<std::endl;
	}
      }
    }
    */
  }
  std::vector<int64_t> cs(states.size(),1e18);
  cs[0]=0;
  int64_t time=1;
  for(int64_t si=0;si<special.size();si++){
    skip(moves,cs,special[si].first-time);
    time=special[si].first;
    for(int64_t i=0;i<states.size();i++){
      if(states[i]&1){
	cs[i]+=special[si].second;
      }
    }
    /*
    for(int64_t i=0;i<states.size();i++){
      std::cout<<"COST("<<time<<")("<<states[i]<<")="<<cs[i]<<std::endl;
    }
    */
  }
  skip(moves,cs,N-X+1-time);
  time=N-X+1;
  /*
  for(int64_t i=0;i<states.size();i++){
    std::cout<<"COST("<<time<<")("<<states[i]<<")="<<cs[i]<<std::endl;
  }
  */
  std::cout<<cs[0]+extra<<std::endl;
  return 0;
}