#include <cstdio>

char str[2005];

int main(){
  int N,P;
  scanf("%d %d",&N,&P);
  scanf("%s",str);
  bool bad=false;
  for(int i=0;i<N-P;i++){
    if(str[i]!=str[i+P]||str[i]=='.'){
      if(str[i]=='0') str[i+P]='1';
      else if(str[i]=='1') str[i+P]='0';
      else if(str[i+P]=='0') str[i]='1';
      else str[i]='0';
      bad=true;
      break;
    }
  }
  if(bad){
    for(int i=0;i<N;i++){
      if(str[i]=='.'){
	str[i]='1';
      }
    }
    printf("%s\n",str);
  }else{
    printf("No\n");
  }
  return 0;
}