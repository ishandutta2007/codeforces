#include <cstdio>
#include <algorithm>
#include <vector>

int main(){
  int N;
  scanf("%d",&N);
  int need=(N*9+1)/2;
  std::vector<int> gain;
  for(int i=0;i<N;i++){
    int X;
    scanf("%d",&X);
    need-=X;
    gain.push_back(5-X);
  }
  std::sort(gain.begin(),gain.end());
  std::reverse(gain.begin(),gain.end());
  if(need<=0){
    printf("0\n");
    return 0;
  }
  for(int i=0;i<N;i++){
    need-=gain[i];
    if(need<=0){
      printf("%d\n",i+1);
      return 0;
    }
  }
  return 0;
}