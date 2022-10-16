#include <cstdio>
#include <array>
#include <algorithm>
#include <iterator>

std::array<int,4> ps[2000005];

template<class Iterator>
Iterator reduce(Iterator begin,Iterator end,Iterator out_begin,int d){
  //printf("reduce[%ld,%ld):%d\n",begin-ps,end-ps,d);
  if(end-begin<2){
    return std::copy(begin,end,out_begin);
  }
  auto mid=std::find_if(begin,end,[=](typename std::iterator_traits<Iterator>::value_type x){return x[d]!=(*begin)[d];});
  auto out_end=reduce(mid,end,reduce(begin,mid,out_begin,d+1),d);
  while(out_end-out_begin>=2){
    printf("%d ",(*(--out_end))[3]);
    printf("%d\n",(*(--out_end))[3]);
  }
  return out_end;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d %d",&ps[i][0],&ps[i][1],&ps[i][2]);
    ps[i][3]=i+1;
  }
  std::sort(ps,ps+N);
  /*for(int i=0;i<N;i++){
    printf("P: %d %d %d\n",ps[i][0],ps[i][1],ps[i][2]);
  }
  */
  reduce(ps,ps+N,ps+N,0);
}