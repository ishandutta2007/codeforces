#include <algorithm>
#include <cstdio>

int as[10005];

int main(){
  int N;
  scanf("%d",&N);
  int cnt=0;
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
    as[i]=std::max(as[i],as[i-1]);
    if(as[i]==i){
      cnt++;
    }
  }
  printf("%d\n",cnt);
  return 0;
}