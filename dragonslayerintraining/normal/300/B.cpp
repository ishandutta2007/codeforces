#include <cstdio>
#include <algorithm>
#include <vector>

int N,M;

int uf[50];

std::vector<int> groups[50];

std::vector<std::vector<int> > bysize[50];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void unify(int a,int b){
  uf[find(a)]=find(b);
}

int main(){
  scanf("%d %d",&N,&M);
  std::iota(uf,uf+N,0);
  for(int i=0;i<M;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    unify(A,B);
  }
  for(int i=0;i<N;i++){
    groups[find(i)].push_back(i);
  }
  for(int i=0;i<N;i++){
    bysize[groups[i].size()].push_back(groups[i]);
  }
  if((bysize[0].size()+bysize[1].size()+bysize[2].size()+bysize[3].size()<N)||(bysize[2].size()>bysize[1].size())){
    printf("-1\n");
    return 0;
  }
  while(bysize[2].size()>0){
    std::vector<int> v=(bysize[2].back());
    bysize[2].pop_back();
    v.push_back(bysize[1].back()[0]);
    bysize[1].pop_back();
    bysize[3].push_back(v);
  }
  while(bysize[1].size()>0){
    std::vector<int> v;
    for(int i=0;i<3;i++){
      v.push_back(bysize[1].back()[0]);
      bysize[1].pop_back();
    }
    bysize[3].push_back(v);
  }
  for(std::vector<int> triple:bysize[3]){
    printf("%d %d %d\n",triple[0]+1,triple[1]+1,triple[2]+1);
  }
  return 0;
}