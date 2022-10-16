#include <cstdio>
#include <algorithm>

int grid[1005][1005];
int jack[1005];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%d",&grid[i][j]);
    }
    jack[i]=*std::min_element(grid[i],grid[i]+M);
  }
  printf("%d\n",*std::max_element(jack,jack+N));
}