#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>
#include <stdint.h>
#include <queue>

std::vector<int64_t> xs,ys;

std::priority_queue<std::tuple<int64_t,int64_t,int64_t> > queue;

int main(){
  int64_t N,M,R,K;
  scanf("%I64d %I64d %I64d %I64d",&N,&M,&R,&K);

  for(int64_t i=0;i<N;i++){
    xs.push_back(std::min(std::min(i+1,N-i),std::min(R,N-R+1)));
  }
  std::sort(xs.begin(),xs.end());
  std::reverse(xs.begin(),xs.end());
  
  for(int64_t i=0;i<M;i++){
    ys.push_back(std::min(std::min(i+1,M-i),std::min(R,M-R+1)));
  }
  std::sort(ys.begin(),ys.end());
  std::reverse(ys.begin(),ys.end());
  
  for(int64_t i=0;i<M;i++){
    queue.emplace(xs[0]*ys[i],0,i);
  }
  int64_t total=0;
  while(K-->0){
    total+=std::get<0>(queue.top());
    int64_t xi=std::get<1>(queue.top())+1;
    int64_t yi=std::get<2>(queue.top());
    queue.pop();
    if(xi<N){
      queue.emplace(xs[xi]*ys[yi],xi,yi);
    }
  }
  printf("%.10lf\n",double(total)/(N-R+1)/(M-R+1));
  return 0;
}