#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>

const int MOD=998244353;
const int HALF=(MOD+1)/2;

const int RT23=15311432;//2^23rd root of unity

int root[24];

void ntt(std::vector<int>& v,bool inv=false){
  int K=0;
  while((1<<K)<v.size()) K++;
  v.resize(1<<K);
  if(inv) std::reverse(v.begin()+1,v.end());
  int rev=0;
  for(int i=0;i<(1<<K);i++){
    if(i<rev) std::swap(v[i],v[rev]);
    if(i==(1<<K)-1) break;
    int k=K-1;
    while(rev&(1<<k)){
      rev^=(1<<k);
      k--;
    }
    rev|=(1<<k);
  }
  for(int k=0;k<K;k++){
    int opow=1;
    for(int i=0;i<(1<<K);i++){
      if(i&(1<<k)) {opow=1;continue;}
      int j=i|(1<<k);
      int x=v[i],y=v[j];
      v[i]=(x+1LL*y*opow)%MOD;
      v[j]=(x+(MOD-1LL)*y%MOD*opow)%MOD;
      opow=(1LL*opow*root[k+1])%MOD;
    }
  }
  if(inv){
    int invN=1;
    for(int i=0;i<K;i++){
      invN=(1LL*invN*HALF)%MOD;
    }
    for(int i=0;i<(1<<K);i++){
      v[i]=(1LL*v[i]*invN)%MOD;
    }
  }
}

std::vector<int> mul(std::vector<int> a,std::vector<int> b){
  if(a.empty()||b.empty()) return {};
  int size=1;
  while(size<a.size()||size<b.size()) size*=2;
  size*=2;
  a.resize(size);
  b.resize(size);
  ntt(a);
  ntt(b);
  for(int i=0;i<a.size();i++){
    a[i]=(1LL*a[i]*b[i])%MOD;
  }
  ntt(a,true);
  while(a.size()>0&&a.back()==0){
    a.pop_back();
  }
  return a;
}

  
std::vector<int> mul(std::vector<int> a,int b){
  for(int i=0;i<a.size();i++){
    a[i]=(1LL*a[i]*b)%MOD;
  }
  return a;
}
  
std::vector<int> add(std::vector<int> a,const std::vector<int>& b){
  if(b.size()>a.size()) a.resize(b.size());
  for(int i=0;i<b.size();i++){
    a[i]=(a[i]+b[i])%MOD;
  }
  while(a.size()>0&&a.back()==0){
    a.pop_back();
  }
  return a;
}

struct Mat{
  std::array<std::array<std::vector<int>,2>,2> mat;//mat[out][in]=coeff
  Mat(){
    mat[0][0].push_back(1);
    mat[1][1].push_back(1);
  }
  Mat(Mat a,Mat b){
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
	for(int k=0;k<2;k++){
	  mat[i][k]=add(mat[i][k],mul(a.mat[i][j],b.mat[j][k]));
	}
      }
    }
  }
}base[2];

int as[100005];
int bs[100005];

Mat solve(int l,int r){
  if(l==r) return Mat();
  if(r-l==1){
    return base[bs[l]];
  }else{
    int m=(l+r)/2;
    return Mat(solve(m,r),solve(l,m));
  }
}

int fact[100005];

int main(){
  root[23]=RT23;
  for(int i=22;i>=0;i--){
    root[i]=1LL*root[i+1]*root[i+1]%MOD;
  }
  int N,M=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N;i+=as[i]){
    if(std::count(as+i,as+i+as[i],as[i])!=as[i]){
      printf("0\n");
      return 0;
    }
    bs[M++]=(as[i]>1);
  }
  
  base[0].mat[0][0]=std::vector<int>({1});
  base[0].mat[0][1]=std::vector<int>({1});
  base[0].mat[1][0]=std::vector<int>({0,2});
  base[0].mat[1][1]=std::vector<int>({0,1});
  
  base[1].mat[0][0]=std::vector<int>();
  base[1].mat[0][1]=std::vector<int>();
  base[1].mat[1][0]=std::vector<int>({2,2});
  base[1].mat[1][1]=std::vector<int>({2,1});
  
  fact[0]=1;
  for(int i=1;i<=M;i++){
    fact[i]=1LL*i*fact[i-1]%MOD;
  }
  Mat res=solve(1,M);
  //If first entry is 1, take (1,1)*res*(1,0)^T
  //If first entry is >=2, take (1,1)*res*(0,2)^T
  std::vector<int> poly=mul(add(res.mat[0][bs[0]],res.mat[1][bs[0]]),bs[0]?2:1);
  int ans=0;
  for(int i=0;i<poly.size();i++){
    ans=(ans+(i%2==0?1LL:MOD-1LL)*poly[i]%MOD*fact[M-i])%MOD;
  }
  printf("%d\n",ans);
}