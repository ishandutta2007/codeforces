#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int rs[100005];

struct Range{
  int l,r;
  Range():l(INF),r(-INF){
  }
  Range(int l,int r):l(l),r(r){
  }
  struct Range shift(int x){
    return Range(l+x,r+x);
  }
  int length(){
    return r-l;
  }
}st[20][200005];
int N;

struct Range combine(struct Range a,struct Range b){
  return Range(std::min(a.l,b.l),std::max(a.r,b.r));
}

void build(int k){
  for(int i=N-1;i>0;i--){
    st[k][i]=combine(st[k][i<<1],st[k][i<<1|1]);
  }
}

struct Range query(int k,struct Range q){
  int a=std::max(0,std::min(N,q.l));
  int b=std::max(0,std::min(N,q.r));
  struct Range ac;
  for(a+=N,b+=N;a<b;a>>=1,b>>=1){
    if(a&1) ac=combine(ac,st[k][a++]);
    if(b&1) ac=combine(ac,st[k][--b]);
  }
  return ac;
}

struct Range circular_query(int k,struct Range q){
  return combine(query(k,q),
		 combine(query(k,q.shift(-N)).shift(N),
			 query(k,q.shift(N)).shift(-N)));
}

int main(){
  scanf("%d",&N);
  if(N==1){
    printf("0\n");
    return 0;
  }
  for(int i=0;i<N;i++){
    int R;
    scanf("%d",&R);
    st[0][i+N].l=i-R;
    st[0][i+N].r=i+R+1;
  }
  build(0);
  for(int k=1;k<20;k++){
    for(int i=0;i<N;i++){
      st[k][i+N]=circular_query(k-1,st[k-1][i+N]);
      //printf("%d after 2^%d iterations: [%d,%d)\n",i,k,st[k][i+N].l,st[k][i+N].r);
    }
    build(k);
  }
  for(int i=0;i<N;i++){
    struct Range curr(i,i+1);
    int ans=0;
    for(int k=20-1;k>=0;k--){
      struct Range tmp=circular_query(k,curr);
      if(tmp.length()<N){
	curr=tmp;
	ans+=(1<<k);
      }
    }
    if(i) printf(" ");
    printf("%d",ans+1);
  }
  printf("\n");
  return 0;
}