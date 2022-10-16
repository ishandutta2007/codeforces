#include <cstdio>
#include <array>
#include <cassert>
#include <algorithm>

//010 -> 0
//0011 -> 01 plus one to cost
//(same for 0 and 1 swapped)
//this reduces all strings to 0?1*0?|1?0*1?
//we can just build a segment for the reduced strings

struct State{
  std::array<int,3> zag;
  int len;
  int cost;
  State():zag{0,0,0},len(0),cost(0){
  }
  State& operator+=(const State& rhs){
    cost+=rhs.cost;
    for(int i=0;i<rhs.len;i++){
      int x=rhs.zag[i];
      if(len==0){
	zag[len++]=x;
	continue;
      }
      if(((zag[len-1])>0)==(x>0)){
	x+=zag[--len];
      }
      if(len==0){
	zag[len++]=x;
	continue;
      }
      //zag[len-1] has opposite sign as x
      if(x>0){
	int use=std::min(x,-zag[len-1])-1;
	cost+=use;
	x-=use;
	zag[len-1]+=use;
      }else{
	int use=std::min(-x,zag[len-1])-1;
	cost+=use;
	x+=use;
	zag[len-1]-=use;
      }
      if((zag[len-1]==-1||zag[len-1]==1)&&len>=2){
	zag[len-2]+=zag[len-1]+x;
	len--;
	continue;
      }
      zag[len++]=x;
    }
    assert(len<=3);
    return *this;
  }
  friend State operator+(State lhs,State rhs){
    return lhs+=rhs;
  }
}st[400005];

int N;

State query(int l,int r){
  State lsum,rsum;
  for(l+=N,r+=N;l<r;l>>=1,r>>=1){
    if(l&1) lsum=lsum+st[l++];
    if(r&1) rsum=st[--r]+rsum;
  }
  return lsum+rsum;
}

char str[200005];

int main(){
  int Q;
  scanf("%d %d",&N,&Q);
  scanf("%s",str);
  for(int i=0;i<N;i++){
    st[i+N].zag[0]=((str[i]=='1')?1:-1);
    st[i+N].len=1;
  }
  for(int i=N-1;i>0;i--){
    st[i]=st[i<<1]+st[i<<1|1];
  }
  while(Q--){
    int L,R;
    scanf("%d %d",&L,&R);
    State state=query(L-1,R);
    int add=0;
    for(int i=0;i<state.len;i++){
      add=std::max(add,std::abs(state.zag[i]));
    }
    printf("%d\n",state.cost+add);
  }
}