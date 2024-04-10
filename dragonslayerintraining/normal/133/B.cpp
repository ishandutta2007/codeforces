#include <iostream>
#include <map>

const int MOD=1000003;

int main(){
  std::map<char,int> map;
  map['>']=8;
  map['<']=9;
  map['+']=10;
  map['-']=11;
  map['.']=12;
  map[',']=13;
  map['[']=14;
  map[']']=15;
  std::string str;
  std::cin>>str;
  int ac=0;
  for(int i=0;i<str.length();i++){
    ac=((ac*16)%MOD+map[str[i]])%MOD;
  }
  std::cout<<ac<<std::endl;
  return 0;
}