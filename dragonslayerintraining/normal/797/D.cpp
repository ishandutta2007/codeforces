#include <iostream>
#include <set>

int vs[100000];
int left[100000];
int right[100000];

std::set<int> success;

void dfs(int node,int lower,int upper){
  if((vs[node]>=lower)&&(vs[node]<=upper)){
    success.insert(vs[node]);
  }
  if(left[node]>=0){
    dfs(left[node],lower,std::min(vs[node],upper));
  }
  if(right[node]>=0){
    dfs(right[node],std::max(vs[node],lower),upper);
  }
}

std::set<int> root;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    root.insert(i);
  }
  for(int i=0;i<N;i++){
    int V,L,R;
    std::cin>>V>>L>>R;
    L--,R--;
    root.erase(L);
    root.erase(R);
    vs[i]=V,left[i]=L,right[i]=R;
  }
  dfs(*root.begin(),0,1e9);
  int cnt=0;
  for(int i=0;i<N;i++){
    cnt+=success.count(vs[i]);
  }
  std::cout<<N-cnt<<std::endl;
  return 0;
}