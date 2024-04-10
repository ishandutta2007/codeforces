#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

const int64_t MOD=998244353;

int64_t inv[1000005];

int64_t as[1000][1000];

int64_t B,D,E;

void addmod(int64_t& x,int64_t y){
  x=(x+y)%MOD;
}

int main(){
  inv[1]=1;
  for(int64_t i=2;i<1000005;i++){
    inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
  }
  int64_t N,M;
  scanf("%I64d %I64d",&N,&M);
  std::map<int64_t,std::vector<std::pair<int64_t,int64_t> > > ord;
  for(int64_t i=0;i<N;i++){
    for(int64_t j=0;j<M;j++){
      scanf("%I64d",&as[i][j]);
      ord[as[i][j]].push_back({i,j});
    }
  }
  int cnt=0;
  for(auto pair:ord){
    for(auto pos:pair.second){
      int64_t i=pos.first,j=pos.second;
      as[i][j]=((cnt*i+B)*i+(cnt*j+D)*j+E)%MOD*inv[cnt]%MOD;
    }
    for(auto pos:pair.second){
      int64_t i=pos.first,j=pos.second;
      addmod(B,(MOD-2)*i);
      addmod(D,(MOD-2)*j);
      addmod(E,as[i][j]+i*i+j*j);
      cnt++;
    }
  }
  int64_t R,C;
  scanf("%I64d %I64d",&R,&C);
  R--,C--;
  printf("%I64d\n",as[R][C]);
  return 0;
}