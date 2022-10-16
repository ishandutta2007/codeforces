#include <iostream>

int last[256];
int wide[256];

int main(){
  std::string str;
  std::cin>>str;
  for(char c='a';c<='z';c++){
    last[c]=-1;
  }
  for(int i=0;i<str.length();i++){
    wide[str[i]]=std::max<int>(wide[str[i]],i-last[str[i]]);
    last[str[i]]=i;
  }
  for(char c='a';c<='z';c++){
    wide[c]=std::max<int>(wide[c],str.length()-last[c]);
  }
  int best=str.length();
  for(char c='a';c<='z';c++){
    best=std::min(best,wide[c]);
  }
  std::cout<<best<<std::endl;
  return 0;
}