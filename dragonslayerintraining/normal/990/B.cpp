#include <cstdio>
#include <vector>
#include <algorithm>

int as[200005];
std::vector<int> left;

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::sort(as,as+N);
  for(int i=0;i<N;i++){
    while(left.size()&&left.back()<as[i]&&left.back()>=as[i]-K){
      left.pop_back();
    }
    left.push_back(as[i]);
  }
  printf("%d\n",(int)left.size());
  return 0;
}