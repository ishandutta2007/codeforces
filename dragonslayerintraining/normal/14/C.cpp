#include <iostream>
#include <set>

struct cseg{
  int x0,y0,x1,y1;
  cseg(int x0,int y0,int x1,int y1):x0(x0),y0(y0),x1(x1),y1(y1){
    if(x0+y0>x1+y1){
      std::swap(x0,x1);
      std::swap(y0,y1);
    }
  }
  bool operator<(struct cseg b)const{
    if(x0!=b.x0){
      return x0<b.x0;
    }else if(y0!=b.y0){
      return y0<b.y0;
    }else if(x1!=b.x1){
      return x1<b.x1;
    }else{
      return y1<b.y1;
    }
  }
};

struct cpoint{
  int x,y;
  cpoint(int x,int y):x(x),y(y){
  }
  bool operator<(struct cpoint b)const{
    if(x!=b.x){return x<b.x;}
    return y<b.y;
  }
};

std::set<struct cseg> segs;
std::set<struct cpoint> points;

bool test(){
  int hcnt=0,vcnt=0;
  for(int i=0;i<4;i++){
    int x0,y0,x1,y1;
    std::cin>>x0>>y0>>x1>>y1;
    if((x0==x1)&&(y0==y1)){
      return false;
    }else if(x0==x1){
      vcnt++;
    }else if(y0==y1){
      hcnt++;
    }else{
      return false;
    }
    segs.insert(cseg(x0,y0,x1,y1));
    points.insert(cpoint(x0,y0));
    points.insert(cpoint(x1,y1));
  }
  if((hcnt!=2)&&(vcnt!=2)){
    return false;
  }
  if(points.size()!=4){
    return false;
  }
  if(segs.size()!=4){
    return false;
  }
  return true;
}

int main(){
  if(test()){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}