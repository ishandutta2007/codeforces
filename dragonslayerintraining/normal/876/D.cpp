#include <cstdio>
#include <vector>
#include <algorithm>

int ps[300005];

std::vector<int> vs;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&ps[i]);
    ps[i]--;
  }
  vs.push_back(1);
  int last=-1;
  for(int i=N-1;i>=0;i--){
    last=std::max(last,ps[i]);
    vs.push_back(last-(N-i)+2);
  }
  std::reverse(vs.begin(),vs.end());
  for(int i=0;i<=N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",vs[i]);
  }
  printf("\n");
  return 0;
}