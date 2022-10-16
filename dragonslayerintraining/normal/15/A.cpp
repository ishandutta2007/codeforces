#include <iostream>
#include <algorithm>

struct house{
  int x,size;
  bool operator<(struct house b)const{
    return x<b.x;
  }
  int right(){return x+size;}
  int left(){return x-size;}
}houses[1000];

int main(){
  int N,T;
  int cnt=2;
  std::cin>>N>>T;
  for(int i=0;i<N;i++){
    int x,size;
    std::cin>>x>>size;
    houses[i].x=x*2;
    houses[i].size=size;
  }
  std::sort(houses,houses+N);

  for(int i=0;i<N-1;i++){
    int dist=houses[i+1].left()-houses[i].right();
    if(dist>2*T){
      cnt+=2;
    }else if(dist==2*T){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}