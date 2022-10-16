#include <cstdio>
#include <string>

char str[100005];

int main(){
  fgets(str,100005,stdin);
  for(int i=0;str[i];i++){
    for(;str[i]==' ';i++);
    if(str[i]=='\n'){
      break;
    }
    if(str[i]=='"'){
      std::string lexeme;
      for(i++;str[i]!='"';i++){
	lexeme+=str[i];
      }
      printf("<%s>\n",lexeme.c_str());
    }else{
      std::string lexeme;
      for(;(str[i]!=' ')&&(str[i]!='\n');i++){
	lexeme+=str[i];
      }
      printf("<%s>\n",lexeme.c_str());
    }
  }
  return 0;
}