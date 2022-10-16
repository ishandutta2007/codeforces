#include <cstdio>

int main(){
  int N;
  scanf("%d",&N);
  int zero=0,one=1023;
  for(int i=0;i<N;i++){
    char c;
    int x;
    scanf(" %c %d",&c,&x);
    switch(c){
    case '&':zero&=x;one&=x;break;
    case '|':zero|=x;one|=x;break;
    case '^':zero^=x;one^=x;break;
    }
  }
  printf("2\n& %d\n^ %d\n",zero^one,zero);
  return 0;
}