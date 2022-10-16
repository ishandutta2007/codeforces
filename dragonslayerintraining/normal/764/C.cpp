#include <iostream>
#include <vector>

//0 is wildcard, -1 is contradiction
int mergecolors(int c1,int c2){
  if((c1==-1)||(c2==-1)){
    return -1;
  }
  if(c1==0){
    return c2;
  }
  if(c2==0){
    return c1;
  }
  if(c1!=c2){
    return -1;
  }
  return c1;
}

int N;
std::vector<int> edges[100000];
int colors[100000];
int subtree_color[100000];
int invalid[100000];

void dfscolor(int node,int parent){
  subtree_color[node]=colors[node];
  for(int i=0;i<edges[node].size();i++){
    int child=edges[node][i];
    if(child!=parent){
      dfscolor(child,node);
      subtree_color[node]=mergecolors(subtree_color[node],subtree_color[child]);
      if(subtree_color[child]==-1){
	if(invalid[node]==0){
	  invalid[node]=child;
	}else{
	  invalid[node]=-1;
	}
      }
    }
  }
  //std::cout<<node+1<<"\t"<<colors[node]<<"\t"<<subtree_color[node]<<"\t"<<invalid[node]<<std::endl;
}

int dfsfind(int node,int parent,int upper_color){
  if(invalid[node]==0){
    return node;
  }else if(invalid[node]==-1){
    return -1;
  }else{
    upper_color=mergecolors(upper_color,colors[node]);
    for(int i=0;i<edges[node].size();i++){
      int child=edges[node][i];
      if((child!=parent)&&(child!=invalid[node])){
	upper_color=mergecolors(upper_color,subtree_color[child]);
      }
    }
    if(upper_color!=-1){
      return dfsfind(invalid[node],node,upper_color);
    }else{
      return -1;
    }
  }
  
}

int main(){
  std::cin>>N;
  for(int i=1;i<N;i++){
    int U,V;
    std::cin>>U>>V;
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  for(int i=0;i<N;i++){
    std::cin>>colors[i];
  }
  dfscolor(0,0);
  int n=dfsfind(0,0,0);
  if(n==-1){
    std::cout<<"NO"<<std::endl;
  }else{
    std::cout<<"YES"<<std::endl;
    std::cout<<n+1<<std::endl;
  }
  return 0;
}