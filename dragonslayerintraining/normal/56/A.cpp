#include <iostream>
#include <cctype>
#include <cstdio>
#include <set>

std::set<std::string> alcoholic;

int main(){
  alcoholic.insert("ABSINTH");
  alcoholic.insert("BEER");
  alcoholic.insert("BRANDY");
  alcoholic.insert("CHAMPAGNE");
  alcoholic.insert("GIN");
  alcoholic.insert("RUM");
  alcoholic.insert("SAKE");
  alcoholic.insert("TEQUILA");
  alcoholic.insert("VODKA");
  alcoholic.insert("WHISKEY");
  alcoholic.insert("WINE");
  int N;
  std::cin>>N;
  int cnt=0;
  for(int i=0;i<N;i++){
    std::string line;
    std::cin>>line;
    if(std::isdigit(line[0])){
      int age;
      sscanf(line.c_str(),"%d",&age);
      if(age<18){
	cnt++;
      }
    }else{
      if(alcoholic.count(line)){
	cnt++;
      }
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}