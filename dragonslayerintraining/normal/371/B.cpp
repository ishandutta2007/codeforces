#include <cstdio>


int cntA[3];
int cntB[3];

int main(){
  int A,B;
  scanf("%d %d",&A,&B);
  while(A%2==0) A/=2,cntA[0]++;
  while(A%3==0) A/=3,cntA[1]++;
  while(A%5==0) A/=5,cntA[2]++;
  while(B%2==0) B/=2,cntB[0]++;
  while(B%3==0) B/=3,cntB[1]++;
  while(B%5==0) B/=5,cntB[2]++;
  if(A!=B){
    printf("-1\n");
    return 0;
  }
  int cost=0;
  while(cntA[2]>cntB[2]){
    cntA[2]--;
    cost++;
  }
  while(cntA[2]<cntB[2]){
    cntB[2]--;
    cost++;
  }
  while(cntA[1]>cntB[1]){
    cntA[1]--;
    cost++;
  }
  while(cntA[1]<cntB[1]){
    cntB[1]--;
    cost++;
  }
  while(cntA[0]>cntB[0]){
    cntA[0]--;
    cost++;
  }
  while(cntA[0]<cntB[0]){
    cntB[0]--;
    cost++;
  }
  printf("%d\n",cost);
  return 0;
}