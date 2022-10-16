#include <cstdio>
#include <set>
#include <vector>
#include <cassert>

int as[200005];
int out[200005];

std::vector<std::pair<int,int> > edges;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    scanf("%d",&as[i]);
    as[i]--;
    out[as[i]]++;
  }
  std::set<int> leaf;
  for(int i=0;i<N;i++){
    if(out[i]==0){
      leaf.insert(i);
    }
  }
  for(int i=N-2;i>=0;i--){
    assert(leaf.size());
    int x=*leaf.begin();
    leaf.erase(x);
    edges.push_back({x,as[i]});
    if(--out[as[i]]==0){
      leaf.insert(as[i]);
    }
  }
  assert(leaf.size()==1);
  printf("%d\n",*leaf.begin()+1);
  for(auto e:edges){
    printf("%d %d\n",e.first+1,e.second+1);
  }
}