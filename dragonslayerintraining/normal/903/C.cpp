#include <cstdio>
#include <map>

std::map<int,int> cnt;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    cnt[A]++;
  }
  int max=0;
  for(std::pair<int,int> p:cnt){
    max=std::max(max,p.second);
  }
  printf("%d\n",max);
  return 0;
}