#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

struct Point{
  int x,y;
  Point():x(0),y(0){
  }
  Point(int x,int y):x(x),y(y){
  }
}points[15000];

int X1,Y1,X2,Y2;

bool is_in_rect(int x,int y){
  return (x>X1)&&(x<X2)&&(y>Y1)&&(y<Y2);
}

bool is_in_rect(struct Point p){
  return is_in_rect(p.x,p.y);
}

int N;

void read_input(){
  scanf("%d %d %d %d",&X1,&Y2,&X2,&Y1);//Y1 and Y2 swapped
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&points[i].x,&points[i].y);
  }
  int outside=-1;
  for(int i=0;i<N;i++){
    if(!is_in_rect(points[i])){
      outside=i;
      break;
    }
  }
  if(outside==-1){
    printf("1\n");
    exit(0);
  }
  std::rotate(points,points+outside,points+N);
}

struct{
  std::vector<std::pair<int,int> > top,bot,left,right;
}crit;

int node_cnt=0;

void addline(struct Point from,struct Point to){
  if(from.x==to.x){
    int x=from.x;
    if(X1<x&&x<X2){
      if(from.y<=Y1^to.y<=Y1) crit.bot.emplace_back(x,node_cnt++);
      if(from.y>=Y2^to.y>=Y2) crit.top.emplace_back(x,node_cnt++);
    }
  }
  if(from.y==to.y){
    int y=from.y;
    if(Y1<y&&y<Y2){
      if(from.x<=X1^to.x<=X1) crit.left.emplace_back(y,node_cnt++);
      if(from.x>=X2^to.x>=X2) crit.right.emplace_back(y,node_cnt++);
    }
  }
}

std::vector<std::vector<int> > adj;

int black=0;

void dfs_color(int node,int parent,int color){
  if(color) black++;
  for(int child:adj[node]){
    if(child!=parent){
      dfs_color(child,node,color^1);
    }
  }
}

int main(){
  read_input();
  int wind=0;
  for(int i=0;i<N;i++){
    //printf("POINT %d,%d\n",points[i].x,points[i].y);
    int j=(i+1)%N;
    addline(points[i],points[j]);
    if(points[i].y>Y1){
      if(points[i].x>X1&&points[j].x<=X1){
	wind++;
      }
      if(points[i].x<=X1&&points[j].x>X1){
	wind--;
      }
    }
  }
  //printf("WIND=%d\n",wind);
  std::sort(crit.top.begin(),crit.top.end());
  std::sort(crit.bot.begin(),crit.bot.end());
  std::sort(crit.left.begin(),crit.left.end());
  std::sort(crit.right.begin(),crit.right.end());

  std::reverse(crit.top.begin(),crit.top.end());
  std::reverse(crit.left.begin(),crit.left.end());
  
  std::vector<std::pair<int,int>> ring;
  ring.insert(ring.end(),crit.bot.begin(),crit.bot.end());
  ring.insert(ring.end(),crit.right.begin(),crit.right.end());
  ring.insert(ring.end(),crit.top.begin(),crit.top.end());
  ring.insert(ring.end(),crit.left.begin(),crit.left.end());
  assert(ring.size()==node_cnt);
  assert(node_cnt%2==0);
  adj.resize(node_cnt/2+1);
  
  
  std::vector<int> stk;
  stk.push_back(node_cnt/2);
  for(auto pair:ring){
    int node=pair.second;
    if((node>>1)==stk.back()){
      stk.pop_back();
    }else{
      adj[stk.back()].push_back(node>>1);
      adj[node>>1].push_back(stk.back());
      stk.push_back(node>>1);
    }
  }
  dfs_color(node_cnt/2,-1,wind);
  printf("%d\n",black);
  return 0;
}