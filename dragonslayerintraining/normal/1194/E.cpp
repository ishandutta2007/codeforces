#include <cstdio>
#include <vector>
#include <set>
#include <array>
#include <algorithm>

struct Seg{
  int x0,y0,x1,y1;
  bool operator<(Seg seg)const{
    return x0<seg.x0;
  }
};

std::vector<Seg> hs,vs;

int bit[20000];

void update(int i,int v){
  for(i+=10000;i<20000;i+=(i&-i)){
    bit[i]+=v;
  }
}

int query(int i){
  int ac=0;
  for(i+=10000;i>0;i-=(i&-i)){
    ac+=bit[i];
  }
  return ac;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    Seg seg;
    scanf("%d %d %d %d",&seg.x0,&seg.y0,&seg.x1,&seg.y1);
    if(seg.x0>seg.x1) std::swap(seg.x0,seg.x1);
    if(seg.y0>seg.y1) std::swap(seg.y0,seg.y1);
    if(seg.x0==seg.x1){
      vs.push_back(seg);
    }else{
      hs.push_back(seg);
    }
  }
  std::sort(vs.begin(),vs.end());
  long long ans=0;
  for(int i=0;i<vs.size();i++){
    //printf("vs[%d]=(%d,[%d,%d])\n",i,vs[i].x0,vs[i].y0,vs[i].y1);
    std::multiset<std::pair<int,int> > rem;
    for(int j=0;j<hs.size();j++){
      if(vs[i].x0>=hs[j].x0&&
	 vs[i].y0<=hs[j].y0&&
	 vs[i].x1<=hs[j].x1&&
	 vs[i].y1>=hs[j].y1){
	//printf("vs[%d]: add (%d,%d)\n",i,hs[j].x1,hs[j].y1-5005);
	update(hs[j].y1,1);
	rem.insert({hs[j].x1,hs[j].y1});
      }
    }
    for(int j=i+1;j<vs.size();j++){
      while(rem.size()&&rem.begin()->first<vs[j].x1){
	//printf("pop (%d,%d)\n",rem.begin()->first,rem.begin()->second);
	update(rem.begin()->second,-1);
	rem.erase(rem.begin());
      }
      int enclosed=query(vs[j].y1)-query(vs[j].y0-1);
      ans+=1LL*enclosed*(enclosed-1)/2;
      //printf("vs[%d] and vs[%d]: found %d horizontal segments\n",i,j,enclosed);
    }
    while(rem.size()){
      //printf("pop (%d,%d)\n",rem.begin()->first,rem.begin()->second);
      update(rem.begin()->second,-1);
      rem.erase(rem.begin());
    }
  }
  printf("%lld\n",ans);
}