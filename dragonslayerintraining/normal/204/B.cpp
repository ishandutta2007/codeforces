#include <iostream>
#include <map>

std::map<int,std::pair<int,int> > color;
/*first: either, second: front*/

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    color[A].first++;
    color[A].second++;
    if(A!=B){
      color[B].first++;
    }
  }
  unsigned int best=-1;
  for(auto it:color){
    if(it.second.first>=(N+1)/2){
      best=std::min<unsigned int>(best,std::max(0,(N+1)/2-it.second.second));
    }
  }
  std::cout<<int(best)<<std::endl;
  return 0;
}