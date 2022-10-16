#include <cstdio>
#include <map>
#include <vector>
#include <array>

const int INF=1e9+7;

std::map<int,int> cpsx,cpsy;

int cap[301][301];

std::vector<std::array<int,4> > rects;

bool vis[301];
int SRC,SNK,SIZE=0;

int dfs(int x,int flow,int scale){
  if(vis[x]) return 0;
  vis[x]=true;
  if(x==SNK) return flow;
  for(int y=0;y<SIZE;y++){
    if(cap[x][y]>=scale&&!vis[y]){
      int tmp=dfs(y,std::min(flow,cap[x][y]),scale);
      if(tmp>0){
	cap[x][y]-=tmp;
	cap[y][x]+=tmp;
	return tmp;
      }
    }
  }
  return 0;
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int X1,Y1,X2,Y2;
    scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
    X1--,Y1--;
    rects.push_back({X1,Y1,X2,Y2});
    cpsx[X1],cpsx[X2];
    cpsy[Y1],cpsy[Y2];
  }
  int lastx=0;
  for(auto& it:cpsx){
    it.second=lastx++;
  }
  int lasty=0;
  for(auto& it:cpsy){
    it.second=lasty++;
  }
  for(auto rect:rects){
    int X1=cpsx[rect[0]];
    int Y1=cpsy[rect[1]];
    int X2=cpsx[rect[2]];
    int Y2=cpsy[rect[3]];
    for(int x=X1;x<X2;x++){
      for(int y=Y1;y<Y2;y++){
	cap[x][y+lastx]=INF;
      }
    }
  }
  SRC=lastx+lasty;
  SNK=lastx+lasty+1;
  SIZE=lastx+lasty+2;
  {
    std::vector<std::pair<int,int> > xs(cpsx.begin(),cpsx.end());
    for(int i=0;i+1<lastx;i++){
      cap[SRC][i]=xs[i+1].first-xs[i].first;
    }
  }
  {
    std::vector<std::pair<int,int> > ys(cpsy.begin(),cpsy.end());
    for(int i=0;i+1<lasty;i++){
      cap[i+lastx][SNK]=ys[i+1].first-ys[i].first;
    }
  }
  int maxflow=0;
  int scale=1<<30;
  while(scale){
    std::fill(vis,vis+SIZE,false);
    int tmp=dfs(SRC,INF,scale);
    if(tmp>0){
      maxflow+=tmp;
    }else{
      scale>>=1;
    }
  }
  printf("%d\n",maxflow);    
}