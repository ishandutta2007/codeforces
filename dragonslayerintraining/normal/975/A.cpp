#include <cstdio>
#include <set>

char str[10000];

std::set<int> set;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int mask=0;
    scanf("%s",str);
    for(int j=0;str[j];j++){
      mask|=(1<<(str[j]-'a'));
    }
    set.insert(mask);
  }
  printf("%d\n",(int)set.size());
  return 0;
}