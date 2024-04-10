#include <cstdio>
#include <cstring>
#include <initializer_list>
bool query(int x){
  char res[16];
  printf("%d\n",x);
  fflush(stdout);
  scanf("%s",res);
  return !strcmp(res,"yes");
}

int main(){
  for(int x:{2,3,5,7}){
    if(query(x)){
      for(int y:{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47}){
	if(x*y<=100&&query(x*y)){
	  printf("composite\n");
	  return 0;
	}
      }
      break;
    }
  }
  printf("prime\n");
  return 0;
}