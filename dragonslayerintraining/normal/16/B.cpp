#include <iostream>
#include <algorithm>

struct c{
  int a,b;
  bool operator<(struct c o)const{
    if(b!=o.b){
      return b>o.b;
    }
    return a<o.a;
  }
}cs[20];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<M;i++){
    std::cin>>cs[i].a>>cs[i].b;
  }
  std::sort(cs,cs+M);
  int cnt=0;
  for(int i=0;i<M;i++){
    int take=std::min(cs[i].a,N);
    cnt+=take*cs[i].b;
    N-=take;
  }
  std::cout<<cnt<<std::endl;
  return 0;
}