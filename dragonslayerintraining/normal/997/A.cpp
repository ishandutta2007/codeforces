#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdint.h>

char str[300005];

int main(){
  int64_t N,X,Y;
  scanf("%I64d %I64d %I64d",&N,&X,&Y);
  scanf("%s",str);
  std::vector<int64_t> blocks;
  for(int64_t i=0;str[i];i++){
    if(blocks.empty()||str[i]!=blocks.back()){
      blocks.push_back(str[i]);
    }
  }
  int64_t zcnt=std::count(blocks.begin(),blocks.end(),'0');
  if(zcnt==0){
    printf("0\n");
  }else{
    printf("%I64d\n",std::min(X,Y)*(zcnt-1)+Y);
  }
  return 0;
}