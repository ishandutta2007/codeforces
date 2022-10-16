#include <iostream>

struct ctable{
  int x0,y0,x1,y1;
}table;

struct cradiator{
  int x,y;
  int r;
}radiators[1000];
int N;

int iscold(int x,int y){
  for(int i=0;i<N;i++){
    int dx=radiators[i].x-x;
    int dy=radiators[i].y-y;
    int r=radiators[i].r;
    if(dx*dx+dy*dy<=r*r){
      //std::cout<<"("<<x<<","<<y<<")\tin range of "<<i+1<<std::endl;
      return 0;
    }
  }
  //std::cout<<"("<<x<<","<<y<<")\tout of range"<<std::endl;
  return 1;
}

int main(){
  std::cin>>table.x0>>table.y0>>table.x1>>table.y1;
  if(table.x0>table.x1){
    std::swap(table.x0,table.x1);
  }
  if(table.y0>table.y1){
    std::swap(table.y0,table.y1);
  }
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>radiators[i].x>>radiators[i].y>>radiators[i].r;
  }
  int cold=0;
  for(int x=table.x0;x<table.x1;x++){
    cold+=iscold(x,table.y0);
  }
  for(int y=table.y0;y<table.y1;y++){
    cold+=iscold(table.x1,y);
  }
  for(int x=table.x1;x>table.x0;x--){
    cold+=iscold(x,table.y1);
  }
  for(int y=table.y1;y>table.y0;y--){
    cold+=iscold(table.x0,y);
  }
  std::cout<<cold<<std::endl;
  return 0;
}