#include <iostream>
#include <queue>
#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int N,M,K;

bool forest[2000][2000];

int lastx=0,lasty=0;

int main(){
  fin>>N>>M>>K;
  std::queue<std::pair<int,int> > frontier;
  for(int i=0;i<K;i++){
    int X,Y;
    fin>>X>>Y;
    X--,Y--;
    frontier.push(std::pair<int,int>(X,Y));
  }
  while(!frontier.empty()){
    int x=frontier.front().first;
    int y=frontier.front().second;
    frontier.pop();
    if((x<0)||(x>=N)||(y<0)||(y>=M)){
      continue;
    }
    if(forest[x][y]){
      continue;
    }
    forest[x][y]=true;
    lastx=x;
    lasty=y;
    frontier.push(std::pair<int,int>(x,y+1));
    frontier.push(std::pair<int,int>(x,y-1));
    frontier.push(std::pair<int,int>(x+1,y));
    frontier.push(std::pair<int,int>(x-1,y));
  }
  fout<<lastx+1<<" "<<lasty+1<<std::endl;
  return 0;
}