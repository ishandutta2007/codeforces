#include <cstdio>
#include <algorithm>
#include <tuple>
#include <cstring>
#include <vector>
#include <map>
#include <cassert>
#include <stdint.h>

const int INF=1e9+7;

const int MAXLOGN=7;//smaller than ideal, else get MLE
const int ALPHA=27;

const int MAXN=100005;

char str[MAXN];
int N;

int nextc[MAXN][ALPHA];//0:N
int prevc[MAXN][ALPHA];//1:N+1
int nextord[MAXN][ALPHA];//0:N
int prevord[MAXN][ALPHA];//1:N+1
int last[ALPHA];

struct Jump{
  int pos;
  int8_t set_size;
  int cost;
}ljump[MAXLOGN][MAXN][ALPHA],rjump[MAXLOGN][MAXN][ALPHA];

//[l,r]
int mask_distinct(int l,int r){
  int distinct=0;
  for(int c=0;c<ALPHA;c++){
    if(nextc[l-1][c]<=r){
      distinct|=(1<<c);
    }
  }
  return distinct;
}

std::pair<int,int> lstep(int l,int lset){
  if(l==1) return {1,0};
  int far=l;
  for(int c=0;c<ALPHA;c++){
    if(lset&(1<<c)){
      far=std::min(far,prevc[l][c]);
    }
  }
  if(far==0){
    far=1;
  }
  return {far,mask_distinct(far,l-1)};
}

std::pair<int,int> rstep(int r,int rset){
  if(r==N) return {N,0};
  int far=r;
  for(int c=0;c<ALPHA;c++){
    if(rset&(1<<c)){
      far=std::max(far,nextc[r][c]);
    }
  }
  if(far==N+1){
    far=N;
  }
  return {far,mask_distinct(r+1,far)};
}

int lstep_decode_arr[MAXN][ALPHA];
int rstep_decode_arr[MAXN][ALPHA];

//first $cnt distinct characters with index >=i
int lstep_decode(int i,int cnt){
  assert(i>=1&&i<=N);
  int mask=0;
  for(int oi=0;oi<cnt;oi++){
    int c=nextord[i-1][oi];
    mask|=(1<<c);
  }
  return mask;
}

//first $cnt distinct characters with index <=i
int rstep_decode(int i,int cnt){
  assert(i>=1&&i<=N);
  int mask=0;
  for(int oi=0;oi<cnt;oi++){
    int c=prevord[i+1][oi];
    mask|=(1<<c);
  }
  return mask;
}

int main(){
  scanf("%s",str+1);
  N=strlen(str+1);
  std::fill(last,last+ALPHA,0);
  for(int i=1;i<=N;i++){
    std::copy(last,last+ALPHA,prevc[i]);
    last[str[i]-'a']=i;
  }
  std::copy(last,last+ALPHA,prevc[N+1]);
  std::fill(last,last+ALPHA,N+1);
  for(int i=N;i>=1;i--){
    std::copy(last,last+ALPHA,nextc[i]);
    last[str[i]-'a']=i;
  }
  std::copy(last,last+ALPHA,nextc[0]);
  for(int i=0;i<=N;i++){
    std::vector<std::pair<int,int> > ord;
    //left to right order
    for(int c=0;c<ALPHA;c++){
      ord.push_back({nextc[i][c],c});
    }
    std::sort(ord.begin(),ord.end());
    for(int oi=0;oi<ALPHA;oi++){
      nextord[i][oi]=ord[oi].second;
    }
  }
  for(int i=1;i<=N+1;i++){
    std::vector<std::pair<int,int> > ord;
    //right to left order
    for(int c=0;c<ALPHA;c++){
      ord.push_back({-prevc[i][c],c});
    }
    std::sort(ord.begin(),ord.end());
    for(int oi=0;oi<ALPHA;oi++){
      prevord[i][oi]=ord[oi].second;
    }
  }
  for(int i=1;i<=N;i++){
    for(int cnt=0;cnt<ALPHA;cnt++){
      lstep_decode_arr[i][cnt]=lstep_decode(i,cnt);
      rstep_decode_arr[i][cnt]=rstep_decode(i,cnt);
    }
  }
  //Shadow
  auto lstep_decode=[](int i,int cnt){
    return lstep_decode_arr[i][cnt];
  };
  auto rstep_decode=[](int i,int cnt){
    return rstep_decode_arr[i][cnt];
  };
  //Compute ljump
  for(int i=1;i<=N;i++){
    for(int cnt=0;cnt<ALPHA;cnt++){
      int pos,set;
      std::tie(pos,set)=lstep(i,lstep_decode(i,cnt));
      ljump[0][i][cnt]={pos,__builtin_popcount(set),i-pos};
      assert(set==lstep_decode(pos,__builtin_popcount(set)));
    }
  }
  for(int k=1;k<MAXLOGN;k++){
    for(int i=1;i<=N;i++){
      for(int cnt=0;cnt<ALPHA;cnt++){
	//(i,cnt,cost)
	Jump& curr=ljump[k][i][cnt];
	curr={i,cnt,0};
	for(int rep=0;rep<4;rep++){
	  Jump mid=ljump[k-1][curr.pos][curr.set_size];
	  assert(mid.pos>=1&&mid.pos<=N);
	  curr.cost+=mid.cost;
	  curr.cost+=((curr.pos-mid.pos)<<(2*(k-1)))*rep;
	  
	  curr.pos=mid.pos;
	  curr.set_size=mid.set_size;
	}
      }
    }
  }
  //Compute rjump
  for(int i=1;i<=N;i++){
    for(int cnt=0;cnt<ALPHA;cnt++){
      int pos,set;
      std::tie(pos,set)=rstep(i,rstep_decode(i,cnt));
      rjump[0][i][cnt]={pos,__builtin_popcount(set),pos-i};
      assert(set==rstep_decode(pos,__builtin_popcount(set)));
    }
  }
  for(int k=1;k<MAXLOGN;k++){
    for(int i=1;i<=N;i++){
      for(int cnt=0;cnt<ALPHA;cnt++){
	//(i,cnt,cost)
	Jump& curr=rjump[k][i][cnt];
	curr={i,cnt,0};
	for(int rep=0;rep<4;rep++){
	  Jump mid=rjump[k-1][curr.pos][curr.set_size];
	  assert(mid.pos>=1&&mid.pos<=N);
	  curr.cost+=mid.cost;
	  curr.cost+=((mid.pos-curr.pos)<<(2*(k-1)))*rep;
	  
	  curr.pos=mid.pos;
	  curr.set_size=mid.set_size;
	}
      }
    }
  }
  //Compute total_dist
  long long total_dist=0;
  for(int i=1;i<=N;i++){
    //dist to i
    int l=i,r=i;
    int lset=(1<<(str[i]-'a')),rset=(1<<(str[i]-'a'));
    int d=0;
    int all=(1<<(str[i]-'a'));
    while(l>1||r<N){
      if(lset==lstep_decode(l,__builtin_popcount(lset))&&
	 rset==rstep_decode(r,__builtin_popcount(rset))){
	int l2,r2;
	int lset2,rset2;
	//Fast forward
	for(int k=MAXLOGN-1;k>=0;k--){
	  while(true){
	    const auto& lj=ljump[k][l][__builtin_popcount(lset)];
	    const auto& rj=rjump[k][r][__builtin_popcount(rset)];
	    if(mask_distinct(lj.pos,rj.pos)&~all){
	      break;
	    }
	    l2=lj.pos,lset2=lstep_decode(l2,lj.set_size);
	    r2=rj.pos,rset2=rstep_decode(r2,rj.set_size);
	    total_dist+=lj.cost+d*(l-l2);
	    total_dist+=rj.cost+d*(r2-r);

	    if(l==l2&&r==r2) break;
	  
	    l=l2,r=r2,lset=lset2,rset=rset2;
	    d+=(1<<(2*k));
	  }
	}
      }
      {
	int l2,r2;
	int lset2,rset2;
	std::tie(l2,lset2)=lstep(l,lset);
	std::tie(r2,rset2)=rstep(r,rset);
	d++;
	total_dist+=d*(l-l2);
	total_dist+=d*(r2-r);
	l=l2,r=r2,lset=lset2,rset=rset2;
	int extra=mask_distinct(l,r)&~all;
	lset|=extra;
	rset|=extra;
	all|=extra;
      }
    }
  }
  printf("%lld\n",total_dist);
}