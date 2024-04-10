#include <cstdio>
#include <string>

void gen(int diff){
  for(int i=0;i<1000;i++){
    putchar('.');
  }
  putchar('\n');
  for(int i=0;i<1000;i++){
    if(i%2==0&&i/2<diff){
      putchar('X');
    }else{
      putchar('.');
    }
  }
  putchar('\n');
  for(int i=0;i<1000;i++){
    if(i==0){
      putchar('X');
    }else{
      putchar('.');
    }
  }
  putchar('\n');
}

char str[100];

int main(){
  scanf("%s",str);
  int last=0;
  for(int i=0;str[i];i++){
    gen((last-str[i]+250)%256+6);
    last=str[i];
  }
  return 0;
}