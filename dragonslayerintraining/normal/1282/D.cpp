#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>

int query(std::string s){
  printf("%s\n",s.c_str());
  fflush(stdout);
  int res;
  scanf("%d",&res);
  if(res==0) exit(0);
  if(res==-1) exit(0);
  return res;
}

int main(){
  int na=300-query(std::string(300,'a'));
  int nb=300-query(std::string(300,'b'));
  int len=na+nb;
  if(na==0){
    query(std::string(nb,'b'));
    assert(0);
  }
  if(nb==0){
    query(std::string(na,'a'));
    assert(0);
  }
  std::string s(len,'a');
  int res=nb;
  for(int i=0;i<len;i++){
    s[i]='b';
    int tmp=query(s);
    if(tmp<res){
      res=tmp;
    }else{
      s[i]='a';
    }
  }
  assert(0);
}