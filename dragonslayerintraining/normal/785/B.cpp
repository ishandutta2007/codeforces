#include <iostream>
#include <vector>

int first_end[2]={int(1e9),int(1e9)};
int last_begin[2]={0,0};

int main(){
  for(int k=0;k<2;k++){
    int N;
    std::cin>>N;
    for(int i=0;i<N;i++){
      int L,R;
      std::cin>>L>>R;
      first_end[k]=std::min(first_end[k],R);
      last_begin[k]=std::max(last_begin[k],L);
    }
  }
  int res=0;
  res=std::max(res,last_begin[1]-first_end[0]);
  res=std::max(res,last_begin[0]-first_end[1]);
  std::cout<<res<<std::endl;
  return 0;
}