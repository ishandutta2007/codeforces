#include <cstdio>

char str[105];

int main(){
  int N,M;
  scanf("%d %d %s",&N,&M,str);
  for(int i=0;i<M;i++){
    int L,R;
    char c1,c2;
    scanf("%d %d %c %c",&L,&R,&c1,&c2);
    for(int i=L-1;i<R;i++){
      if(str[i]==c1){
	str[i]=c2;
      }
    }
  }
  printf("%s\n",str);
  return 0;
}