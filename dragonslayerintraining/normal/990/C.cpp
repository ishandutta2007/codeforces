#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stdint.h>

char str[300005];

int64_t fwd[300005];
int64_t bkwd[300005];

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t s=0;s<N;s++){
    scanf("%s",str);
    {
      int64_t open=0;
      for(int64_t i=0;str[i];i++){
	if(str[i]=='(') open++; else open--;
	if(open<0) break;
      }
      if(open>=0){
	fwd[open]++;
	//printf("%I64d: FWD %I64d\n",s,open);
      }
    }
    std::reverse(str,str+strlen(str));
    {
      int64_t open=0;
      for(int64_t i=0;str[i];i++){
	if(str[i]==')') open++; else open--;
	if(open<0) break;
      }
      if(open>=0){
	bkwd[open]++;
	//printf("%I64d: BKWD %I64d\n",s,open);
      }
    }
  }
  int64_t total=0;
  for(int64_t i=0;i<=300000;i++){
    total+=fwd[i]*bkwd[i];
  }
  printf("%I64d\n",total);
  return 0;
}