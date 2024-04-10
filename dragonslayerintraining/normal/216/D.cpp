#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sector[1000];
int unbalanced=0;

void check(const std::vector<int>& left,
	   const std::vector<int>& center,
	   const std::vector<int>& right){
  int l=0,r=0;
  for(int i=0;i<center.size();i++){
    int lcnt=0,rcnt=0;
    while((l<left.size())&&(left[l]<center[i])){
      l++,lcnt++;
    }
    while((r<right.size())&(right[r]<center[i])){
      r++,rcnt++;
    }
    if((i>0)&&(lcnt!=rcnt)){
      unbalanced++;
    }
  }
}
	   

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int K;
    std::cin>>K;
    for(int k=0;k<K;k++){
      int P;
      std::cin>>P;
      sector[i].push_back(P);
    }
    std::sort(sector[i].begin(),sector[i].end());
  }
  for(int i=0;i<N;i++){
    check(sector[i],sector[(i+1)%N],sector[(i+2)%N]);
  }
  std::cout<<unbalanced<<std::endl;
}