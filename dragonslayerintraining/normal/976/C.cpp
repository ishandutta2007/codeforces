#include <cstdio>
#include <algorithm>

struct Interval{
  int L,R,id;
  bool operator<(struct Interval other)const{
    if(L!=other.L)return L<other.L;
    if(R!=other.R)return R>other.R;
    return false;
  }
};
  
struct Interval rs[3000000];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int L,R,id;
    scanf("%d %d",&rs[i].L,&rs[i].R);
    rs[i].id=i+1;
  }
  std::sort(rs,rs+N);
  for(int i=1;i<N;i++){
    if(rs[i-1].R>=rs[i].R){
      printf("%d %d\n",rs[i].id,rs[i-1].id);
      return 0;
    }
  }
  printf("-1 -1\n");
  return 0;
}