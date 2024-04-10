#include <cstdio>
#include <vector>
#include <map>

std::vector<int> rem[100000];

int main(){
  int K,N,M;
  scanf("%d %d %d",&N,&K,&M);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    rem[A%M].push_back(A);
  }
  for(int i=0;i<M;i++){
    if(rem[i].size()>=K){
      printf("Yes\n");
      for(int j=0;j<K;j++){
	if(j>0){
	  printf(" ");
	}
	printf("%d",rem[i][j]);
      }
      printf("\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}