#include <cstdio>
#include <algorithm>
#include <vector>

std::vector<std::pair<int,int> > computers;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    computers.emplace_back(A,B);
  }
  std::sort(computers.begin(),computers.end());
  for(int i=0;i<N-1;i++){
    if(computers[i].second>computers[i+1].second){
      printf("Happy Alex\n");
      return 0;
    }
  }
  printf("Poor Alex\n");
  return 0;
}