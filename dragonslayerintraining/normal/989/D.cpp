#include <cstdio>
#include <algorithm>
#include <vector>
#include <stdint.h>

std::vector<int64_t> rightward,leftward;
int64_t W;

bool intersect(int64_t i,int64_t j){
  if(rightward[i]>=leftward[j]) return false;
  int64_t diff=leftward[j]-rightward[i];
  int64_t sum=leftward[j]+rightward[i];
  return ((sum>-W*diff)&&(sum<W*diff));
}

int main(){
  int64_t N,L;
  scanf("%I64d %I64d %I64d",&N,&L,&W);
  for(int64_t i=0;i<N;i++){
    int64_t X,V;
    scanf("%I64d %I64d",&X,&V);
    if(V==1){
      rightward.push_back(X);
    }else{
      leftward.push_back(X+L);
    }
  }
  std::sort(leftward.begin(),leftward.end());
  std::sort(rightward.begin(),rightward.end());
  int64_t j=0;
  int64_t total=0;
  for(int64_t i=0;i<rightward.size();i++){
    while(j<leftward.size()&&!intersect(i,j)){
      j++;
    }
    total+=leftward.size()-j;
  }
  printf("%I64d\n",total);
  return 0;
}