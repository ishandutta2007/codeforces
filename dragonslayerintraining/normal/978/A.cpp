#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

std::set<int> occur;
std::vector<int> list;

int as[50];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=N-1;i>=0;i--){
    if(!occur.count(as[i])){
      occur.insert(as[i]);
      list.push_back(as[i]);
    }
  }
  std::reverse(list.begin(),list.end());
  printf("%d\n",(int)list.size());
  for(int i=0;i<list.size();i++){
    if(i) printf(" ");
    printf("%d",list[i]);
  }
  printf("\n");
  return 0;
}