#include <iostream>
#include <vector>

struct Unclosed{
  char c;
  int begin;
  int score;
  Unclosed(char c,int begin):c(c),begin(begin),score(0){
  }
};

std::vector<struct Unclosed> opens;
int best_score;
int best_begin,best_end;

int main(){
  std::string str;
  std::cin>>str;
  opens.push_back(Unclosed('$',0));
  for(int i=0;i<str.length();i++){
    switch(str[i]){
    case '(':
      opens.push_back(Unclosed(')',i+1));
      break;
    case '[':
      opens.back().score++;
      opens.push_back(Unclosed(']',i+1));
      break;
    case ')':
    case ']':
      if(opens.back().c==str[i]){
	int score=opens.back().score;
	opens.pop_back();
	opens.back().score+=score;
	if(opens.back().score>best_score){
	  best_score=opens.back().score;
	  best_begin=opens.back().begin;
	  best_end=i+1;
	}
      }else{
	opens.clear();
	opens.push_back(Unclosed('$',i+1));
      }
      break;
    }
  }
  std::cout<<best_score<<std::endl;
  for(int i=best_begin;i<best_end;i++){
    std::cout<<str[i];
  }
  std::cout<<std::endl;
  return 0;
}