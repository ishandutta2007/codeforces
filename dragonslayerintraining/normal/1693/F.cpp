#include <cstdio>
#include <cassert>
#include <algorithm>
#include <map>

char str[200005];

int solve(){
  int N;
  scanf("%d",&N);
  scanf("%s",str);
  if(std::count(str,str+N,'1')<std::count(str,str+N,'0')){
    std::reverse(str,str+N);
    for(int i=0;i<N;i++){
      str[i]^='0'^'1';
    }
  }
  std::map<int,int> first;
  first[0]=0;
  int pref=0;
  for(int i=0;i<N;i++){
    if(str[i]=='1'){
      pref++;
    }else{
      pref--;
    }
    if(!first.count(pref)){
      first[pref]=i+1;
    }
  }
  int i=N;
  while(i>0&&str[i-1]=='1'){
    i--;
    pref--;
  }
  if(i==-pref){
    return 0;
  }
  int cnt=0;
  while(pref>0){
    //printf("i=%d pref=%d\n",i,pref);
    int shift=(i-first[pref])/2;
    pref-=shift;
    i-=shift;
    cnt++;
  }
  return cnt+1;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    printf("%d\n",solve());
  }
}