#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::pair<int,int> > dirs;

int N,M;
std::string grid[100];
int startx,starty;

std::string prgm;

int main(){
  dirs.emplace_back(-1,0);
  dirs.emplace_back(1,0);
  dirs.emplace_back(0,-1);
  dirs.emplace_back(0,1);
  std::sort(dirs.begin(),dirs.end());
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::cin>>grid[i];
    for(int j=0;j<M;j++){
      if(grid[i][j]=='S'){
	startx=i;
	starty=j;
      }
    }
  }
  std::cin>>prgm;
  int cnt=0;
  do{
    int x=startx,y=starty;
    for(char c:prgm){
      x+=dirs[c-'0'].first;
      y+=dirs[c-'0'].second;
      if((x<0)||(x>=N)||(y<0)||(y>=M)){
	break;
      }
      if(grid[x][y]=='#'){
	break;
      }
      if(grid[x][y]=='E'){
	cnt++;
	break;
      }
    }
  }while(std::next_permutation(dirs.begin(),dirs.end()));

  std::cout<<cnt<<std::endl;
  return 0;
}