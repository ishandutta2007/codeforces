#include <cstdio>
#include <vector>

char str[1000005];

std::vector<int> stones;

void dfs(int i){
  if(str[i]=='\0'){
    return;
  }
  if(str[i]=='l'){
    dfs(i+1);
    stones.push_back(i);
  }else{
    stones.push_back(i);
    dfs(i+1);
  }
}

int main(){
  scanf("%s",str);
  dfs(0);
  for(int stone:stones){
    printf("%d\n",stone+1);
  }
  return 0;
}