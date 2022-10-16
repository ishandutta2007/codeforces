#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

struct Point{
  int x,y;
  void read(){
    scanf("%d %d",&x,&y);
  }
}ps[200005];


int bit[200005];
bool used[200005];

void update(int i,int v){
  for(;i<=200000;i+=(i&-i)){
    bit[i]+=v;
  }
}

int query(int i){
  int ac=0;
  for(;i>0;i-=(i&-i)){
    ac+=bit[i];
  }
  return ac;
}

int main(){
  int N;
  scanf("%d",&N);
  std::map<int,int> cps;
  for(int i=0;i<N;i++){
    ps[i].read();
    cps[ps[i].x];
  }
  {
    int last=1;
    for(auto& it:cps){
      it.second=last++;
    }
  }
  std::map<int,std::vector<int> > layers;
  for(int i=0;i<N;i++){
    layers[-ps[i].y].push_back(cps[ps[i].x]);
  }
  long long ans=0;
  for(auto l:layers){
    std::vector<int> xs=l.second;
    std::sort(xs.begin(),xs.end());
    for(int x:xs){
      if(!used[x]){
	update(x,1);
	used[x]=1;
      }
    }
    xs.insert(xs.begin(),0);
    xs.insert(xs.end(),200001);
    int above=query(200000);
    ans+=above*(above+1LL)/2;
    for(int i=1;i<xs.size();i++){
      int region=query(xs[i]-1)-query(xs[i-1]);
      ans-=region*(region+1LL)/2;
    }
  }
  printf("%I64d\n",ans);
}