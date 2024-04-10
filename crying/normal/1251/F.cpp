#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=1.2e6+10,LIM=1.2e6,mod=998244353;
int mypow(int a,int n){
    int ret=1,val=a;
    while(n){
        if(n&1)ret=1ll*ret*val%mod;
        val=1ll*val*val%mod;
        n>>=1;
    }
    return ret;
}
namespace MyPoly{
    int f[MAXN],g[MAXN],h[MAXN],R[MAXN],N;
    void change(int* f,int N){rep(i,0,N-1)if(i<R[i])swap(f[i],f[R[i]]);}
    void DFT(int* f,int N,ll rev){
        change(f,N);
        for(int len=2;len<=N;len<<=1){
            ll step=mypow(rev,(mod-1)/len);
            for(int i=0;i<N;i+=len){
                ll w=1;
                rep(k,0,len/2-1){
                    ll x=f[i+k],y=f[i+k+len/2];
                    f[i+k]=(x+w*y%mod)%mod;
                    f[i+k+len/2]=(x-w*y%mod+mod)%mod;
                    w=w*step%mod;
                }
            }
        }
    }
    void NTT(int* a,int* b,int* c,int n,int m){
        N=1;while(N<=n+m)N<<=1;
        rep(i,0,N)f[i]=g[i]=h[i]=0;
        rep(i,1,N-1){
            R[i]=R[i>>1]>>1;
            if(i&1)R[i]|=(N>>1);
        }
        rep(i,0,n)f[i]=a[i];rep(i,0,m)g[i]=b[i];
        DFT(f,N,3);DFT(g,N,3);
        rep(i,0,N-1)h[i]=1ll*f[i]*g[i]%mod;
        DFT(h,N,mypow(3,mod-2));
        ll d=mypow(N,mod-2);
        rep(i,0,N-1)h[i]=h[i]*d%mod;
        rep(i,0,n+m)c[i]=h[i];
    }
};
int n,k,q,a[MAXN],b[MAXN],Q[MAXN];
ll ans[MAXN],fact[MAXN],inv[MAXN],power[MAXN];
int f[MAXN],g[MAXN],h[MAXN],bucket[MAXN];
int tmp[19][MAXN];
ll C(int n,int m){
    if(n<m || n<0 || m<0)return 0;
    return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
void solve(int len){
    memset(bucket,0,sizeof bucket);
    rep(i,1,n){if(a[i]<len)bucket[a[i]]++;}
    int x=0,y=0;
    rep(i,1,3e5)if(bucket[i]==1)x++;else if(bucket[i]>1)y++;
    memset(f,0,sizeof f);memset(g,0,sizeof g);memset(h,0,sizeof h);
    rep(i,0,x)f[i]=C(x,i)*power[i]%mod;
    rep(i,0,2*y)g[i]=C(2*y,i);
    MyPoly::NTT(f,g,h,x,y*2);
    rep(i,1,q){ 
        if(Q[i]/2<=len)continue;
        ans[i]=(ans[i]+h[Q[i]/2-len-1])%mod;
    }
}
int main(){
    fact[0]=1;rep(i,1,LIM)fact[i]=fact[i-1]*i%mod;
    power[0]=1;rep(i,1,LIM)power[i]=power[i-1]*2%mod;
    inv[LIM]=mypow(fact[LIM],mod-2);per(i,LIM-1,0)inv[i]=inv[i+1]*(i+1)%mod;
    cin>>n>>k;
    rep(i,1,n)cin>>a[i];
    rep(i,1,k)cin>>b[i];
    cin>>q;
    rep(i,1,q)cin>>Q[i];
    rep(i,1,k)solve(b[i]);
    rep(i,1,q)cout<<ans[i]<<endl;
    return 0;
}