#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<std::string> > plate;

struct cpoint{
  int x,y,z;
  cpoint(int x,int y,int z):x(x),y(y),z(z){
  }
};

int main(){
  int K,N,M;
  std::cin>>K>>N>>M;
  plate.resize(K);
  for(int i=0;i<K;i++){
    plate[i].resize(N);
    for(int j=0;j<N;j++){
      std::cin>>plate[i][j];
    }
  }
  std::queue<struct cpoint> frontier;
  int time=0;
  int X,Y;
  std::cin>>X>>Y;
  frontier.push(cpoint(0,X-1,Y-1));
  while(!frontier.empty()){
    struct cpoint p=frontier.front();
    frontier.pop();
    if((p.x<0)||(p.x>=K)||
       (p.y<0)||(p.y>=N)||
       (p.z<0)||(p.z>=M)){
      continue;
    }
    if(plate[p.x][p.y][p.z]=='.'){
      plate[p.x][p.y][p.z]='#';
      time++;
      frontier.push(cpoint(p.x,p.y,p.z+1));
      frontier.push(cpoint(p.x,p.y,p.z-1));
      frontier.push(cpoint(p.x,p.y+1,p.z));
      frontier.push(cpoint(p.x,p.y-1,p.z));
      frontier.push(cpoint(p.x+1,p.y,p.z));
      frontier.push(cpoint(p.x-1,p.y,p.z));
    }
  }
  std::cout<<time<<std::endl;
  return 0;
}