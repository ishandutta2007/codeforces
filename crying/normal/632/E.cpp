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
const int MAXN=(1<<21)+10,mod=998244353,INF=1e9;
//poly-template
ll mypow(ll a,ll n){
    if(!n)return 1;
    ll tmp=mypow(a,n/2);tmp=tmp*tmp%mod;
    if(n&1)tmp=tmp*a%mod;return tmp;
}
ll myinv(ll a){return mypow(a,mod-2);}
void add(ll& x,ll v){x=(x+v)%mod;}
void radd(ll& x,ll v){x=(x+mod-v)%mod;}
struct Poly{
    vector<ll>a;
    int n;
    Poly(int N=0){a.resize(N+1,0);n=N;}
    void split(int N,int mode=0){if(mode || (n>N) ){a.resize(N+1,0);n=N;}}
    void output(){rep(i,0,n)cout<<a[i]<<" ";cout<<"\n";}
    void replace(){
        rep(i,0,n)a[i]=(a[i])?(1):(0);
    }
};
namespace NTT{
    ll f[MAXN],g[MAXN],h[MAXN],rev[MAXN],N;
    void change(ll* f,int N){rep(i,0,N-1)if(i<rev[i])swap(f[i],f[rev[i]]);}
    void DFT(ll* f,int N,ll rev){
        change(f,N);
        for(int len=2;len<=N;len<<=1){
            ll step=mypow(rev,(mod-1)/len);
            for(int i=0;i<N;i+=len){
                ll w=1;
                rep(j,0,len/2-1){
                    ll x=f[i+j],y=f[i+j+len/2];
                    f[i+j]=(x+w*y)%mod;
                    f[i+j+len/2]=(x-w*y%mod+mod)%mod;
                    w=1ll*w*step%mod;
                }
            }
        }
    }
    Poly ntt(Poly F,Poly G){
        int n=F.n,m=G.n;N=1;
        while(N<=(n+m))N<<=1;
        rep(i,0,N-1)f[i]=g[i]=h[i]=0;
        rep(i,0,N-1){
            rev[i]=rev[i>>1]>>1;
            if(i&1)rev[i]|=(N>>1);
        }
        rep(i,0,n)f[i]=F.a[i];
        rep(i,0,m)g[i]=G.a[i];
        DFT(f,N,3);DFT(g,N,3);
        rep(i,0,N-1)h[i]=1ll*f[i]*g[i]%mod;
        DFT(h,N,myinv(3));
        ll inv=myinv(N);
        rep(i,0,N-1)h[i]=1ll*h[i]*inv%mod;
        Poly ret(n+m);
        rep(i,0,n+m)ret.a[i]=h[i];
        return ret;
    }
};
Poly operator+(Poly p1,Poly p2){
    if(p1.n<p2.n)swap(p1,p2);
    rep(i,0,p2.n)add(p1.a[i],p2.a[i]);
    return p1;
}
Poly operator-(Poly p1,Poly p2){
    int flag=0;
    if(p1.n<p2.n)flag=1,swap(p1,p2);
    rep(i,0,p2.n)radd(p1.a[i],p2.a[i]);
    if(flag)rep(i,0,p1.n)p1.a[i]=(mod-p1.a[i])%mod;
    return p1;
}
Poly operator*(int c,Poly p){
    rep(i,0,p.n)p.a[i]=1ll*c*p.a[i]%mod;
    return p;
}
Poly operator*(Poly p1,Poly p2){return NTT::ntt(p1,p2);}
namespace INV{
    Poly solve(Poly A,int N){
        if(N==1){
            Poly ret(0);
            ret.a[0]=myinv(A.a[0]);
            return ret;
        }
        Poly F0=solve(A,(N+1)>>1);
        A.split(N-1);
        A=A*F0;A.split(N-1);
        A=A*F0;A.split(N-1);
        return 2*F0-A;
    }  
    Poly solve(Poly A){return solve(A,A.n+1);}
};
Poly inv(Poly p1){return INV::solve(p1);}
Poly diff(Poly p){
    if(p.n==0){p.a[0]=0;return p;}
    rep(i,0,p.n-1)p.a[i]=1ll*(i+1)*p.a[i+1]%mod;
    p.split(p.n-1);return p;
}
Poly inte(Poly p){
    p.split(p.n+1);
    per(i,p.n,1)p.a[i]=myinv(i)*p.a[i-1]%mod;
    p.a[0]=0;return p;
}
Poly ln(Poly A){
    int n=A.n;
    Poly AA=diff(A);
    AA=AA*inv(A);AA.split(n);
    AA=inte(AA);AA.split(n);
    return AA;
}
namespace EXP{
    Poly solve(Poly A,int N){
        if(N==1){
            Poly ret(0);ret.a[0]=1;return ret;
        }
        Poly F0=solve(A,(N+1)/2);F0.split(N-1,1);
        Poly TMP=A;TMP.split(N-1);
        TMP=TMP-ln(F0);TMP.split(N-1);
        add(TMP.a[0],1);
        F0=F0*TMP;F0.split(N-1);
        return F0;
    }
    Poly solve(Poly A){return solve(A,A.n+1);}
};
Poly Exp(Poly A){return EXP::solve(A);}

//
int n,k,a[MAXN],mn,mx,lim;
Poly F;
Poly poly_pow(int n){
    if(n==1){
        Poly tmp=F;
        tmp.split(mx);
        return tmp;
    }
    Poly tmp=poly_pow(n/2);tmp=tmp*tmp;
    tmp.split(n*mx);
    if(n&1){
        tmp=tmp*F;tmp.split(n*mx);
    }
    tmp.replace();
    return tmp;
}
int main(){
    cin>>n>>k;
    rep(i,1,n)cin>>a[i];
    mn=mx=a[1];
    rep(i,2,n)mn=min(mn,a[i]),mx=max(mx,a[i]);
    mx-=mn;
    lim=mx*k;  
    F.split(lim,1);
    rep(i,1,n)add(F.a[a[i]-mn],1);
    Poly res=poly_pow(k);
    rep(i,0,lim)if(res.a[i])cout<<i+mn*k<<" ";


    return 0;
}