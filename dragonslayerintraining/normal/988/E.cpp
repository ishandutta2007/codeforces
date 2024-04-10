#include <iostream>

const int INF=1e9+7;

std::string str;

bool movetoend(std::string& s,char c,int& cost){
  for(int i=s.length()-1;i>=0;i--){
    if(s[i]==c){
      cost+=s.length()-1-i;
      s.erase(s.begin()+i);
      return true;
    }
  }
  return false;
}

bool movenonzero(std::string& s,int& cost){
  for(int i=0;i<s.length();i++){
    if(s[i]!='0'){
      cost+=i;
      s.erase(s.begin()+i);
      return true;
    }
  }
  return false;
}

int best=INF;

void check(char a,char b){
  int cost=0;
  std::string s=str;
  if(!movetoend(s,b,cost)) return;
  if(!movetoend(s,a,cost)) return;
  if(s.size()&&s[0]=='0'){
    if(!movenonzero(s,cost)) return;
  }
  best=std::min(best,cost);
}

int main(){
  std::cin>>str;
  check('0','0');
  check('2','5');
  check('5','0');
  check('7','5');
  std::cout<<((best<INF)?best:-1)<<std::endl;
  return 0;
}