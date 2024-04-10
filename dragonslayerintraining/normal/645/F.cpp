#include <cstdio>
#include <vector>

const int MOD=1e9+7;

std::vector<int> factor[1000005];
int fs[1000005];
int gs[1000005];
int scale[1000005];
int ans=0;

int fact[2000005]={1,1};
int inv[2000005]={0,1};
int invfact[2000005]={1,1};
int N,K;

int choose(int n,int k){
  if(k<0||k>n) return 0;
  return 1LL*fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
}

void add(int x){
  for(int y:factor[x]){
    ans=(ans+1LL*(MOD-scale[y])*gs[y])%MOD;
    fs[y]++;
    gs[y]=choose(fs[y],K);
    ans=(ans+1LL*(scale[y])*gs[y])%MOD;
  }
}

int main(){
  for(int i=2;i<=2000000;i++){
    fact[i]=1LL*i*fact[i-1]%MOD;
    inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    invfact[i]=1LL*inv[i]*invfact[i-1]%MOD;
  }
  for(int i=1;i<=1000000;i++){
    for(int j=i;j<=1000000;j+=i){
      factor[j].push_back(i);
    }
  }
  for(int i=1;i<=1000000;i++){
    scale[i]=i;
  }
  for(int i=1;i<=1000000;i++){
    for(int j=i*2;j<=1000000;j+=i){
      scale[j]=(scale[j]+MOD-scale[i])%MOD;
    }
  }
  int Q;
  scanf("%d %d %d",&N,&K,&Q);
  
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    add(A);
  }
  for(int i=0;i<Q;i++){
    int A;
    scanf("%d",&A);
    add(A);
    printf("%d\n",ans);
  }
  return 0;
}