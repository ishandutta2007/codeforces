#include <cstdio>
#include <vector>
#include <algorithm>

int as[100005];
int cs[100005];
int last=0;
std::vector<int> buf[100005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    as[i]=N-as[i];
    buf[as[i]].push_back(i);
    if(buf[as[i]].size()==as[i]){
      last++;
      for(int j:buf[as[i]]){
	cs[j]=last;
      }
      buf[as[i]].clear();
    }
  }
  if(*std::min_element(cs,cs+N)==0){
    printf("Impossible\n");
  }else{
    printf("Possible\n");
    for(int i=0;i<N;i++){
      if(i) printf(" ");
      printf("%d",cs[i]);
    }
    printf("\n");
  }
  return 0;
}