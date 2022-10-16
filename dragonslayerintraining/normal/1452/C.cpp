#include <iostream>

int score(std::string s){
  int cnt=0;
  int res=0;
  for(char c:s){
    if(c=='('){
      cnt++;
    }else{
      if(cnt>0){
	cnt--;
	res++;
      }
    }
  }
  return res;
}

void solve(){
  std::string str;
  std::cin>>str;
  std::string a,b;
  for(char c:str){
    if(c=='(') a+='(';
    if(c==')') a+=')';
    if(c=='[') b+='(';
    if(c==']') b+=')';
  }
  printf("%d\n",score(a)+score(b));
}

int main(){
  int T;
  std::cin>>T;
  while(T--){
    solve();
  }
}