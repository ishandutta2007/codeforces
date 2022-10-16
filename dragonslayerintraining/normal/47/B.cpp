#include <iostream>
#include <vector>
#include <set>

int visited[3];
int visited_cnt=0;
bool success=true;

std::vector<int> edges[3];

std::vector<int> sorted;

void dfs(int node){
  if(visited[node]){
    return;
  }
  visited[node]=++visited_cnt;
  for(unsigned int i=0;i<edges[node].size();i++){
    if((visited[edges[node][i]]>0)&&
       (visited[edges[node][i]]<visited[node])){
      success=false;
      return;
    }
    dfs(edges[node][i]);
  }
  sorted.push_back(node);
  visited[node]=1e9;
}

std::set<int> used;

int main(){
  for(int i=0;i<3;i++){
    std::string cmp;
    std::cin>>cmp;
    if(cmp[1]=='>'){
      edges[cmp[0]-'A'].push_back(cmp[2]-'A');
    }else{
      edges[cmp[2]-'A'].push_back(cmp[0]-'A');
    }
    used.insert(cmp[0]-'A');
    used.insert(cmp[2]-'A');
  }
  for(std::set<int>::iterator it=used.begin();it!=used.end();it++){
    dfs(*it);
  }
  if(success){
    for(unsigned int i=0;i<sorted.size();i++){
      std::cout<<char(sorted[i]+'A');
    }
    std::cout<<std::endl;
  }else{
    std::cout<<"Impossible"<<std::endl;
  }
  return 0;
}