#include <iostream>
#include <vector>

std::vector<int> domino[7][7];
int degree[7];

std::vector<int> line;

void dfs(int node){
  for(int i=0;i<7;i++){
    while(domino[node][i].size()>0){
      int next=domino[node][i].back();
      domino[node][i].pop_back();
      dfs(i);
      line.push_back(-next);
    }
    while(domino[i][node].size()>0){
      int next=domino[i][node].back();
      domino[i][node].pop_back();
      dfs(i);
      line.push_back(next);
    }
  }
}

void search(){
  int odd=0;
  for(int i=0;i<7;i++){
    if(degree[i]%2==1){
      odd++;
    }
  }
  if(odd>2){
    return;
  }
  for(int i=0;i<7;i++){
    if(degree[i]%2==1){
      dfs(i);
      return;
    }
  }
  for(int i=0;i<7;i++){
    if(degree[i]>0){
      dfs(i);
      return;
    }
  }
}

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int L,R;
    std::cin>>L>>R;
    domino[L][R].push_back(i+1);
    degree[L]++;
    degree[R]++;
  }
  search();
  if(line.size()==N){
    for(int dom:line){
      if(dom<0){
	std::cout<<-dom<<" -"<<std::endl;
      }else{
	std::cout<<dom<<" +"<<std::endl;
      }
    }
  }else{
    std::cout<<"No solution"<<std::endl;
  }
  return 0;
}