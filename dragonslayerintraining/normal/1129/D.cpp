#include <cstdio>
#include <algorithm>
#include <cassert>

const int BLOCK=250;
const int NUMBLOCKS=100005/BLOCK+1;

const int MOD=998244353;
const int INF=1e9+7;

void addmod(int& x,int y){
  x=(x+y)%MOD;
}

struct Block{
  int extra;
  struct Point{
    int i,h,v;
    Point():i(0),h(0),v(0){
    }
    bool operator<(struct Point p)const{
      return h<p.h;
    }
  }data[BLOCK+1];
  int prefix[BLOCK+1];
  void calc_prefix(){
    for(int k=1;k<=BLOCK;k++){
      prefix[k]=(prefix[k-1]+data[k].v)%MOD;
    }
  }
  void clear(){
    extra=0;
    std::fill(data,data+BLOCK+1,Point());
    for(int k=1;k<=BLOCK;k++){
      data[k].i=k-1;
    }
    std::fill(prefix,prefix+BLOCK+1,0);
  }
  Block():extra(0){
    clear();
  }
  void elevate(int l,int r,int x){
    if(l>=BLOCK||r<=0) return;
    if(l<=0&&r>=BLOCK){
      extra+=x;
      return;
    }
    auto f=[l,r](struct Point p){return p.i>=l&&p.i<r;};
    auto it=std::stable_partition(data+1,data+BLOCK+1,f);
    for(int k=1;k<=BLOCK;k++){
      if(f(data[k])){
	data[k].h+=x;
      }
    }
    std::inplace_merge(data+1,it,data+BLOCK+1);
    calc_prefix();
  }
  //returns sum of v for all points whose h<x
  int query(int l,int r,int x){
    x-=extra;
    if(l>=BLOCK||r<=0) return 0;
    
    if(l<=0&&r>=BLOCK){
      int low=0,high=BLOCK+1;
      while(high-low>1){
	int mid=(low+high)>>1;
	if(x<=data[mid].h){
	  high=mid;
	}else{
	  low=mid;
	}
      }
      //low => high is the switch from <x to >=x
      assert(low==0||data[low].h<x);
      assert(high==BLOCK+1||data[high].h>=x);
      return prefix[low];
    }
    
    int ans=0;
    for(int k=1;k<=BLOCK;k++){
      if(data[k].h>=x) break;
      if(data[k].i>=l&&data[k].i<r&&data[k].h<x){
	addmod(ans,data[k].v);
      }
    }
    return ans;
  }
  void set(int i,int v){
    if(i<0||i>=BLOCK) return;
    for(int k=1;k<=BLOCK;k++){
      if(data[k].i==i){
	data[k].v=v;
	break;
      }
    }
    calc_prefix();
  }
}blocks[NUMBLOCKS];

int query(int l,int r,int x){
  int ans=0;
  for(int b=0;b<NUMBLOCKS;b++){
    addmod(ans,blocks[b].query(l-b*BLOCK,r-b*BLOCK,x));
  }
  return ans;
}

void elevate(int l,int r,int x){
  for(int b=0;b<NUMBLOCKS;b++){
    blocks[b].elevate(l-b*BLOCK,r-b*BLOCK,x);
  }
}

void set(int i,int x){
  for(int b=0;b<NUMBLOCKS;b++){
    blocks[b].set(i-b*BLOCK,x);
  }
}

int N,K;
int as[100005];
int dp[100005];
int last[100005];
int prev[100005];


int main(){
  scanf("%d %d",&N,&K);
  std::fill(last,last+100005,0);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
    prev[i]=last[as[i]];
    last[as[i]]=i;
  }
  set(0,1);
  for(int i=1;i<=N;i++){
    elevate(prev[i],i,1);
    if(prev[i]){
      elevate(prev[prev[i]],prev[i],-1);
    }
    /*
    printf("i=%d\n",i);
    for(int k=0;k<=N;k++){
      printf("(%d,%d) ",hs[k],vs[k]);
    }
    printf("\n");
    */
    dp[i]=query(0,i,K+1);
    //printf("dp[%d]=%d\n",i,dp[i]);
    set(i,dp[i]);
  }
  printf("%d\n",dp[N]);
}