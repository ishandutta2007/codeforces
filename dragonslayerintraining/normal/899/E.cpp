#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<std::pair<int,int> > groups;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    if((groups.size()>0)&&(A==groups.back().first)){
      groups.back().second++;
    }else{
      groups.emplace_back(A,1);
    }
  }
  int moves=0;
  while(groups.size()>0){
    int longest=0;
    for(std::pair<int,int> group:groups){
      longest=std::max(longest,group.second);
    }
    std::vector<std::pair<int,int> > next;
    for(std::pair<int,int> group:groups){
      if((next.size()>=1)&&(next.back().first==group.first)){
	group.second+=next.back().second;
	next.pop_back();
      }
      if(group.second>=longest){
	moves++;
      }else{
	next.push_back(group);
      }
    }
    std::swap(groups,next);
  }
  printf("%d\n",moves);
  return 0;
}