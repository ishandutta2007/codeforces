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
    static vector<int> r;
    r.resize(n);
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

const int precLen=300000;

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

int n,k,q,a[300005],b[10],ans[300005];
pair<int,int> qs[300005];

void deal(int m){
    int cnt[3]={0};
    for(int i=1;i<=n&&a[i]<m;i++)if(a[i]!=a[i-1]){
        if(a[i]==a[i+1])cnt[1]+=2;
        else cnt[2]++;
    }
    vector<int> pa[3];
    for(int v=1;v<=2;v++){
        vector<int> &p=pa[v];
        p.resize(cnt[v]+1);
        for(int i=0,pw=1;i<=cnt[v];i++,pw=(ll)pw*v%mod)p[i]=pw*C(cnt[v],i)%mod;
    }
    vector<int> p=convolution(pa[1],pa[2]);
    for(int i=0,j=1;i<p.size();i++){
        int len=(i+1+m)*2;
        while(j<=q&&qs[j].first<len)j++;
        while(qs[j].first==len){
            ans[qs[j].second]=(ans[qs[j].second]+p[i])%mod;
            j++;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    initialization();
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=k;i++){
        cin>>b[i];
    }
    cin>>q;
    for(int i=1;i<=q;i++)cin>>qs[i].first,qs[i].second=i;
    sort(qs+1,qs+1+q);
    for(int i=1;i<=k;i++){
        deal(b[i]);
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';

    return 0;
}