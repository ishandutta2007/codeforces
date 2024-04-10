#include <iostream>
#include <algorithm>

struct cx{
  int n;
  char c;
  struct ncmp{
    bool operator()(struct cx a,struct cx b)const{
      return a.n<b.n;
    }
  };
}cnt[26];

bool del[26];

struct cx::ncmp ncmp;

int main(){
  std::string str;
  std::cin>>str;
  int K;
  std::cin>>K;
  for(int i=0;i<26;i++){
    cnt[i].c=char(i+'a');
  }
  for(int i=0;i<str.length();i++){
    cnt[str[i]-'a'].n++;
  }
  std::sort(cnt,cnt+26,ncmp);
  int distinct=0;
  for(int i=0;i<26;i++){
    if(cnt[i].n>0){
      if(cnt[i].n<=K){
	K-=cnt[i].n;
	del[cnt[i].c-'a']=true;
      }else{
	distinct++;
      }
    }
  }
  std::cout<<distinct<<std::endl;
  for(int i=0;i<str.length();i++){
    if(!del[str[i]-'a']){
      std::cout<<str[i];
    }
  }
  std::cout<<std::endl;
  return 0;
}