#include <cstdio>
#include <cstdlib>

typedef struct Point{
  int x,y;
  Point():x(0),y(0){
  }
  Point(int x,int y):x(x),y(y){
  }
}Point;

char grid[1005][1005];
int N,M;

bool reachable=false;

void setT(int x,int y){
  grid[x][y]='T';
}

void scanT1(int x,int y);

template<void(*Func)(int,int)>
void spread(Point S){
  for(int i=S.x;i<N;i++){
    if(grid[i][S.y]=='*'){
      break;
    }else{
      Func(i,S.y);
    }
  }
  for(int i=S.x;i>=0;i--){
    if(grid[i][S.y]=='*'){
      break;
    }else{
      Func(i,S.y);
    }
  }
  for(int i=S.y;i<M;i++){
    if(grid[S.x][i]=='*'){
      break;
    }else{
      Func(S.x,i);
    }
  }
  for(int i=S.y;i>=0;i--){
    if(grid[S.x][i]=='*'){
      break;
    }else{
      Func(S.x,i);
    }
  }  
}

void scanT0(int x,int y){
  if(grid[x][y]=='T'){
    printf("YES\n");
    exit(0);
  }
}

void scanT1(int x,int y){
  spread<scanT0>(Point(x,y));
}


int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%s",grid[i]);
  }
  Point S,T;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      switch(grid[i][j]){
      case 'S':S=Point(i,j);break;
      case 'T':T=Point(i,j);break;
      default:break;
      }
    }
  }
  spread<setT>(T);
  spread<scanT1>(S);
  printf("NO\n");
  return 0;
}