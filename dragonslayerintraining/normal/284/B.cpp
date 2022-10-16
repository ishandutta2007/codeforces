#include <cstdio>

char str[200005];
int N;
int allin,in,folded;

int main(){
  scanf("%d %s",&N,str);
  for(int i=0;str[i];i++){
    switch(str[i]){
    case 'A':allin++;break;
    case 'I':in++;break;
    case 'F':folded++;break;
    }
  }
  if(in==0){
    printf("%d\n",allin);
  }else if(in==1){
    printf("1\n");
  }else{
    printf("0\n");
  }
  return 0;
}