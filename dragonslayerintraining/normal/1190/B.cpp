#include <cstdio>
#include <algorithm>
#include <vector>

int as[100005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::sort(as,as+N);
  std::vector<int> dup;
  for(int i=1;i<N;i++){
    if(as[i]==as[i-1]){
      dup.push_back(as[i]);
    }
  }
  if(dup.size()>1||dup.size()==1&&(dup[0]==0||std::count(as,as+N,dup[0]-1))){
    printf("cslnb\n");
  }else{
    int cnt=0;
    for(int i=0;i<N;i++){
      cnt+=(as[i]+i)%2;
    }
    if(cnt%2==0){
      printf("cslnb\n");
    }else{
      printf("sjfnb\n");
    }
  }
}