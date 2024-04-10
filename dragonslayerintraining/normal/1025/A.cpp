#include <cstdio>
#include <map>

char str[100005];

int main(){
  int N;
  scanf("%d %s",&N,str);
  std::map<int,int> cnt;
  for(int i=0;i<N;i++){
    cnt[str[i]]++;
  }
  bool uniq=true;
  for(auto pair:cnt){
    if(pair.second!=1){
      uniq=false;
    }
  }
  if(uniq&&cnt.size()>=2){
    printf("No\n");
  }else{
    printf("Yes\n");
  }
  return 0;
}