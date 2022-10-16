#include <cstdio>
#include <map>

std::map<int,int> cnt;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    cnt[A]++;
  }
  int best=0;
  for(auto p:cnt){
    best=std::max(best,p.second);
  }
  printf("%d\n",N-best);
  return 0;
}