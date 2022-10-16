#include <cstdio>
#include <vector>
#include <algorithm>

const int BLK=500;

const int MAXN=100005;

int as[MAXN];
int N;

std::vector<int> st[MAXN*4];
std::vector<int> st2[MAXN*4];

void build(int w,int L,int R,int a,int b){
  if(a>=R||b<=L) return;
  st[w].clear();
  if(R-L==1){
    st[w].push_back(as[L]);
  }else{
    int M=(L+R)/2;
    build(w*2+1,L,M,a,b);
    build(w*2+2,M,R,a,b);
    if(R-L<=BLK){
      int shift=0;
      int i=0,j=0;
      const auto& lchd=st[w*2+1];
      const auto& rchd=st[w*2+2];
      while(i<lchd.size()||j<rchd.size()){
	if(j==rchd.size()||(i<lchd.size()&&lchd[i]+shift<rchd[j])){
	  st[w].push_back(lchd[i++]+shift);
	}else{
	  st[w].push_back(rchd[j++]);
	  shift++;
	}
      }
    }
  }
  st2[w].clear();
  for(int i=0;i<st[w].size();i++){
    st2[w].push_back(st[w][i]-i);
  }
}

int query(int w,int L,int R,int a,int b,int v){
  int v0=v;
  if(a>=R||b<=L){
    //do nothing
  }else if(a<=L&&b>=R&&R-L<=BLK){
    v+=(std::upper_bound(st2[w].begin(),st2[w].end(),v)-st2[w].begin());
  }else{
    int M=(L+R)/2;
    v=query(w*2+1,L,M,a,b,v);
    v=query(w*2+2,M,R,a,b,v);
  }
  return v;
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int B;
    scanf("%d",&B);
    as[i]=i-B;
  }
  build(0,0,N,0,N);
  int Q;
  scanf("%d",&Q);
  while(Q--){
    int T;
    scanf("%d",&T);
    if(T==1){
      int I,X;
      scanf("%d %d",&I,&X);
      I--;
      as[I]=I-X;
      build(0,0,N,I,I+1);
    }else{
      int I;
      scanf("%d",&I);
      I--;
      printf("%d\n",query(0,0,N,I+1,N,as[I])+1);
    }
  } 
}