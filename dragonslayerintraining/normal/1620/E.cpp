#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

int ts[500005];
int xs[500005];
int ys[500005];

int main(){
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    scanf("%d",&ts[i]);
    if(ts[i]==1){
      scanf("%d",&xs[i]);
    }else{
      scanf("%d %d",&xs[i],&ys[i]);
    }
  }
  std::vector<int> vs;
  std::map<int,int> replace;
  for(int i=Q-1;i>=0;i--){
    if(ts[i]==2){
      replace[xs[i]]=replace.count(ys[i])?replace[ys[i]]:ys[i];
    }else{
      vs.push_back(replace.count(xs[i])?replace[xs[i]]:xs[i]);
    }
  }
  std::reverse(vs.begin(),vs.end());
  for(int i=0;i<vs.size();i++){
    if(i) printf(" ");
    printf("%d",vs[i]);
  }
  printf("\n");
}