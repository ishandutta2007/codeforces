#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

struct cpoint{
  enum etype{
    BEGIN=0,
    END=1,
  }type;
  int x;
  int h;
  cpoint(enum etype type,int x,int h):type(type),x(x),h(h){
  }
  static struct cpoint begin(int x,int h){
    return cpoint(BEGIN,x,h);
  }
  static struct cpoint end(int x,int h){
    return cpoint(END,x,h);
  }
  bool operator<(struct cpoint other)const{
    if(x!=other.x){return x<other.x;}
    if(type!=other.type){return type<other.type;}
    return h<other.h;
  }
};

std::vector<struct cpoint> points;

std::vector<std::pair<int,int> > polyline;

int main(){
  int N;
  fin>>N;
  for(int i=0;i<N;i++){
    int h,l,r;
    fin>>h>>l>>r;
    points.push_back(cpoint::begin(l,h));
    points.push_back(cpoint::end(r,h));
  }
  std::sort(points.begin(),points.end());

  std::multiset<int> heights;
  for(int i=0;i<points.size();i++){
    int x=points[i].x;
    int h=points[i].h;
    int oldmax=heights.empty()?0:*heights.rbegin();
    
    switch(points[i].type){
    case cpoint::BEGIN:heights.insert(h);break;
    case cpoint::END:heights.erase(heights.find(h));break;
    }
    
    int newmax=heights.empty()?0:*heights.rbegin();
    if(oldmax!=newmax){
      polyline.push_back(std::pair<int,int>(x,oldmax));
      polyline.push_back(std::pair<int,int>(x,newmax));
    }
  }
  std::vector<std::pair<int,int> > simple;
  for(int i=0;i<polyline.size();i++){
    std::pair<int,int> next(polyline[i].first,polyline[i].second);
    if((simple.size()>0)&&(next==simple.back())){
      simple.pop_back();
    }else{
      simple.push_back(next);
    }
  }
  
  fout<<simple.size()<<std::endl;
  for(int i=0;i<simple.size();i++){
    fout<<simple[i].first<<" "<<simple[i].second<<std::endl;
  }
  return 0;
}