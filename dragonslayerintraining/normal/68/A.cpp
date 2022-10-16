#include <cstdio>
#include <algorithm>

int ps[4];
int A,B;

int main(){
  int P=1e9;
  for(int i=0;i<4;i++){
    scanf("%d",&ps[i]);
    P=std::min(P,ps[i]);
  }
  scanf("%d %d",&A,&B);
  printf("%d\n",std::max(0,std::min(P,B+1)-A));
  return 0;
}