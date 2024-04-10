#include <iostream>

int pop[1<<10];

void solve(std::string str){
  int ac=0;
  for(char c:str){
    ac^=(1<<(c-'0'));
  }
  for(int i=str.length()-1;i>=0;i--){
    int D=str[i]-'0';
    ac^=(1<<D);
    for(int d=D-1;d>=(i==0);d--){
      if(pop[ac^(1<<d)]<=str.length()-1-i){
	str[i++]=(d+'0');
	ac^=(1<<d);
	int end=str.length();
	for(int k=0;k<10;k++){
	  if((ac>>k)&1){
	    str[--end]=(k+'0');
	  }
	}
	while(i<end){
	  str[i++]='9';
	}
	std::cout<<str<<std::endl;
	return;
      }
    }
  }
  for(int i=0;i<str.length()-2;i++){
    std::cout<<'9';
  }
  std::cout<<std::endl;
}

int main(){
  for(int i=1;i<(1<<10);i++){
    pop[i]=pop[i-(i&-i)]+1;
  }
  
  int T;
  std::cin>>T;
  while(T-->0){
    std::string str;
    std::cin>>str;
    solve(str);
  }
  return 0;
}