#include <cstdio>
#include <vector>
#include <algorithm>

struct Segment{
  int x1,x2,y;
  void read(){
    scanf("%d %d %d",&x1,&x2,&y);
  }
  bool operator<(struct Segment other)const{
    return x2<other.x2;
  }
};
std::vector<struct Segment> segs;

int xs[100005];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&xs[i]);
  }
  for(int i=0;i<M;i++){
    struct Segment seg;
    seg.read();
    if(seg.x1==1){
      segs.push_back(seg);
    }
  }
  std::sort(xs,xs+N);
  xs[N]=1e9;
  std::sort(segs.begin(),segs.end());
  int cost=1e9+7;
  int j=0;
  for(int i=0;i<=N;i++){
    while(j<segs.size()&&segs[j].x2<xs[i]){
      j++;
    }
    cost=std::min<int>(cost,i+segs.size()-j);
  }
  printf("%d\n",cost);
  return 0;
}