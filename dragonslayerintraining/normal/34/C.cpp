#include <iostream>
#include <set>

std::set<int> pages;

int main(){
  do{
    int n;
    std::cin>>n;
    pages.insert(n);
  }while(std::cin.get()==',');

  int start=-1;
  int end=0;
  int nth=0;
  for(std::set<int>::iterator it=pages.begin();it!=pages.end();it++){
    if(start==-1){
      start=*it;
      end=*it;
      continue;
    }
    if((*it)-end>1){
      if(nth>0){
	std::cout<<",";
      }
      if(start==end){
	std::cout<<start;
      }else{
	std::cout<<start<<"-"<<end;
      }
      nth++;
      start=*it;
    }
    end=*it;
  }
  if(start>=0){
    if(nth>0){
      std::cout<<",";
    }
    if(start==end){
      std::cout<<start<<std::endl;
    }else{
      std::cout<<start<<"-"<<end<<std::endl;
    }
    nth++;
  }
  
  return 0;
}