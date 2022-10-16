#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int64_t N,M;
int64_t T;

struct ant{
  int64_t pos;
  int64_t dir;
  int64_t id;
  ant(int64_t pos,int64_t dir,int64_t id):pos(pos),dir(dir),id(id){
  }
};

bool operator<(struct ant a,struct ant b){
  if(a.pos!=b.pos){
    return a.pos<b.pos;
  }
  if(a.dir!=b.dir){
    return a.dir<b.dir;
  }
  return false;
}

std::vector<struct ant> begin,end;
int64_t shift=0;
int64_t loc[300000];

int64_t quotient(int64_t num,int64_t den){
  assert(den>0);
  if(num>=0){
    return num/den;
  }
  return -((den-num-1)/den);
}

int64_t modulo(int64_t num,int64_t den){
  assert(den>0);
  if(num>=0){
    return num%den;
  }
  return (den-(-num)%den)%den;
}

int main(){
  std::cin>>N>>M>>T;
  for(int64_t i=0;i<N;i++){
    int64_t S;
    std::string D;
    std::cin>>S>>D;
    S--;
    if(D=="L"){
      begin.emplace_back(S,-1,i);
      end.emplace_back(modulo(S-T,M),-1,-1);
      shift+=quotient(S-T,M);
    }else{
      begin.emplace_back(S,1,i);
      end.emplace_back(modulo(S+T,M),1,-1);
      shift+=quotient(S+T,M);
    }
  }
  std::sort(begin.begin(),begin.end());
  std::sort(end.begin(),end.end());
  for(int64_t i=0;i<N;i++){
    loc[begin[modulo(i-shift,N)].id]=end[i].pos;
  }
  for(int64_t i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<loc[i]+1;
  }
  std::cout<<std::endl;
  return 0;
}