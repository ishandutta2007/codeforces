#include <cstdio>
#include <map>

const int INF=1e9+7;


int xs[100005];
int ys[100005];
int last=0;

void append(int X){
  int old_last=last;
  while(xs[last]>=X){
    last--;
  }
  int Y=ys[last]+(X-xs[last]);
  if(old_last>last){
    Y=std::min(Y,ys[last+1]);
  }
  Y--;
  while(ys[last]>=Y) last--;
  last++;
  xs[last]=X;
  ys[last]=Y;
}

int main(){
  int N;
  scanf("%d",&N);
  xs[0]=-INF;
  ys[0]=-INF;
  for(int i=0;i<N;i++){
    int X;
    scanf("%d",&X);
    append(X);
  }
  append(0);
  printf("%d\n",ys[last]+N+1);
}