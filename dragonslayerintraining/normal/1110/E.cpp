#include <cstdio>
#include <algorithm>

int cs[200005];
int ts[200005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&cs[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&ts[i]);
  }
  for(int i=N-1;i>0;i--){
    cs[i]-=cs[i-1];
    ts[i]-=ts[i-1];
  }
  std::sort(cs+1,cs+N);
  std::sort(ts+1,ts+N);
  if(std::equal(cs,cs+N,ts)){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}