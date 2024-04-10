#include <cstdio>
#include <cstring>

char str[1000005];
int border[1000005];
int occur[1000005];

int main(){
  scanf("%s",str);
  border[0]=-1;
  for(int i=0;str[i];i++){
    int k=border[i];
    while((k>=0)&&(str[k]!=str[i])){
      k=border[k];
    }
    border[i+1]=k+1;
  }
  for(int i=1;str[i];i++){
    occur[border[i]]++;
  }
  for(int k=border[strlen(str)];k>0;k=border[k]){
    if(occur[k]>0){
      str[k]='\0';
      printf("%s\n",str);
      return 0;
    }
  }
  printf("Just a legend\n");
  return 0;
}