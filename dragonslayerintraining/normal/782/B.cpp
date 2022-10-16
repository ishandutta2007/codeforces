#include <cstdio>
#include <algorithm>

int xs[60000];
int vs[60000];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&xs[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&vs[i]);
  }
  double low=0,high=1e9+1;
  while(true){
    double mid=(low+high)/2;
    if(low==mid||high==mid) break;
    double up=1e9,down=0;
    for(int i=0;i<N;i++){
      up=std::min(up,xs[i]+vs[i]*mid);
      down=std::max(down,xs[i]-vs[i]*mid);
    }
    if(down<up){
      high=mid;
    }else{
      low=mid;
    }
  }
  printf("%.10lf\n",low);
  return 0;
}