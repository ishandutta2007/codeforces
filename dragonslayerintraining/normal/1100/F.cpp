#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

int N;

struct Node{
  int basis[20];
  int left[20];
  Node(){
    std::fill(basis,basis+20,0);
    std::fill(left,left+20,0);
  }
  bool insert(int x,int l){
    for(int k=20-1;k>=0;k--){
      if((x>>k)&1){
	x^=basis[k];
	if(basis[k]==0){
	  basis[k]=x;
	  left[k]=l;
	  return true;
	}
      }
    }
    return false;
  }
  int max(int l){
    int ans=0;
    for(int k=20-1;k>=0;k--){
      if(left[k]<l) continue;
      if((ans^basis[k])>ans){
	ans=(ans^basis[k]);
      }
    }
    return ans;
  }
}nodes[500001];

int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    int C;
    scanf("%d",&C);
    nodes[i].insert(C,i);
    std::vector<std::pair<int,int> > relevant;
    for(int k=0;k<20;k++){
      if(nodes[i-1].basis[k]){
	relevant.push_back({nodes[i-1].left[k],nodes[i-1].basis[k]});
      }
    }
    std::sort(relevant.begin(),relevant.end());
    std::reverse(relevant.begin(),relevant.end());
    for(auto it:relevant){
      nodes[i].insert(it.second,it.first);
    }
  }
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    printf("%d\n",nodes[R].max(L));
  }
  return 0;
}