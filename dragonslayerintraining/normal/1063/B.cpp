#include <cstdio>
#include <deque>

char grid[2005][2005];
int bad[2005][2005];
bool vis[2005][2005];

int main(){
  int N,M;
  int R,C;
  int maxL,maxR;
  scanf("%d %d",&N,&M);
  scanf("%d %d",&R,&C);
  scanf("%d %d",&maxL,&maxR);
  for(int r=1;r<=N;r++){
    scanf("%s",grid[r]+1);
  }
  std::deque<std::pair<std::pair<int,int>,int> > frontier;
  frontier.emplace_back(std::make_pair(R,C),0);
  while(!frontier.empty()){
    int r=frontier.front().first.first;
    int c=frontier.front().first.second;
    int d=frontier.front().second;
    frontier.pop_front();
    if(vis[r][c]) continue;
    if(grid[r][c]!='.') continue;
    vis[r][c]=true;
    bad[r][c]=d;
    frontier.emplace_front(std::make_pair(r-1,c),d);
    frontier.emplace_front(std::make_pair(r+1,c),d);
    int dx=c-C;
    if(d<maxR) frontier.emplace_back(std::make_pair(r,c+1),d+1);
    if(d-dx<maxL) frontier.emplace_back(std::make_pair(r,c-1),d);
  }
  int cnt=0;
  for(int r=1;r<=N;r++){
    for(int c=1;c<=M;c++){
      if(vis[r][c]) cnt++;
    }
  }
  printf("%d\n",cnt);
  return 0;
}