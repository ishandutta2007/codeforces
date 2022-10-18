#include <cstdio>
#include <algorithm>

char str[200005];

int main(){
  int N,A,B;
  scanf("%d %d %d %s",&N,&A,&B,str);
  int empty=0;
  int use=0;
  int bonus=0;
  for(int i=0;i<=N;i++){
    if(str[i]=='.'){
      empty++;
    }else{
      use+=empty/2;
      bonus+=empty%2;
      empty=0;
    }
  }
  //printf("USE %d\n",use);
  //printf("BONUS %d\n",bonus);
  int total=0;
  total+=std::min(A,use);
  A-=std::min(A,use);
  total+=std::min(B,use);
  B-=std::min(B,use);
  total+=std::min(bonus,A+B);
  printf("%d\n",total);
  return 0;
}