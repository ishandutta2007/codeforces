#include <cstdio>
#include <cstring>
#include <algorithm>

char str[1000006];
char ans[1000006];
int ans_len=0;
int L,R;

void reduce(){
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      if(str[L+i]==str[R-1-j]){
	ans[ans_len++]=str[L+i];
	L+=i+1;
	R-=j+1;
	return;
      }
    }
  }
}

int main(){
  scanf("%s",str);
  L=0,R=strlen(str);
  while(R-L>3){
    reduce();
  }
  printf("%s",ans);
  printf("%c",str[L]);
  std::reverse(ans,ans+ans_len);
  printf("%s\n",ans);
}