#include <cstdio>
#include <algorithm>

int as[50];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  if(std::count(as,as+N,*std::min_element(as,as+N))<=N/2){
    printf("Alice\n");
  }else{
    printf("Bob\n");
  }
}