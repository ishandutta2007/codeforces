#include <cstdio>
#include <algorithm>
#include <cassert>

const int MOD=998244353;

int as[2001][2001];

int table[2001][2001];
int dpow[2001];

int index[2001];

int N;

void update(int* ft,int i,int v){
  for(i++;i<=N;i+=(i&-i)){
    ft[i]+=v;
  }
}

int query(int* ft,int i){
  int ac=0;
  for(i++;i>0;i-=(i&-i)){
    ac+=ft[i];
  }
  return ac;
}

int get(int* ft,int i){
  return query(ft,i)-query(ft,i-1);
}

void clear(int* ft,int i){
  update(ft,i,-get(ft,i));
}

int layer[2001];
int both[2001];

int main(){
  scanf("%d",&N);
  table[0][0]=1;
  for(int i=1;i<=N;i++){
    table[i][0]=1LL*i*table[i-1][0]%MOD;
    for(int j=1;j<=i;j++){
      table[i][j]=(table[i][j-1]-table[i-1][j-1]+MOD)%MOD;
    }
  }
  dpow[0]=1;
  for(int i=1;i<=N;i++){
    dpow[i]=1LL*table[N][N]*dpow[i-1]%MOD;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      scanf("%d",&as[i][j]);
      as[i][j]--;
    }
  }
  std::fill(layer,layer+N,true);
  for(int j=0;j<N;j++){
    int cnt=0;
    for(int x=0;x<as[0][j];x++){
      cnt+=layer[x];
    }
    index[0]=(index[0]+1LL*cnt*table[N-j-1][0])%MOD;
    layer[as[0][j]]=false;
  }

  for(int i=1;i<N;i++){
    for(int j=0;j<N;j++){
      update(layer,j,1);
      update(both,j,1);
    }
    for(int j=0;j<N;j++){
      clear(both,as[i-1][j]);
      int ways_common=query(both,as[i][j]-1);
      int ways_total=query(layer,as[i][j]-1)-(as[i-1][j]<as[i][j]&&get(layer,as[i-1][j]));
      int ways_diff=ways_total-ways_common;
      int total_common=query(both,N-1);
      if(total_common-1>=0){
	index[i]=(index[i]+1LL*ways_common*table[N-j-1][total_common-1])%MOD;
      }
      index[i]=(index[i]+1LL*ways_diff*table[N-j-1][total_common])%MOD;
      clear(both,as[i][j]);
      clear(layer,as[i][j]);
    }
  }
  int ans=0;
  for(int i=0;i<N;i++){
    ans=(ans+1LL*index[i]*dpow[N-i-1])%MOD;
  }
  printf("%d\n",ans);
}