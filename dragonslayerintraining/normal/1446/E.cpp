#include <cstdio>
#include <vector>
#include <map>
#include <set>

struct Point{
  int x,y;
  bool operator<(Point p)const{
    return std::make_pair(x,y)<std::make_pair(p.x,p.y);
  }
  bool operator==(Point p)const{
    return std::make_pair(x,y)==std::make_pair(p.x,p.y);
  }
};

std::vector<Point> neighbors(Point p){
  int sgn=(p.x%2==0)?1:-1;
  return std::vector<Point>{Point{p.x+1,p.y},
      Point{p.x-1,p.y},
	Point{p.x+sgn,p.y-sgn}};
}

std::set<Point> orig,infect;

std::map<Point,Point> uf;

Point find(Point p){
  if(!uf.count(p)){
    uf[p]=p;
  }
  return (p==uf[p])?p:uf[p]=find(uf[p]);
}

void add(Point p);

void attack(Point p){
  if(infect.count(p)) return;
  int cnt=0;
  for(Point q:neighbors(p)){
    if(infect.count(q)) cnt++;
  }
  if(cnt<2) return;
  add(p);
}
  

void add(Point p){
  if(infect.count(p)) return;
  infect.insert(p);
  for(Point q:neighbors(p)){
    if(infect.count(q)){
      if(find(p)==find(q)){
	printf("SICK\n");
	exit(0);
      }
      uf[find(p)]=find(q);
    }
  }
  for(Point q:neighbors(p)){
    attack(q);
  }
}

bool isbad(Point p){
  if(orig.count(p)) return false;
  for(Point q:neighbors(p)){
    if(!orig.count(q)) return false;
    for(Point r:neighbors(q)){
      if(p==r) continue;
      if(infect.count(r)) return false;
    }
  }
  return true;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    orig.insert(Point{X,Y});
    add(Point{X,Y});
  }
  int ans=0;
  for(auto p:orig){
    for(auto q:neighbors(p)){
      if(!orig.count(q)) ans++;
    }
  }
  std::set<Point> ccs;
  for(auto p:orig){
    ccs.insert(find(p));
  }
  ans-=ccs.size()*2;
  for(auto p:infect){
    if(isbad(p)){
      ans-=2;
    }
  }
  printf("RECOVERED\n%d\n",ans);
}