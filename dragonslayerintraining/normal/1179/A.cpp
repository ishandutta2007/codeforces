#include <cstdio>
#include <deque>
#include <array>
#include <map>
#include <cassert>

std::deque<int> as;
std::array<int,2> two[200005];

int main(){
  int N,Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    as.push_back(A);
  }
  for(int t=0;t<N*2;t++){
    int A=as.front();
    as.pop_front();
    int B=as.front();
    as.pop_front();
    two[t]={A,B};
    if(A>B){
      as.push_front(A);
      as.push_back(B);
    }else{
      as.push_front(B);
      as.push_back(A);
    }
  }
  while(Q--){
    int64_t M;
    scanf("%I64d",&M);
    M--;
    if(M>=N*2){
      M=(M-N)%(N-1)+N;
    }
    printf("%d %d\n",two[M][0],two[M][1]);
  }
  return 0;
}