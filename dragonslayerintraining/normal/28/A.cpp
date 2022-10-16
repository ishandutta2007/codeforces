#include <iostream>
#include <set>
#include <cmath>

int xs[500],ys[500];
int ds[500];
struct crod{
  int len;
  int id;
  crod(int len,int id):len(len),id(id){
  }
  crod(int len):len(len){
  }
  operator int(){
    return len;
  }
  bool operator<(struct crod other)const{
    return len<other.len;
  }
};
std::multiset<struct crod> rods1,rods2;

int ans[500];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::cin>>xs[i]>>ys[i];
  }
  for(int i=0;i<N;i++){
    ds[i]=std::abs(xs[i]-xs[(i+1)%N])+
      std::abs(ys[i]-ys[(i+1)%N]);
  }
  for(int i=0;i<M;i++){
    int r;
    std::cin>>r;
    rods1.insert(crod(r,i+1));
    rods2.insert(crod(r,i+1));
  }
  bool ok;
  ok=true;
  for(int i=0;i<N;i+=2){
    int l=ds[i]+ds[(i+N-1)%N];
    if(rods1.count(l)){
      ans[i]=rods1.find(l)->id;
      ans[i+1]=-1;
      rods1.erase(rods1.find(l));
    }else{
      ok=false;
      break;
    }
  }
  if(ok){
    std::cout<<"YES"<<std::endl;
    for(int i=0;i<N;i++){
      if(i>0){
	std::cout<<" ";
      }
      std::cout<<ans[i];
    }
    std::cout<<std::endl;
    return 0;
  }
  ok=true;
  for(int i=0;i<N;i+=2){
    int l=ds[i]+ds[i+1];
    if(rods1.count(l)){
      ans[i]=-1;
      ans[i+1]=rods1.find(l)->id;
      rods1.erase(rods1.find(l));
    }else{
      ok=false;
      break;
    }
  }
  if(ok){
    std::cout<<"YES"<<std::endl;
    for(int i=0;i<N;i++){
      if(i>0){
	std::cout<<" ";
      }
      std::cout<<ans[i];
    }
    std::cout<<std::endl;
    return 0;
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}