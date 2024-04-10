#include <iostream>
#include <set>

int color[100000];
int used[100000]={};
std::set<int> neighbors[100001];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::cin>>color[i];
    used[color[i]]=1;
  }
  for(int i=0;i<M;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    int U=color[A],V=color[B];
    if(U!=V){
      neighbors[U].insert(V);
      neighbors[V].insert(U);
    }
  }
  int best_index=0;
  int best=-1;
  for(int i=0;i<=100000;i++){
    if(!used[i]){
      continue;
    }
    if(static_cast<int>(neighbors[i].size())>best){
      best=neighbors[i].size();
      best_index=i;
    }
  }
  std::cout<<best_index<<std::endl;
  return 0;
}