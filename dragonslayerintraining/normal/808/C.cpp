#include <cstdio>
#include <algorithm>

int as[100];

std::vector<std::pair<int,int> > cups;

int main(){
  int N,W;
  scanf("%d %d",&N,&W);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    as[i]=(A+1)/2;
    W-=(A+1)/2;
    cups.emplace_back(A,i);
  }
  if(W<0){
    printf("-1\n");
    return 0;
  }
  std::sort(cups.begin(),cups.end());
  std::reverse(cups.begin(),cups.end());
  for(auto cup:cups){
    int use=std::min(W,cup.first/2);
    as[cup.second]+=use;
    W-=use;
  }
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",as[i]);
  }
  printf("\n");
  return 0;
}