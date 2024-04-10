#include <cstdio>
#include <map>

char str[200005];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  scanf("%s",str);
  int run=0;
  std::map<char,int> cnt;
  for(int i=0;str[i];i++){
    if(i>0&&str[i]==str[i-1]){
      run++;
    }else{
      run=1;
    }
    if(run==K){
      run=0;
      cnt[str[i]]++;
    }
  }
  int best=0;
  for(auto it:cnt){
    best=std::max(best,it.second);
  }
  printf("%d\n",best);
  return 0;
}