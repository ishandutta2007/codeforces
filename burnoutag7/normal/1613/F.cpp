#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;
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

const int ML=250000;

int fact[ML+5],inv[ML+5];

ll C(int n,int r){
    return (ll)fact[n]*inv[n-r]%mod*inv[r]%mod;
}

void initialization(){
    fact[0]=1;
    for(int i=1;i<=ML;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
    }
    inv[ML]=qpow(fact[ML],mod-2);
    for(int i=ML-1;i>=0;i--){
        inv[i]=(ll)inv[i+1]*(i+1)%mod;
    }
}

struct lencmp{
    bool operator()(const vector<int> &a,const vector<int> &b)const{
        if(a.size()!=b.size())return a.size()<b.size();
        return a<b;
    }
};

int n,m,son[ML+5],cnt[ML+5];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    initialization();

    cin>>n;
    for(int i=2;i<=n;i++){
        int u,v;
        cin>>u>>v;
        son[u]++;
        son[v]++;
        son[i]--;
    }
    set<vector<int>,lencmp> s;
    for(int i=1;i<=n;i++)cnt[son[i]]++;
    for(int v=1;v<n;v++)if(cnt[v]){
        m+=cnt[v];
        vector<int> p(cnt[v]+1);
        for(int i=0,pw=1;i<=cnt[v];i++,pw=(ll)pw*v%mod)p[i]=pw*C(cnt[v],i)%mod;
        s.emplace(p);
    }
    while(s.size()>1){
        vector<int> a(*s.begin());
        s.erase(s.begin());
        vector<int> b(*s.begin());
        s.erase(s.begin());
        s.emplace(convolution(a,b));
    }
    vector<int> p(*s.begin());
    ll ans=0;
    for(int i=0;i<=m;i++){
        ans+=(i&1?-1ll:1ll)*p[i]*fact[n-i]%mod;
    }
    cout<<(ans%mod+mod)%mod;

    return 0;
}