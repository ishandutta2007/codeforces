#include <iostream>
#include <vector>
#include <map>
#include <set>

std::map<int,std::vector<int> > adj;
std::set<int> visited;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    adj[A].push_back(B);
    adj[B].push_back(A);
  }
  int cur;
  for(std::map<int,std::vector<int> >::iterator
	it=adj.begin();it!=adj.end();it++){
    if(it->second.size()==1){
      cur=it->first;
      break;
    }
  }
  do{
    std::cout<<cur<<" ";
    visited.insert(cur);
    if(visited.count(adj[cur][0])){
      cur=adj[cur][1];
    }else{
      cur=adj[cur][0];
    }
  }while(adj[cur].size()!=1);
  std::cout<<cur<<std::endl;
  
  return 0;
}