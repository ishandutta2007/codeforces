#include <iostream>
#include <algorithm>
#include <cstdlib>

int as[6]={4,8,15,16,23,42};

int qs[4][3]={{0,1,0},{1,2,0},{2,3,0},{3,4,0}};

int query(int i,int j){
  std::cout<<"? "<<i+1<<" "<<j+1<<std::endl;
  int ans;
  std::cin>>ans;
  if(!ans) exit(0);
  return ans;
}

int main(){
  for(int i=0;i<4;i++){
    qs[i][2]=query(qs[i][0],qs[i][1]);
  }
  do{
    bool good=true;
    for(int i=0;i<4;i++){
      if(as[qs[i][0]]*as[qs[i][1]]!=qs[i][2]){
	good=false;
      }
    }
    if(good){
      std::cout<<"!";
      for(int i=0;i<6;i++){
	std::cout<<" "<<as[i];
      }
      std::cout<<std::endl;
    }
  }while(std::next_permutation(as,as+6));
  return 0;
}