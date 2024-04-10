#include <cstdio>
#include <cassert>

const int MOD=1e9+9;

template<int R,int C>
struct Matrix{
  int mat[R][C];
  Matrix(){
    for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
	mat[i][j]=0;
      }
    }
  }
  int& operator()(int r,int c){
    assert(r>=0&&r<R&&c>=0&&c<C);
    return mat[r][c];
  }
};

template<int M,int N,int P>
struct Matrix<M,P> operator*(struct Matrix<M,N> a,struct Matrix<N,P> b){
  struct Matrix<M,P> res;
  for(int i=0;i<M;i++){
    for(int j=0;j<P;j++){
      for(int k=0;k<N;k++){
	res(i,j)=(res(i,j)+1LL*a(i,k)*b(k,j))%MOD;
      }
    }
  }
  return res;
}

template<int M,int N>
struct Matrix<M,N>& operator+=(struct Matrix<M,N>& a,struct Matrix<M,N> b){
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      a(i,j)=(a(i,j)+b(i,j))%MOD;
    }
  }
  return a;
}

template<int M,int N>
struct Matrix<M,N> operator+(struct Matrix<M,N> a,struct Matrix<M,N> b){
  return a+=b;
}

int as[300005];
struct Matrix<2,2> pows[300005];
struct Matrix<2,2> powsums[300005];

struct Matrix<2,1> st[1200005];
struct Matrix<2,1> lazy[1200005];

void push(int w,int L,int R){
  if(R-L>1){
    int M=(L+R)/2;
    lazy[w<<1]+=lazy[w];
    lazy[w<<1|1]+=pows[M-L]*lazy[w];
  }
  st[w]+=powsums[R-L]*lazy[w];
  lazy[w]=Matrix<2,1>();
}

void pull(int w,int L,int R){
  st[w]=st[w<<1]+st[w<<1|1];
}

void build(int w,int L,int R){
  if(R-L==1){
    st[w](0,0)=as[L];
  }else{
    int M=(L+R)/2;
    build(w<<1,L,M);
    build(w<<1|1,M,R);
    pull(w,L,R);
  }
}

struct Matrix<2,1> query(int w,int L,int R,int a,int b){
  push(w,L,R);
  if(b<=L||a>=R) return Matrix<2,1>();
  if(a<=L&&b>=R){
    return st[w];
  }else{
    int M=(L+R)/2;
    return query(w<<1,L,M,a,b)+query(w<<1|1,M,R,a,b);
  }
}

void update(int w,int L,int R,int a,int b,struct Matrix<2,1>& v){
  push(w,L,R);
  if(b<=L||a>=R) return;
  if(a<=L&&b>=R){
    //printf("update(%d)[%d,%d),[%d,%d),(%d,%d))\n",w,L,R,a,b,v(0,0),v(1,0));
    lazy[w]+=v;
    push(w,L,R);
    v=pows[R-L]*v;
  }else{
    int M=(L+R)/2;
    update(w<<1,L,M,a,b,v);
    update(w<<1|1,M,R,a,b,v);
    pull(w,L,R);
  }
}
  
int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  pows[0](0,0)=1;
  pows[0](1,1)=1;
  pows[1](0,1)=1;
  pows[1](1,0)=1;
  pows[1](1,1)=1;
  for(int i=2;i<=N;i++){
    pows[i]=pows[i-1]*pows[1];
  }
  for(int i=1;i<=N;i++){
    powsums[i]=powsums[i-1]+pows[i-1];
  }
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  build(1,0,N);
  while(M--){
    int T,L,R;
    scanf("%d %d %d",&T,&L,&R);
    L--;
    if(T==1){
      struct Matrix<2,1> v;
      v(0,0)=1;
      v(1,0)=1;
      update(1,0,N,L,R,v);
    }else{
      printf("%d\n",query(1,0,N,L,R)(0,0));
    }
  }
  return 0;
}