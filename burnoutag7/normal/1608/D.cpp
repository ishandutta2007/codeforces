#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;
const int G=3;
const int precLen=200000;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int fact[precLen+5],inv[precLen+5];

ll C(int n,int r){
    return (ll)fact[n]*inv[n-r]%mod*inv[r]%mod;
}

void initialization(){
    fact[0]=1;
    for(int i=1;i<=precLen;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
    }
    inv[precLen]=qpow(fact[precLen],mod-2);
    for(int i=precLen-1;i>=0;i--){
        inv[i]=(ll)inv[i+1]*(i+1)%mod;
    }
}

void ntt(vector<int> &p,int inv){
    int n=p.size();
    vector<int> r(n);
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

vector<int> make(int a,int b,int n){
    vector<int> p(n+1);
    for(int i=0;i<=n;i++){
        if((i==0||b)&&(i==n||a))p[i]=C(n,i);
    }
    return p;
}

int n,c[3][3];
vector<int> f(1,1);

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    initialization();

    cin>>n;
    for(int i=0;i<n;i++){
        char l,r;
        cin>>l>>r;
        c[l=='?'?0:l=='W'?1:2][r=='?'?0:r=='W'?1:2]++;
    }
    f=convolution(make(1,1,c[0][0]*2+c[0][1]+c[1][0]+c[0][2]+c[2][0]),
      convolution(make(1,0,c[0][1]+c[1][0]+c[1][1]*2+c[1][2]+c[2][1]),
                  make(0,1,c[0][2]+c[2][0]+c[2][2]*2+c[1][2]+c[2][1])));
    int ans=f[n];
    if(!(c[1][1]||c[2][2])){
        bool wb=c[1][0]||c[0][2]||c[1][2],bw=c[2][0]||c[0][1]||c[2][1];
        ans=(ans-qpow(2,c[0][0])+mod+2-wb-bw)%mod;
    }
    cout<<ans;

    return 0;
}