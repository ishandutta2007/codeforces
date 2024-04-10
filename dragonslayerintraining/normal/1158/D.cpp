#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

struct Point{
  int x,y;
  Point():x(0),y(0){
  }
  Point(int x,int y):x(x),y(y){
  }
  void read(){
    scanf("%d %d",&x,&y);
  }
  Point operator-(Point p)const{
    return Point(x-p.x,y-p.y);
  }
  long long cross(Point p)const{
    return 1LL*x*p.y-1LL*y*p.x;
  }
}ps[2005];
bool used[2005];

char str[2005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    ps[i].read();
  }
  scanf("%s",str);
  int last=std::max_element(ps,ps+N,[](Point a,Point b){return (a.x!=b.x)?(a.x<b.x):(a.y<b.y);})-ps;
  used[last]=true;
  printf("%d ",last+1);
  for(int i=0;i<N-2;i++){
    int choice=-1;
    for(int j=0;j<N;j++){
      if(used[j]) continue;
      if((choice==-1)||(((ps[j]-ps[last]).cross(ps[choice]-ps[last])>0)^(str[i]=='R'))){
	choice=j;
      }
    }
    printf("%d ",choice+1);
    used[choice]=true;
    last=choice;
  }
  printf("%d\n",int(std::find(used,used+N,false)-used)+1);
  return 0;
}