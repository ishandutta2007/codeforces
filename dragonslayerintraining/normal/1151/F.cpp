#include <cstdio>
#include <stdint.h>
#include <cassert>
#include <vector>

const int64_t MOD=1e9+7;

struct Matrix{
  int m,n;
  std::vector<int> data;
  Matrix(int m,int n):m(m),n(n),data(m*n){
  }
  Matrix():Matrix(0,0){
  }
  int& operator()(int i,int j){
    assert(i>=0&&i<m&&j>=0&&j<n);
    return data[i*n+j];
  }
  int operator()(int i,int j)const{
    assert(i>=0&&i<m&&j>=0&&j<n);
    return data[i*n+j];
  }
  struct Matrix operator*(struct Matrix other)const{
    assert(n==other.m);
    struct Matrix ret(m,other.n);
    for(int i=0;i<m;i++){
      for(int j=0;j<other.n;j++){
	for(int k=0;k<n;k++){
	  ret(i,j)=(ret(i,j)+1LL*(*this)(i,k)*other(k,j))%MOD;
	}
      }
    }
    return ret;
  }
}exp[30];

int as[105];
int cnt[2];

int64_t inverse(int64_t x){
  return x==1?1:(MOD-MOD/x)*inverse(MOD%x)%MOD;
}

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    cnt[as[i]]++;
  }
  int den=inverse(N*(N-1)/2%MOD);
  int worst=std::min(cnt[0],cnt[1]);
  exp[0]=Matrix(worst+1,worst+1);
  for(int bad=0;bad<=worst;bad++){
    int down=1LL*bad*bad%MOD*den%MOD;
    int up=1LL*(cnt[0]-bad)*(cnt[1]-bad)%MOD*den%MOD;
    if(bad>0) exp[0](bad,bad-1)=down;
    if(bad<worst) exp[0](bad,bad+1)=up;
    exp[0](bad,bad)=(MOD*2+1-up-down)%MOD;
  }
  /*
  printf("Built base\n");
  for(int k=0;k<3;k++){
    printf("A^%d:\n",1<<k);
    for(int i=0;i<=worst;i++){
      for(int j=0;j<=worst;j++){
	printf("%d ",exp[0](i,j));
      }
      printf("\n");
    }
  }
  */
  for(int k=1;k<30;k++){
    exp[k]=exp[k-1]*exp[k-1];
  }
  struct Matrix v(1,worst+1);
  int bad=0;
  for(int i=0;i<cnt[0];i++){
    bad+=as[i];
  }
  //printf("BAD=%d\n",bad);
  v(0,bad)=1;
  for(int k=0;k<30;k++){
    if(K&(1<<k)){
      //printf("xA^%d\n",1<<k);
      v=v*exp[k];
      assert(v.m==1&&v.n==worst+1);
    }
  }
  /*
  printf("V:\n");
  for(int i=0;i<=worst;i++){
    printf("%d\n",v(0,i));
  }
  */
  printf("%d\n",v(0,0));
  return 0;
}