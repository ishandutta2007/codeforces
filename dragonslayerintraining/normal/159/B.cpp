#include <iostream>
#include <vector>

std::vector<int> markers[1001];
std::vector<int> caps[1001];

int matches=0,supers=0;

int marker_color[1001];
int cap_color[1001];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    int color,diam;
    std::cin>>color>>diam;
    markers[diam].push_back(color);
  }
  for(int i=0;i<M;i++){
    int color,diam;
    std::cin>>color>>diam;
    caps[diam].push_back(color);
  }
  for(int diam=1;diam<=1000;diam++){
    matches+=std::min(markers[diam].size(),caps[diam].size());
    for(int color:markers[diam]){
      marker_color[color]++;
    }
    for(int color:caps[diam]){
      cap_color[color]++;
    }
    for(int color=1;color<=1000;color++){
      supers+=std::min(marker_color[color],cap_color[color]);
    }
    for(int color:markers[diam]){
      marker_color[color]--;
    }
    for(int color:caps[diam]){
      cap_color[color]--;
    }
  }
  std::cout<<matches<<" "<<supers<<std::endl;
  return 0;
}