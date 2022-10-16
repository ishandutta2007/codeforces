#include <cstdio>
#include <map>

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  N=K+1;
  if(K==1){
    printf("! 1\n");
    return 0;
  }
  std::map<int,int> freq;
  for(int i=1;i<=N;i++){
    printf("?");
    for(int j=1;j<=N;j++){
      if(j==i) continue;
      printf(" %d",j);
    }
    printf("\n");
    fflush(stdout);
    int I,A;
    scanf("%d %d",&I,&A);
    freq[A]++;
  }
  printf("! %d\n",freq.rbegin()->second);
}