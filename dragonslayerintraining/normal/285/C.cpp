#include <cstdio>
#include <algorithm>

int as[300005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::sort(as,as+N);
  int64_t diff=0;
  for(int i=0;i<N;i++){
    diff+=std::abs(i+1-as[i]);
  }
  printf("%I64d\n",diff);
  return 0;
}