#include <cstdio>
#include <vector>
#include <algorithm>
#include <array>

int xs[1005];
int ys[1005];

std::vector<int> cpsx;
std::vector<int> cpsy;

int grid[1005][1005];
std::vector<int> horiz[1005],verti[1005];
std::vector<int> horiz_seg[1005],verti_seg[1005];

std::vector<int> edges[2005];
int match[2005];
bool vis[2005];
int node_cnt=0;

bool dfs_match(int u){
  vis[u]=true;
  for(int v:edges[u]){
    if(!match[v]||!vis[match[v]]&&dfs_match(match[v])){
      match[u]=v;
      match[v]=u;
      return true;
    }
  }
  return false;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&xs[i],&ys[i]);
    cpsx.push_back(xs[i]);
    cpsy.push_back(ys[i]);
  }
  std::sort(cpsx.begin(),cpsx.end());
  std::sort(cpsy.begin(),cpsy.end());
  cpsx.erase(std::unique(cpsx.begin(),cpsx.end()),cpsx.end());
  cpsy.erase(std::unique(cpsy.begin(),cpsy.end()),cpsy.end());
  for(int i=0;i<N;i++){
    xs[i]=std::lower_bound(cpsx.begin(),cpsx.end(),xs[i])-cpsx.begin();
    ys[i]=std::lower_bound(cpsy.begin(),cpsy.end(),ys[i])-cpsy.begin();
    horiz[ys[i]].push_back(xs[i]);
    verti[xs[i]].push_back(ys[i]);
  }
  for(int y=0;y<N;y++){
    std::sort(horiz[y].begin(),horiz[y].end());
    for(int j=0;j+1<horiz[y].size();j++){
      node_cnt++;
      for(int x=horiz[y][j]+1;x<horiz[y][j+1];x++){
	grid[y][x]=node_cnt;
      }
      horiz_seg[y].push_back(node_cnt);
    }
  }
  int left_cnt=node_cnt;
  for(int x=0;x<N;x++){
    std::sort(verti[x].begin(),verti[x].end());
    for(int j=0;j+1<verti[x].size();j++){
      node_cnt++;
      for(int y=verti[x][j]+1;y<verti[x][j+1];y++){
	if(grid[y][x]){
	  edges[node_cnt].push_back(grid[y][x]);
	  edges[grid[y][x]].push_back(node_cnt);
	}
      }
      verti_seg[x].push_back(node_cnt);
    }
  }
  int match_cnt=0;
  for(int i=1;i<=left_cnt;i++){
    if(!match[i]){
      std::fill(vis,vis+node_cnt,false);
      if(dfs_match(i)) match_cnt++;
    }
  }
  std::fill(vis,vis+node_cnt,false);
  for(int i=1;i<=left_cnt;i++){
    if(!vis[i]&&!match[i]){
      dfs_match(i);
    }
  }
  std::vector<std::array<int,4> > hans,vans;
  for(int y=0;y<N;y++){
    if(horiz[y].empty()) continue;
    int x1=cpsx[horiz[y][0]];
    for(int j=0;j+1<horiz[y].size();j++){
      //minimize splits
      if(!vis[horiz_seg[y][j]]){//[j:j+1] is in min vertex cover
	int x2=cpsx[horiz[y][j]];
	hans.push_back(std::array<int,4>({x1,cpsy[y],x2,cpsy[y]}));
	x1=cpsx[horiz[y][j+1]];
      }
    }
    int x2=cpsx[horiz[y].back()];
    hans.push_back(std::array<int,4>({x1,cpsy[y],x2,cpsy[y]}));
  }
  for(int x=0;x<N;x++){
    if(verti[x].empty()) continue;
    int y1=cpsy[verti[x][0]];
    for(int j=0;j+1<verti[x].size();j++){
      //minimize splits
      if(match[verti_seg[x][j]]&&vis[match[verti_seg[x][j]]]){//[j:j+1] is in min vertex cover
	int y2=cpsy[verti[x][j]];
	vans.emplace_back(std::array<int,4>{cpsx[x],y1,cpsx[x],y2});
	y1=cpsy[verti[x][j+1]];
      }
    }
    int y2=cpsy[verti[x].back()];
    vans.emplace_back(std::array<int,4>{cpsx[x],y1,cpsx[x],y2});
  }
  printf("%d\n",(int)hans.size());
  for(auto p:hans){
    printf("%d %d %d %d\n",p[0],p[1],p[2],p[3]);
  }
  printf("%d\n",(int)vans.size());
  for(auto p:vans){
    printf("%d %d %d %d\n",p[0],p[1],p[2],p[3]);
  }
  return 0;
}