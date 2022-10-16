#include <iostream>

std::string str;

int cost[101];

int main(){
  int N,D;
  std::cin>>N>>D>>str;
  cost[0]=0;
  for(int i=1;i<str.length();i++){
    cost[i]=1e9;
    if(str[i]=='1'){
      for(int k=0;k<=std::min(D,i);k++){
	cost[i]=std::min(cost[i],cost[i-k]+1);
      }
    }
  }
  std::cout<<((cost[N-1]==(int)1e9)?-1:cost[N-1])<<std::endl;
  return 0;
}