#include <cstdio>
#include <cstring>

int cnt=0;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    char str[30];
    scanf("%s",str);
    if(!strcmp(str,"Tetrahedron")){
      cnt+=4;
    }else if(!strcmp(str,"Cube")){
      cnt+=6;
    }else if(!strcmp(str,"Octahedron")){
      cnt+=8;
    }else if(!strcmp(str,"Dodecahedron")){
      cnt+=12;
    }else if(!strcmp(str,"Icosahedron")){
      cnt+=20;
    }
  }
  printf("%d\n",cnt);
  return 0;
}