#include <cstdio>
#include <algorithm>

int as[200005];
int bs[200005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::copy(as,as+N,bs);
  std::sort(bs,bs+N);
  int best=(bs[0]+1)/2+(bs[1]+1)/2;
  for(int i=0;i<N-2;i++){
    int x=as[i],y=as[i+2];
    best=std::min(best,(x+y+1)/2);
  }
  for(int i=0;i<N-1;i++){
    int x=as[i],y=as[i+1];
    best=std::min(best,std::max({(x+1)/2,(y+1)/2,(x+y+2)/3}));
  }
  printf("%d\n",best);
}