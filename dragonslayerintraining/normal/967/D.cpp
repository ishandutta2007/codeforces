#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stdint.h>

int N;
int X1,X2;
std::pair<int,int> cs[300000];
int t=0;

void check(){
  int split=-1;
  for(int i=0;i<300000;i++){
    if(cs[i].first*int64_t(i+1)>=X1){
      split=i;
      break;
    }
  }
  if(split<0) return;
  for(int i=split+1;i<300000;i++){
    if(cs[i].first*int64_t(i-split)>=X2){
      printf("Yes\n");
      std::vector<int> t1,t2;
      for(int k=0;k<=split;k++){
	t1.push_back(cs[k].second);
      }
      for(int k=split+1;k<=i;k++){
	t2.push_back(cs[k].second);
      }
      if(t) std::swap(t1,t2);
      printf("%d %d\n",(int)t1.size(),(int)t2.size());
      for(int k=0;k<t1.size();k++){
	if(k) printf(" ");
	printf("%d",t1[k]);
      }
      printf("\n");
      for(int k=0;k<t2.size();k++){
	if(k) printf(" ");
	printf("%d",t2[k]);
      }
      printf("\n");
      exit(0);
    }
  }
}

int main(){
  scanf("%d %d %d",&N,&X1,&X2);
  for(int i=0;i<N;i++){
    scanf("%d",&cs[i].first);
    cs[i].second=i+1;
  }
  std::sort(cs,cs+N);
  std::reverse(cs,cs+N);
  for(t=0;t<2;t++){
    check();
    std::swap(X1,X2);
  }
  printf("No\n");
  return 0;
}