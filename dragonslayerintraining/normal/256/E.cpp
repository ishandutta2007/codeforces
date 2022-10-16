#include <iostream>
#include <stdint.h>

const int64_t MOD=777777777;

struct matrix{
  int mat[3][3];
  int operator()(int x,int y)const{
    return mat[x][y];
  }
  int& operator()(int x,int y){
    return mat[x][y];
  }
  struct matrix operator*(struct matrix other)const{
    struct matrix ret;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	ret.mat[i][j]=0;
	for(int k=0;k<3;k++){
	  ret.mat[i][j]=(ret.mat[i][j]+static_cast<int64_t>(mat[i][k])*other.mat[k][j])%MOD;
	}
      }
    }
    return ret;
  }
};

struct matrix lucky;
struct matrix unit[4];

struct matrix st[4*77777];
int N;

void build(int w,int L,int R){
  if(R-L==1){
    st[w]=unit[0];
    return;
  }
  int M=(L+R)/2;
  build(w*2+1,L,M);
  build(w*2+2,M,R);
  st[w]=st[w*2+1]*lucky*st[w*2+2];
}

void build(){
  build(0,0,N);
}

void set(int w,int L,int R,int i,int v){
  if((i<L)||(i>=R)){
    return;
  }
  if(R-L==1){
    st[w]=unit[v];
    return;
  }
  int M=(L+R)/2;
  set(w*2+1,L,M,i,v);
  set(w*2+2,M,R,i,v);
  st[w]=st[w*2+1]*lucky*st[w*2+2];
}

void set(int i,int v){
  set(0,0,N,i,v);
}

int query(){
  const struct matrix& mat=st[0];
  int cnt=0;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cnt=(cnt+static_cast<int64_t>(mat(i,j)))%MOD;
    }
  }
  return cnt;
}

int main(){
  for(int k=0;k<4;k++){
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	unit[k](i,j)=0;
      }
    }
  }
  for(int i=0;i<3;i++){
    unit[0](i,i)=1;
    unit[i+1](i,i)=1;
  }
  int M;
  std::cin>>N>>M;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      std::cin>>lucky(i,j);
    }
  }
  build();
  for(int i=0;i<M;i++){
    int V,T;
    std::cin>>V>>T;
    set(V-1,T);
    std::cout<<query()<<std::endl;
  }
  return 0;
}