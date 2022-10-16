#include <cstdio>
#include <vector>
#include <algorithm>

int N;
int as[300005];
int bs[300005];

std::vector<std::pair<int,int> > inc,dec;

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&as[i],&bs[i]);
    if(as[i]<bs[i]){
      inc.push_back({as[i],i});
    }else{
      dec.push_back({as[i],i});
    }
  }
  std::vector<int> ans;
  if(inc.size()>dec.size()){
    //take inc
    std::sort(inc.begin(),inc.end());
    std::reverse(inc.begin(),inc.end());
    for(auto it:inc){
      ans.push_back(it.second+1);
    }
  }else{
    //take dec
    std::sort(dec.begin(),dec.end());
    for(auto it:dec){
      ans.push_back(it.second+1);
    }
  }
  printf("%d\n",(int)ans.size());
  for(int i=0;i<ans.size();i++){
    if(i) printf(" ");
    printf("%d",ans[i]);
  }
  printf("\n");
  return 0;
}