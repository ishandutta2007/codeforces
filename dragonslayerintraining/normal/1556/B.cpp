#include <cstdio>
#include <vector>
#include <cmath>

int solve(){
  std::vector<int> odd;
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    if(A%2) odd.push_back(i);
  }
  auto score=[&](int shift){
    long long cost=0;
    for(int i=0;i<odd.size();i++){
      cost+=labs(odd[i]-(i*2+shift));
    }
    return cost;
  };
  if(odd.size()*2+1==N){
    return score(1);
  }else if(odd.size()*2-1==N){
    return score(0);
  }else if(odd.size()*2==N){
    return std::min(score(0),score(1));
  }else{
    return -1;
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    printf("%d\n",solve());
  }
}