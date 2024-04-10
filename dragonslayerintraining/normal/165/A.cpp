#include <iostream>

struct cpoint{
  int x,y;
}points[200];

int minx[2001],maxx[2001],miny[2001],maxy[2001];

int cnt=0;
int main(){
  int N;
  std::cin>>N;
  std::fill(minx,minx+2000,1e9);
  std::fill(maxx,maxx+2000,-1e9);
  std::fill(miny,miny+2000,1e9);
  std::fill(maxy,maxy+2000,-1e9);
  for(int i=0;i<N;i++){
    std::cin>>points[i].x>>points[i].y;
    points[i].x+=1000;
    points[i].y+=1000;
    minx[points[i].y]=std::min(minx[points[i].y],points[i].x);
    miny[points[i].x]=std::min(miny[points[i].x],points[i].y);
    maxx[points[i].y]=std::max(maxx[points[i].y],points[i].x);
    maxy[points[i].x]=std::max(maxy[points[i].x],points[i].y);
  }
  for(int i=0;i<N;i++){
    if((points[i].x>minx[points[i].y])&&
       (points[i].y>miny[points[i].x])&&
       (points[i].x<maxx[points[i].y])&&
       (points[i].y<maxy[points[i].x])){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  
  return 0;
}