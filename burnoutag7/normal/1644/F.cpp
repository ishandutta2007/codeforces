#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;
const int N=2e6;

int p[N+5],mu[N+5],ptot;
bool iscomp[N+5];

void sieve(){
    mu[1]=1;
    for(int i=2;i<=N;i++){
        if(!iscomp[i]){
            p[++ptot]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=ptot&&i*p[j]<=N;j++){
            iscomp[i*p[j]]=1;
            if(i%p[j]==0){
                mu[i*p[j]]=0;
                break;
            }
            mu[i*p[j]]=-mu[i];
        }
    }
}

const int G=3;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

void ntt(vector<int> &p,int inv){
    int n=p.size();
    static int r[1<<22];
    for(int i=0;i<n;i++){
        r[i]=r[i>>1]>>1;
        if(i&1)r[i]|=n>>1;
        if(r[i]>i)swap(p[i],p[r[i]]);
    }
    for(int i=2;i<=n;i*=2){
        int wn=qpow(G,(mod-1)/i);
        if(inv==-1)wn=qpow(wn,mod-2);
        for(int j=0;j<n;j+=i){
            int w=1;
            for(int k=j;k<j+i/2;k++){
                int u=p[k],t=(ll)w*p[i/2+k]%mod;
                p[k]=(u+t)%mod;
                p[i/2+k]=(u-t+mod)%mod;
                w=(ll)w*wn%mod;
            }
        }
    }
    if(inv==-1){
        int in=qpow(n,mod-2);
        for(int &x:p)x=(ll)x*in%mod;
    }
}

vector<int> convolution(vector<int> a,vector<int> b){
    if(a.empty()||b.empty())return vector<int>();
    int n=1,m=a.size()+b.size()-1;
    while(n<m)n*=2;
    a.resize(n);
    b.resize(n);
    ntt(a,1);
    ntt(b,1);
    for(int i=0;i<n;i++)a[i]=(ll)a[i]*b[i]%mod;
    ntt(a,-1);
    a.resize(m);
    return a;
}

int fact[N+5],inv[N+5];

void initialization(){
    fact[0]=1;
    for(int i=1;i<=N;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
    }
    inv[N]=qpow(fact[N],mod-2);
    for(int i=N-1;i>=0;i--){
        inv[i]=(ll)inv[i+1]*(i+1)%mod;
    }
}

int ss(int n,int m){
    static int mem[N+5];
    if(mem[n])return mem[n];
    m=min(m,n);
    static int pw[N+5];
    pw[1]=1;
    for(int i=2;i<=m;i++){
        if(!iscomp[i]){
            pw[i]=qpow(i,n);
        }
        for(int j=1;j<=ptot&&i*p[j]<=m;j++){
            pw[i*p[j]]=(ll)pw[i]*pw[p[j]]%mod;
            if(i%p[j]==0)break;
        }
    }
    static int pref[N+5];
    for(int i=0;i<=m;i++){
        pref[i]=((i?pref[i-1]:0)+(i&1?mod-inv[i]:inv[i]))%mod;
    }
    mem[n]=mod-1;
    for(int i=0;i<=m;i++)mem[n]=(mem[n]+qpow(i,n)*inv[i]%mod*pref[m-i])%mod;
    return mem[n];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve();
    initialization();
    int n,k;
    cin>>n>>k;
    if(n==1||k==1){
        cout<<1;
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)if(mu[i]){
        ans=(ans+mu[i]*ss((n+i-1)/i,k))%mod;
    }
    cout<<(ans+mod)%mod;

    return 0;
}