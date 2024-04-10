#include <cstdio>
#include <algorithm>

int N;

char grid[4][200005];

int main(){
  scanf("%d",&N);
  for(int j=0;j<4;j++){
    for(int i=0;i<N;i++){
      scanf(" %c",&grid[j][i]);
    }
  }
  long long a=0,b=0;
  long long cost=0;
  for(int i=0;i<N;i++){
    a+=grid[0][i]-grid[2][i];
    b+=grid[1][i]-grid[3][i];
    if(a<0&&b>0){
      long long delta=std::min(-a,b);
      cost+=delta;
      a+=delta;
      b-=delta;
    }else if(a>0&&b<0){
      long long delta=std::min(a,-b);
      cost+=delta;
      a-=delta;
      b+=delta;
    }
    cost+=std::labs(a)+std::labs(b);
  }
  if(a!=0||b!=0){
    printf("-1\n");
  }else{
    printf("%lld\n",cost);
  }
}