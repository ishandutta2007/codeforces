#include <cstdio>
#include <algorithm>

int as[100005];
int bs[100005];
int in[100005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    in[as[i]]=i;
  }
  for(int i=0;i<N;i++){
    scanf("%d",&bs[i]);
  }
  int fine=0;
  int early=N;
  for(int i=N-1;i>=0;i--){
    early=std::min(early,in[bs[i]]);
    if(early<in[bs[i]]){
      fine++;
    }
  }
  printf("%d\n",fine);
}