#include <iostream>
#include <set>
#include <vector>
#include <tuple>
#include <stdint.h>

int N;
int st[800000];
int lazy[800000];
std::vector<int64_t> lub;

std::vector<std::tuple<int,int64_t,int64_t> > queries;

void lazyprop(int w,int L,int R){
  switch(lazy[w]){
  case 0:
    break;
  case 1:
    st[w]=R-L;
    break;
  case 2:
    st[w]=0;
    break;
  case 3:
    st[w]=R-L-st[w];
    break;
  }
  if(R-L>1){
    switch(lazy[w]){
    case 0:
      break;
    case 1:
      lazy[w*2+1]=1;
      lazy[w*2+2]=1;
      break;
    case 2:
      lazy[w*2+1]=2;
      lazy[w*2+2]=2;
      break;
    case 3:
      lazy[w*2+1]^=3;
      lazy[w*2+2]^=3;
      break;
    }
  }
  lazy[w]=0;
}

void set(int w,int L,int R,int a,int b,int T){
  lazyprop(w,L,R);
  if((a>=R)||(b<=L)){
    return;
  }
  if((a<=L)&&(b>=R)){
    lazy[w]=T;
    lazyprop(w,L,R);
    return;
  }
  int M=(L+R)/2;
  set(w*2+1,L,M,a,b,T);
  set(w*2+2,M,R,a,b,T);
  st[w]=st[w*2+1]+st[w*2+2];
}

int64_t mex(int w,int L,int R){
  lazyprop(w,L,R);
  if(st[w]==R-L){
    //std::cerr<<"MEX=lub["<<R<<"]"<<std::endl;
    return lub[R];
  }
  if(R-L==1){
    //std::cerr<<"MEX=lub["<<L<<"]"<<std::endl;
    return lub[L];
  }
  int M=(L+R)/2;
  lazyprop(w*2+1,L,M);
  if(st[w*2+1]==M-L){
    return mex(w*2+2,M,R);
  }else{
    return mex(w*2+1,L,M);
  }
}

int main(){
  std::set<int64_t> exist;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int T;
    int64_t L,R;
    std::cin>>T>>L>>R;
    queries.emplace_back(T,L-1,R);
    exist.insert(L-1);
    exist.insert(R);
  }
  exist.insert(0);
  for(int64_t v:exist){
    lub.push_back(v);
  }
  for(int i=0;i<N;i++){
    int T=std::get<0>(queries[i]);
    int64_t L=std::lower_bound(lub.begin(),lub.end(),
			   std::get<1>(queries[i]))-lub.begin();
    int64_t R=std::lower_bound(lub.begin(),lub.end(),
			   std::get<2>(queries[i]))-lub.begin();
    set(0,0,lub.size(),L,R,T);
    std::cout<<mex(0,0,lub.size())+1<<std::endl;
  }
  return 0;
}