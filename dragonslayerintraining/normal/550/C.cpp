#include <iostream>

struct List* dp[101][8];

typedef struct List{
  int digit;
  struct List* next;
  List(int digit,struct List* next):digit(digit),next(next){
  }
}List;

void output(List* list){
  if(list!=NULL){
    output(list->next);
    std::cout<<list->digit;
  }
}

int main(){
  std::string N;
  std::cin>>N;
  for(int i=0;i<N.size();i++){
    for(int d=0;d<8;d++){
      if(dp[i][d]){
	dp[i+1][(d*10+N[i]-'0')%8]=new List(N[i]-'0',dp[i][d]);
	dp[i+1][d]=dp[i][d];
      }
    }
    if(N[i]!='0'){
      dp[i+1][(N[i]-'0')%8]=new List(N[i]-'0',NULL);
    }else{
      std::cout<<"YES"<<std::endl;
      std::cout<<0<<std::endl;
      return 0;
    }
  }
  if(dp[N.size()][0]){
    std::cout<<"YES"<<std::endl;
    output(dp[N.size()][0]);
    std::cout<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}