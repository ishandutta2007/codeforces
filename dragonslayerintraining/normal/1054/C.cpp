#include <cstdio>
#include <vector>

int ls[1005];
int rs[1005];
int as[1005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&ls[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&rs[i]);
  }
  int rem=N;
  for(int curr=N;rem>0;curr--){
    std::vector<int> most;
    for(int i=0;i<N;i++){
      if(as[i]==0&&ls[i]==0&rs[i]==0){
	most.push_back(i);
	as[i]=curr;
	rem--;
      }
    }
    if(most.empty()){
      printf("NO\n");
      return 0;
    }
    for(int x:most){
      for(int i=0;i<x;i++){
	rs[i]--;
      }
      for(int i=x+1;i<N;i++){
	ls[i]--;
      }
    }
  }
  printf("YES\n");
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",as[i]);
  }
  printf("\n");
  return 0;
}