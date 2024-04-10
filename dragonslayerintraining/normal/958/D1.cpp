#include <cstdio>
#include <map>

double to[200000];
std::map<double,int> at;

int main(){
  int M;
  scanf("%d",&M);
  for(int i=0;i<M;i++){
    int A,B,C;
    scanf(" (%d+%d)/%d",&A,&B,&C);
    to[i]=double(A+B)/C;
    at[to[i]]++;
  }
  for(int i=0;i<M;i++){
    if(i) printf(" ");
    printf("%d",at[to[i]]);
  }
  printf("\n");
  return 0;
}