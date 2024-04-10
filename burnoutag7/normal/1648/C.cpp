#include<bits/stdc++.h>
using namespace std;

template<typename T> struct bitsum{
    int sz;
    vector<T> hav;

    bitsum(int _sz){
        sz=_sz;
        hav.resize(sz+1);
    }

    T sum(int pos){
        T res=0;
        while(pos>0){
            res+=hav[pos];
            pos-=pos&-pos;
        }
        return res;
    }

    void add(int pos,T val){
        while(pos<=sz){
            hav[pos]+=val;
            pos+=pos&-pos;
        }
    }

    void clear(){
        hav.assign(sz+1,0);
    }
};

typedef long long ll;
const int mod=998244353;
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

ll binom(int n,int r){
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

const int V=200000;
int n,m,c[200005],t[200005];
bitsum<int> hav(V),tot(V);

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    initialization();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        c[v]++;
        if(c[v]==1)hav.add(v,1);
        tot.add(v,1);
    }
    ll coef=1;
    for(int i=1;i<=V;i++)coef=coef*fact[c[i]]%mod;
    coef=qpow(coef,mod-2);
    for(int i=1;i<=m;i++){
        cin>>t[i];
    }
    ll ans=0;
    bool valid=1;
    for(int i=1;i<=min(n,m);i++){
        ll val=(ll)fact[n-i]*coef%mod*tot.sum(t[i]-1)%mod;
        ans=(ans+val)%mod;
        coef=coef*c[t[i]]%mod;
        c[t[i]]--;
        if(c[t[i]]<0){
            valid=0;
            break;
        }
        if(!c[t[i]])hav.add(t[i],-1);
        tot.add(t[i],-1);
    }
    if(n<m&&valid)ans=(ans+1)%mod;
    cout<<ans<<'\n';

    return 0;
}