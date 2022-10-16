#include <iostream>
#include <algorithm>

struct cstar{
  long long x,y;
  long long id;
  bool operator<(struct cstar other)const{
    if(x!=other.x){
      return x<other.x;
    }
    return y<other.y;
  }
}stars[100000];

long long N;

int main(){
  std::cin>>N;
  for(long long i=0;i<N;i++){
    std::cin>>stars[i].x>>stars[i].y;
    stars[i].id=i+1;
  }
  std::sort(stars,stars+N);
  for(long long i=2;i<N;i++){
    if((stars[i].x-stars[i-2].x)*(stars[i].y-stars[i-1].y)!=(stars[i].y-stars[i-2].y)*(stars[i].x-stars[i-1].x)){
      std::cout<<stars[i-2].id<<" "<<stars[i-1].id<<" "<<stars[i].id<<std::endl;
      return 0;
    }
  }
  return 0;
}