#include <iostream>
#include <vector>

int minimize(int now,int date){
  int best=9999;
  for(int i=0;i<10;i++){
    int x=date-(date/1%10-i)*1;
    if(x>=now){
      best=std::min(best,x);
    }
  }
  for(int i=0;i<10;i++){
    int x=date-(date/10%10-i)*10;
    if(x>=now){
      best=std::min(best,x);
    }
  }
  for(int i=0;i<10;i++){
    int x=date-(date/100%10-i)*100;
    if(x>=now){
      best=std::min(best,x);
    }
  }
  for(int i=0;i<10;i++){
    int x=date-(date/1000%10-i)*1000;
    if(x>=now){
      best=std::min(best,x);
    }
  }
  return best;
}

std::vector<int> out;

int main(){
  int N;
  std::cin>>N;
  int now=1000;
  for(int i=0;i<N;i++){
    int date;
    std::cin>>date;
    date=minimize(now,date);
    if(date<now){
      std::cout<<"No solution"<<std::endl;
      return 0;
    }
    now=date;
    out.push_back(date);
  }
  if(now>2011){
    std::cout<<"No solution"<<std::endl;
    return 0;
  }
  for(int i=0;i<N;i++){
    std::cout<<out[i]<<std::endl;
  }
  return 0;
}