#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

std::vector<int> prefix;

void manacher(std::string orig){
  std::string str=".";
  for(char c:orig){
    str+=c;
    str+='.';
  }
  // printf("%s\n",str.c_str());
  std::vector<int> pal(str.length());
  int center=0;
  while(true){
    for(int i=pal[center];(center-i>=0)&&(center+i<str.length())&&
	  (str[center-i]==str[center+i]);i++){
      pal[center]=i;
    }
    int i=1;
    while((center-i>=0)&&(center+i<str.length())&&
	  (pal[center-i]<pal[center]-i)){
      pal[center+i]=pal[center-i];
      i++;
    }
    if(center+i==str.length()){
      break;
    }
    pal[center+i]=std::max(0,pal[center]-i);
    center+=i;
  }
  prefix.resize(str.length()/2+1);
  for(int i=0;i<str.length()/2+1;i++){
    if(pal[i]==i){
      prefix[i]=1;
    }
  }
  // for(int v:pal){
  //   printf("%d ",v);
  // }
  // printf("\n");
  // for(int v:prefix){
  //   printf("%d ",v);
  // }
  // printf("\n");
}

char str[5000005];
int deg[5000005];

int main(){
  scanf("%s",str);
  manacher(std::string(str));
  int len=strlen(str);
  int sum=0;
  for(int i=1;i<=len;i++){
    if(prefix[i]){
      deg[i]=deg[i/2]+1;
    }
    sum+=deg[i];
    // printf("%d: %d\n",i,deg[i]);
  }
  printf("%d\n",sum);
  return 0;
}