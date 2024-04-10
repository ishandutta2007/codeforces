#include <iostream>
#include <queue>

long long cost=0;

std::priority_queue<std::pair<int,int> > replaces;

int main(){
  std::string str;
  std::cin>>str;
  
  int sum=0;
  for(int i=0;i<str.length();i++){
    if(str[i]=='('){
      sum++;
    }else if(str[i]==')'){
      sum--;
    }if(str[i]=='?'){
      str[i]=')';
      sum--;
      int open,close;
      std::cin>>open>>close;
      cost+=close;
      replaces.push(std::pair<int,int>(close-open,i));
    }
    while(sum<0){
      if(replaces.empty()){
	std::cout<<-1<<std::endl;
	return 0;
      }
      cost-=replaces.top().first;
      str[replaces.top().second]='(';
      replaces.pop();
      sum+=2;
    }
  }
  if(sum>0){
    std::cout<<-1<<std::endl;
    return 0;
  }
  std::cout<<cost<<std::endl;
  std::cout<<str<<std::endl;
  return 0;
}