#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=40,M=1440,mod=1000000007;

template<typename T,typename T2,T mod>
struct modint{

  using mint=modint<T,T2,mod>;

  T v;

  modint(){v=0;}
  modint(T V){v=V;}

  static constexpr T umod(){return mod;}

  mint &operator += (const mint &p){(v+=p.v)>=mod?v-=mod:0;return *this;}
  mint &operator -= (const mint &p){(v-=p.v)<0?v+=mod:0;return *this;}
  mint &operator *= (const mint &p){v=T2(v)*p.v%mod;return *this;}
  mint &operator ++ (){v+1<mod?++v:v=0;return *this;}
  mint operator ++ (int){mint res=*this;v+1<mod?++v:v=0;return res;}
  mint &operator -- (){v?--v:v=mod-1;return *this;}
  mint operator -- (int){mint res=*this;v?--v:v=mod-1;return res;}
  friend mint operator + (const mint &a,const mint &b){return mint(a)+=b;}
  friend mint operator - (const mint &a,const mint &b){return mint(a)-=b;}
  friend mint operator * (const mint &a,const mint &b){return mint(a)*=b;}
  friend bool operator == (const mint &a,const mint &b){return a.v==b.v;}
  friend bool operator != (const mint &a,const mint &b){return a.v!=b.v;}

  template<typename Temp>mint pow(Temp k){
    mint a=*this,res=1;
    for (;k;k/=2,a*=a)
      if (k&1) res*=a;
    return res;
  }

  mint inv(){return pow(mod-2);}

};
typedef modint<int,LL,mod> mint;

int n,a[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
    scanf("%d",&a[i]);
}

mint inv[N+9],fac[N+9],ifac[N+9];

void Get_inv(){
  inv[1]=1;
  fac[0]=fac[1]=1;
  ifac[0]=ifac[1]=1;
  for (int i=2;i<=n;++i){
    inv[i]=(mod-mod/i)*inv[mod%i];
    fac[i]=fac[i-1]*i;
    ifac[i]=ifac[i-1]*inv[i];
  }
}

mint Get_c(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]*ifac[n-m];}

int vis[N+9],cnt[N+9];

void Get_cnt(){
  for (int i=1;i<=n;++i){
    if (vis[i]) continue;
    int c=0;
    for (int j=i;!vis[j];vis[j]=1,j=a[j]) ++c;
    ++cnt[c];
  }
}

int ml[N+9];
mint dp[M+9];

mint Dfs_dp(int k,int s,int t,int x,int y,mint now){
  if (k==n) return dp[s-t]*now*(fac[n]*inv[n-x+y]).pow(y);
  int lim=s/ml[k]%(cnt[k+1]+1);
  mint res=0;
  for (int i=0;i<=lim;++i)
    res+=Dfs_dp(k+1,s,t+i*ml[k],x+lim*(k+1),y+i*(k+1),now*Get_c(lim,i)*(i&1?mod-1:1));
  return res;
}

void Get_dp(){
  ml[0]=1;
  for (int i=1;i<=n;++i) ml[i]=ml[i-1]*(cnt[i]+1);
  dp[0]=1;
  for (int s=1;s<ml[n];++s) dp[s]=Dfs_dp(0,s,0,0,0,mod-1);
}

void work(){
  Get_inv();
  Get_cnt();
  Get_dp();
}

void outo(){
  printf("%d\n",dp[ml[n]-1].v);
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}