#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

ll gcd(ll a,ll b){
    while(b!=0){
        a=a%b;
        swap(a,b);
    }
    return a;
}

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int q;
ll d,pw[105],inv[105];
map<ll,int> mp;

int calc(ll x){
    if(mp.find(x)!=mp.end())return mp[x];
    ll tmp=x;
    int tot=0;
    vector<pair<ll,int>> v;
    for(ll i=2;i*i<=tmp;i++){
        if(tmp%i==0){
            v.push_back(make_pair(i,0));
            while(tmp%i==0){
                tmp/=i;
                v.back().second++;
                tot++;
            }
        }
    }
    if(tmp>1){
        v.push_back(make_pair(tmp,1));
        tot++;
    }
    ll res=pw[tot];
    for(pair<ll,int> &p:v){
        res=res*inv[p.second]%mod;
    }
    return mp[x]=res;
}

int main(){

    pw[0]=1;
    inv[0]=1;
    for(int i=1;i<=100;i++){
        pw[i]=pw[i-1]*i%mod;
        inv[i]=qpow(pw[i],mod-2);
    }
    mp[1]=1;
    scanf("%lld",&d);
    scanf("%d",&q);
    while(q--){
        ll v,u;
        scanf("%lld%lld",&v,&u);
        printf("%d\n",(ll)calc(u/gcd(u,v))*calc(v/gcd(u,v))%mod);
    }

    return 0;
}