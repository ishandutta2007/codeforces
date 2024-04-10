#include <cstdio>
#include <algorithm>
#include <array>
#include <cassert>
#include <vector>

std::vector<std::pair<int,int> > cheap[1<<10];//(cost,id)
int cnt[1<<10];
int satisfy[1<<10];

std::vector<std::array<int,3> > pizzas;//(mask,cost,id)

int read_mask(){
  int F;
  scanf("%d",&F);
  int mask=0;
  for(int i=0;i<F;i++){
    int B;
    scanf("%d",&B);
    mask|=(1<<(B-1));
  }
  return mask;
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    int mask=read_mask();
    cnt[mask]++;
  }
  for(int i=0;i<M;i++){
    int price;
    scanf("%d",&price);
    int mask=read_mask();
    cheap[mask].push_back({price,i+1});
  }
  for(int mask=0;mask<(1<<10);mask++){
    std::sort(cheap[mask].begin(),cheap[mask].end());
    for(int i=0;i<std::min<int>(2,cheap[mask].size());i++){
      pizzas.push_back({mask,cheap[mask][i].first,cheap[mask][i].second});
    }
  }
    
  for(int m1=0;m1<(1<<10);m1++){
    for(int m2=0;m2<(1<<10);m2++){
      if((m1&m2)!=m2) continue;
      satisfy[m1]+=cnt[m2];
    }
  }
  std::array<int,4> ans({-1,-1,-1,-1});//(satisfy,-cost,id1,id2)
  for(auto p1:pizzas){
    int m1=p1[0];
    int c1=p1[1];
    for(auto p2:pizzas){
      if(p1[2]==p2[2]) continue;
      int m2=p2[0];
      int c2=p2[1];
      ans=std::max(ans,{satisfy[m1|m2],
	    -(c1+c2),p1[2],p2[2]}); 
    }
  }
  //printf("%d %d\n",ans[0],ans[1]);
  printf("%d %d\n",ans[2],ans[3]);
  return 0;
}