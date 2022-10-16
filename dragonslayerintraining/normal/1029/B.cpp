#include <cstdio>
#include <algorithm>

int as[200005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  int best=1;
  int run=1;
  for(int i=1;i<N;i++){
    if(as[i-1]*2>=as[i]){
      run++;
    }else{
      run=1;
    }
    best=std::max(best,run);
  }
  printf("%d\n",best);
  return 0;
}