#include <iostream>
#include <algorithm>

int diff[1001];
int toffee[1000];

int main(){
  int N;
  std::cin>>N;
  std::string str;
  std::cin>>str;
  diff[0]=1e9;
  for(int i=0;i<str.length();i++){
    switch(str[i]){
    case 'L':diff[i+1]=1;break;
    case 'R':diff[i+1]=-1;break;
    case '=':diff[i+1]=0;break;
    }
  }
  diff[N]=1e9;
  for(int t=0;t<N;t++){
    for(int i=0;i<N;i++){
      switch(diff[i]){
      case 0:toffee[i]=std::max(toffee[i],toffee[i-1]);break;
      case -1:toffee[i]=std::max(toffee[i],toffee[i-1]+1);break;
      }
      switch(diff[i+1]){
      case 0:toffee[i]=std::max(toffee[i],toffee[i+1]);break;
      case 1:toffee[i]=std::max(toffee[i],toffee[i+1]+1);break;
      }
    }
  }
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<toffee[i]+1;
  }
  std::cout<<std::endl;
  return 0;
}