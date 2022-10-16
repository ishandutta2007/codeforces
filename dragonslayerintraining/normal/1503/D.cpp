#include <cstdio>
#include <numeric>
#include <vector>
#include <cassert>

int uf[400005];
int card[400005];
int where[400005];
int dom[400005];
int size[400005];

int find(int a){
  while(a!=uf[a]){
    a=uf[a]=uf[uf[a]];
  }
  return a;
}

void merge(int a,int b){
  a=find(a),b=find(b);
  if(a==b) return;
  uf[a]=b;
  size[b]+=size[a];
}

void merge2(int a,int b){
  merge(a,b);
  merge(a^1,b^1);
}

int main(){
  int N;
  scanf("%d",&N);
  std::iota(uf,uf+N*2,0);
  for(int i=0;i<N;i++){
    size[i*2+1]=1;
  }
  for(int i=0;i<N*2;i++){
    scanf("%d",&card[i]);
    card[i]--;
    where[card[i]]=i;
  }
  std::vector<int> stk;
  for(int u=0;u<N*2;u++){
    int i=where[u];
    int v=card[i^1];
    if(stk.size()&&v>stk.back()){
      int tmp=stk.back();
      while(stk.size()&&v>stk.back()){
	if(dom[stk.back()]){
	  printf("-1\n");
	  return 0;
	}
	merge2(where[v],where[stk.back()]^1);
	stk.pop_back();
      }
      stk.push_back(v);
      stk.push_back(tmp);
      dom[v]=true;
    }else{
      stk.push_back(v);
    }
  }
  for(int i=0;i<N*2;i+=2){
    if(find(i)==find(i^1)){
      printf("-1\n");
      return 0;
    }
  }
  int cost=0;
  for(int i=0;i<N*2;i+=2){
    if(find(i)==i){
      assert(find(i^1)==(i^1));
      cost+=std::min(size[find(i)],size[find(i^1)]);
    }
  }
  printf("%d\n",cost);
}