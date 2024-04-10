#include <iostream>
#include <vector>

int colors[200005];

int uf[200005];
int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}
void unite(int a,int b){
  uf[find(a)]=find(b);
}

std::vector<int> set[200005];
int colorcnt[200005];

int main(){
  int N,M,K;
  std::cin>>N>>M>>K;
  for(int i=0;i<N;i++){
    uf[i]=i;
  }
  for(int i=0;i<N;i++){
    std::cin>>colors[i];
    colors[i]--;
  }
  for(int i=0;i<M;i++){
    int L,R;
    std::cin>>L>>R;
    L--,R--;
    unite(L,R);
  }
  for(int i=0;i<N;i++){
    set[find(i)].push_back(i);
  }
  int repaint=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<set[i].size();j++){
      colorcnt[colors[set[i][j]]]++;
    }
    int max=0;
    for(int j=0;j<set[i].size();j++){
      max=std::max(max,colorcnt[colors[set[i][j]]]);
    }
    for(int j=0;j<set[i].size();j++){
      colorcnt[colors[set[i][j]]]--;
    }
    repaint+=set[i].size()-max;
  }
  std::cout<<repaint<<std::endl;
  return 0;
}