#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::pair<int,int> > edges;

std::queue<std::pair<int,int> > leaves;

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<K;i++){
    leaves.emplace(i,1);
  }
  for(int i=K;i<N-1;i++){
    int leaf=leaves.front().first;
    int height=leaves.front().second;
    leaves.pop();
    edges.emplace_back(leaf,i);
    leaves.emplace(i,height+1);
  }
  std::vector<int> heights;
  while(!leaves.empty()){
    edges.emplace_back(N-1,leaves.front().first);
    heights.push_back(leaves.front().second);
    leaves.pop();
  }
  std::reverse(heights.begin(),heights.end());
  printf("%d\n",heights[0]+heights[1]);
  for(std::pair<int,int> edge:edges){
    printf("%d %d\n",edge.first+1,edge.second+1);
  }
  return 0;
}