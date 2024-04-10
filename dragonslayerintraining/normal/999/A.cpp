#include <cstdio>
#include <deque>

int main(){
  std::deque<int> vs;
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    int X;
    scanf("%d",&X);
    vs.push_back(X);
  }
  while(vs.size()&&vs.front()<=K){
    vs.pop_front();
  }
  while(vs.size()&&vs.back()<=K){
    vs.pop_back();
  }
  printf("%d\n",(int)(N-vs.size()));
  return 0;
}