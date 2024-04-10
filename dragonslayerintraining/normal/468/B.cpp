#include <iostream>
#include <map>

int label[100000];
int assign[100000];

int N,A,B;
int ps[100000];

std::map<int,int> index;

void dfs(int node,int l){
  if(label[node]!=-1){
    return;
  }
  label[node]=l;
  if(index.count(A-ps[node])){
    assign[node]|=1;
    dfs(index[A-ps[node]],l);
  }
  if(index.count(B-ps[node])){
    assign[node]|=2;
    dfs(index[B-ps[node]],l);
  }
}

int final[100000];

int main(){
  std::cin>>N>>A>>B;
  for(int i=0;i<N;i++){
    std::cin>>ps[i];
    index[ps[i]]=i;
  }
  std::fill(label,label+N,-1);
  for(int i=0;i<N;i++){
    dfs(i,i);
  }
  std::fill(final,final+N,3);
  for(int i=0;i<N;i++){
    final[label[i]]&=assign[i];
  }
  for(int i=0;i<N;i++){
    if(final[i]==0){
      std::cout<<"NO"<<std::endl;
      return 0;
    }
  }
  std::cout<<"YES"<<std::endl;
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    if(final[label[i]]&1){
      std::cout<<0;
    }else{
      std::cout<<1;
    }
  }
  std::cout<<std::endl;
  
  return 0;
}