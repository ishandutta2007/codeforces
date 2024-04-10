#include <cstdio>

int main(){
  char c;
  int mode=1;
  int ac=0;
  int num;
  while((c=getchar())!='\n'){
    if(c=='+'){
      ac+=num*mode;
      num=0;
      mode=1;
    }
    if(c=='-'){
      ac+=num*mode;
      num=0;
      mode=-1;
    }
    num=num*10+(c-'0');
  }
  ac+=num*mode;
  
  printf("%d\n",ac);
  return 0;
}