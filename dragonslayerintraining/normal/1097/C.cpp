#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>

char str[1000005];
int len;

std::map<int,int> pos;

int ans=0;

void add(int x){
  if(pos.count(-x)&&pos[-x]>0){
    pos[-x]--;
    ans++;
  }else{
    pos[x]++;
  }
}

int add_str(int sgn){
  int open=0;
  for(int i=0;i<len;i++){
    if(str[i]=='('){
      open++;
    }else{
      if(--open<0){
	return -1;
      }
    }
  }
  add(sgn*open);
  return open;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%s",str);
    len=strlen(str);
    if(add_str(1)>=0) continue;
    std::reverse(str,str+len);
    for(int i=0;i<len;i++){
      str[i]^=('('^')');
    }
    add_str(-1);
  }
  printf("%d\n",ans);
  return 0;
}