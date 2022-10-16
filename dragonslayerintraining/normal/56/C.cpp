#include <iostream>
#include <cctype>
#include <cassert>
#include <set>

struct cparser{
  std::multiset<std::string> supers;
  std::string line;
  int i;
  int cnt;
  cparser(std::string line):line(line),i(0),cnt(0){
  }
  void parse(){
    std::string name;
    while(std::isalpha(line[i])){
      name+=line[i];
      i++;
    }
    if(line[i]==':'){
      supers.insert(name);
      i++;
      while(line[i]!='.'){
	parse();
	if(line[i]!=','){
	  break;
	}
	i++;
      }
      supers.erase(supers.find(name));
    }
    assert(line[i]=='.');
    i++;
    cnt+=supers.count(name);
  }
  int count(){
    parse();
    return cnt;
  }
};

int main(){
  std::string line;
  std::getline(std::cin,line);
  std::cout<<cparser(line).count()<<std::endl;
  return 0;
}