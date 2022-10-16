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
const int MAXN=(1<<20)+10,mod=998244353,INF=1e9;
int mypow(int a,int n){
    if(!n)return 1;
    int tmp=mypow(a,n/2);tmp=1ll*tmp*tmp%mod;
    if(n&1)tmp=1ll*tmp*a%mod;return tmp;
}
int n,k,f;
struct Poly{
    vector<int>c;int n;
    Poly(int n=0){c.clear();this->n=n;c.resize(n+1);}
    void set(int n){this->n=n;c.resize(n+1);}
    void operator=(const Poly p2){set(p2.n);rep(i,0,n)c[i]=p2.c[i];}
    int operator[](const int x)const{return n>=x?c[x]:0;}
}F[20],G;
namespace NTT{
    int f[MAXN],g[MAXN],h[MAXN],rev[MAXN],N;
    void change(int* f,int N){rep(i,0,N-1)if(i<rev[i])swap(f[i],f[rev[i]]);}
    void DFT(int* f,int N,int rev){
        change(f,N);
        for(int len=2;len<=N;len<<=1){
            int step=mypow(rev,(mod-1)/len);
            for(int i=0;i<N;i+=len){
                int w=1;
                rep(j,0,len/2-1){
                    ll x=f[i+j],y=f[i+j+len/2];
                    f[i+j]=(x+w*y)%mod;
                    f[i+j+len/2]=(x-w*y%mod+mod)%mod;
                    w=1ll*w*step%mod;
                }
            }
        }
    }
    Poly ntt(const Poly F,const Poly G,int lim=INF){
        int n=min(F.n,lim),m=min(G.n,lim);
        N=1;while(N<=(n+m))N<<=1;
        rep(i,0,N-1)f[i]=g[i]=h[i]=0;
        rep(i,0,n)f[i]=F[i];rep(i,0,m)g[i]=G[i];
        rep(i,0,N-1){
            rev[i]=rev[i>>1]>>1;
            if(i&1)rev[i]|=(N>>1);
        }
        DFT(f,N,3);DFT(g,N,3);
        rep(i,0,N-1)h[i]=1ll*f[i]*g[i]%mod;
        DFT(h,N,mypow(3,mod-2));
        int inv=mypow(N,mod-2);rep(i,0,N-1)h[i]=1ll*h[i]*inv%mod;
        Poly ret(min(n+m,lim));
        rep(i,0,ret.n)ret.c[i]=h[i];
        return ret;
    }
};
Poly operator+(const Poly p1,const Poly p2){
    Poly ret(max(p1.n,p2.n));
    rep(i,0,ret.n)ret.c[i]=(p1[i]+p2[i])%mod;
    return ret;
}
Poly operator-(const Poly p1,const Poly p2){
    Poly ret(max(p1.n,p2.n));
    rep(i,0,ret.n)ret.c[i]=(p1[i]-p2[i]+mod)%mod;
    return ret;
}
Poly mult(const Poly p1,const Poly p2,int lim=INF){return NTT::ntt(p1,p2,lim);}
ll suf[MAXN];
int main(){
    cin>>n>>k>>f;
    F[1].set(k);
    rep(i,0,k)F[1].c[i]=(i<=k)?(1):(0);
    rep(i,2,n){
        F[i]=mult(F[i-1],F[i-1],2*k);
        suf[2*k+1]=0;
        per(j,2*k,0)suf[j]=(suf[j+1]+F[i][j])%mod;
        rep(j,0,2*k){
            if(j>k){F[i].c[j]=0;continue;}
            F[i].c[j]=1ll*F[i].c[j]*(k-j+1)%mod;
            F[i].c[j]=(F[i].c[j]+suf[j+1])%mod;
        }
    }
    G=mult(F[n],F[n],f);
    cout<<G[f];
    return 0;
}