#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int fact[500005],inv[500005];

ll C(const int& n,const int& r){
    return (ll)fact[n]*inv[n-r]%mod*inv[r]%mod;
}

int n,m,fa[500005],xu[500005],xv[500005],sz[500005];
vector<int> ansv;

int find(const int& x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    fa[x]=y;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fact[0]=inv[0]=1;
    for(int i=1;i<=500000;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
        inv[i]=qpow(fact[i],mod-2);
    }
    cin>>n>>m;
    iota(fa,fa+1+m,0);
    for(int i=1;i<=n;i++){
        static int k;
        cin>>k;
        if(k==1){
            cin>>xu[i];
        }else{
            cin>>xu[i]>>xv[i];
        }
        if(find(xu[i])!=find(xv[i])){
            unite(xu[i],xv[i]);
            ansv.emplace_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        sz[find(i)]++;
    }
    int ans=qpow(2,sz[find(0)]);
    for(int i=1;i<=m;i++){
        if(find(i)==i&&find(i)!=find(0)){
            int cur=0;
            for(int j=0;j<=sz[i];j+=2)cur=(cur+C(sz[i],j))%mod;
            ans=(ll)ans*cur%mod;
        }
    }
    cout<<ans<<' '<<ansv.size()<<endl;
    for(const int& x:ansv)cout<<x<<' ';
    cout<<endl;

    return 0;
}