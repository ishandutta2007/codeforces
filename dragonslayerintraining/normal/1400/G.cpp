#include <cstdio>
#include <stdint.h>
#include <algorithm>
#include <map>

const int MAXN=300005;
const int MOD=998244353;

int fact[MAXN]={1,1};
int inv[MAXN]={0,1};
int invfact[MAXN]={1,1};

int ls[MAXN];
int rs[MAXN];

int lower[1<<20];
int upper[1<<20];
uint64_t ban[1<<20];

int merc[MAXN];
int prefix[41][MAXN];

int cnt[1<<20];

int choose(int n,int k){
  if(n<0||k<0||k>n) return 0;
  return 1LL*fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=2;i<=N;i++){
    inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    fact[i]=1LL*fact[i-1]*i%MOD;
    invfact[i]=1LL*invfact[i-1]*inv[i]%MOD;
  }
  for(int i=0;i<N;i++){
    scanf("%d %d",&ls[i],&rs[i]);
    merc[ls[i]]++;
    merc[rs[i]+1]--;
  }
  for(int i=1;i<=N;i++){
    merc[i]+=merc[i-1];
  }
  //k fixed
  for(int k=0;k<=M*2;k++){
    for(int i=1;i<=N;i++){
      prefix[k][i]=(prefix[k][i-1]+choose(merc[i]-k,i-k))%MOD;
      //printf("prefix[%d][%d]=%d\n",k,i,prefix[k][i]);
    }
  }
  lower[0]=1;
  upper[0]=N;
  ban[0]=0;
  std::map<int,int> cps;
  for(int i=0;i<M;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    lower[1<<i]=std::max(ls[A],ls[B]);
    upper[1<<i]=std::min(rs[A],rs[B]);
    if(!cps.count(A)){
      int tmp=cps.size();
      cps[A]=tmp;
    }
    if(!cps.count(B)){
      int tmp=cps.size();
      cps[B]=tmp;
    }
    ban[1<<i]=(1ULL<<cps[A])|(1ULL<<cps[B]);
  }
  for(int mask=1;mask<(1<<M);mask++){
    int sub=mask&(mask-1);
    lower[mask]=std::max(lower[sub],lower[mask^sub]);
    upper[mask]=std::min(upper[sub],upper[mask^sub]);
    ban[mask]=ban[sub]|ban[mask^sub];
  }
  int sum=0;
  for(int mask=0;mask<(1<<M);mask++){
    int distinct=__builtin_popcountll(ban[mask]);
    int low=lower[mask],high=upper[mask];
    if(low>high) continue;
    int cnt=0;
    /*
    for(int size=low;size<=high;size++){
      cnt=(cnt+choose(merc[size]-distinct,size-distinct))%MOD;
    }
    */
    cnt=(prefix[distinct][high]+MOD-prefix[distinct][low-1])%MOD;
    if(__builtin_popcount(mask)%2==0){
      sum=(sum+cnt)%MOD;
    }else{
      sum=(sum-cnt+MOD)%MOD;
    }
    //printf("cnt[%d]=%d\n",mask,cnt);
  }
  printf("%d\n",sum);
}