#include <iostream>

std::string grid[10];

bool winnable(int x,int y,int xdir,int ydir){
  int miss=0;
  for(int i=0;i<5;i++){
    if((x<0)||(y<0)||(x>=10)||(y>=10)){
      return false;
    }
    if(grid[x][y]=='O'){
      return false;
    }else if(grid[x][y]=='.'){
      if(++miss>1){
	return false;
      }
    }
    x+=xdir,y+=ydir;
  }
  return true;
}

bool winnable(){
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(winnable(i,j,0,1)){return true;}
      if(winnable(i,j,1,1)){return true;}
      if(winnable(i,j,1,0)){return true;}
      if(winnable(i,j,1,-1)){return true;}
      if(winnable(i,j,0,-1)){return true;}
      if(winnable(i,j,-1,-1)){return true;}
      if(winnable(i,j,-1,0)){return true;}
      if(winnable(i,j,-1,1)){return true;}
    }
  }
  return false;
}

int main(){
  for(int i=0;i<10;i++){
    std::cin>>grid[i];
  }
  if(winnable()){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;   
}