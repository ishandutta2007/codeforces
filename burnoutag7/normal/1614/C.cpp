#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;

struct SegTree{
    int sz;
    vector<uint> dat;

    SegTree(int _sz=1<<17){
        sz=1;
        while(sz<_sz)sz<<=1;
        dat.resize(sz<<1,-1);
    }

    void upd(int id,int l,int r,int ql,int qr,uint val){
        if(qr<l||r<ql)return;
        if(ql<=l&&r<=qr){
            dat[id]&=val;
            return;
        }
        dat[id<<1]&=dat[id];
        dat[id<<1|1]&=dat[id];
        upd(id<<1,l,l+r>>1,ql,qr,val);
        upd(id<<1|1,(l+r>>1)+1,r,ql,qr,val);
    }

    void upd(int l,int r,uint val){
        upd(1,1,sz,l,r,val);
    }

    void build(){
        for(int id=1;id<sz;id++){
            dat[id<<1]&=dat[id];
            dat[id<<1|1]&=dat[id];
        }
    }

    uint qry(int q){
        return dat[q+sz-1];
    }
};

typedef long long ll;
const int mod=1e9+7;
const int precLen=2e5;

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

int n,m,a[200005];

void mian(){
    cin>>n>>m;
    SegTree s(n);
    for(int i=0;i<m;i++){
        int l,r,x;
        cin>>l>>r>>x;
        s.upd(l,r,x);
    }
    s.build();
    for(int i=1;i<=n;i++){
        a[i]=s.qry(i);
    }
    ll ans=0;
    for(int i=0;i<30;i++){
        int c=0;
        for(int j=1;j<=n;j++)if(a[j]>>i&1)c++;
        int rs=qpow(2,n-c+i);
        for(int j=1;j<=c;j+=2){
            ans+=C(c,j)*rs%mod;
        }
    }
    cout<<ans%mod<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    initialization();
    
    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}