#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

std::map<int,std::vector<int> > where;

char str[105];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int S;
    scanf("%d",&S);
    where[S].push_back(i);
  }
  std::fill(str,str+N,'A');
  int flag=0;
  for(auto it:where){
    if(it.second.size()==1){
      str[it.second[0]]='A'+flag;
      flag^=1;
    }
  }
  for(auto it:where){
    if(it.second.size()>2){
      if(flag){
	str[it.second[0]]='B';
	flag=0;
      }
    }
  }
  if(flag){
    printf("NO\n");
  }else{
    printf("YES\n");
    printf("%s\n",str);
  }
  return 0;
}