#include <iostream>
#include <map>
#include <algorithm>

std::map<std::string,int> dist;

int main(){
  int N;
  scanf("%d",&N);
  dist["polycarp"]=1;
  int pop=1;
  for(int i=0;i<N;i++){
    std::string a,x,b;
    std::cin>>a>>x>>b;
    std::transform(a.begin(),a.end(),a.begin(),tolower);
    std::transform(b.begin(),b.end(),b.begin(),tolower);
    dist[a]=dist[b]+1;
    pop=std::max(pop,dist[a]);
  }
  printf("%d\n",pop);
  return 0;
}