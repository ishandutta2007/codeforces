#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
bool pd[105];

void sieve(){
    for(int i=2;i<=100;i++)if(!pd[i]){
        prime.emplace_back(i);
        for(int j=i*i;j<=100;j+=i)pd[j]=1;
    }
}

typedef long long ll;

struct node{
    ll f;
    int s;
    node(){
        f=s=1;
    }
    void add(const node &a){
        f+=a.f*prime[a.s-1];
        s+=a.s;
    }
    bool operator==(const node &a)const{
        return s==a.s&&f==a.f;
    }
    bool operator<(const node &a)const{
        if(s!=a.s)return s<a.s;
        return f<a.f;
    }
};

const int mod=1e9+7;
const int precLen=15;

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

int n,m,f[1005][12],g[1<<12],ng[1<<12],ans,rt,atm[12],msk[12];
vector<int> gs[1005],gt[12];
node h[12];

void dfs(int x,int p){
    for(int y:gs[x])if(y!=p){
        dfs(y,x);
    }
    memset(g,0,sizeof(g));
    g[0]=1;
    for(int y:gs[x])if(y!=p){
        memcpy(ng,g,sizeof(ng));
        for(int s=0;s<1<<m;s++){
            for(int i=0;i<m;i++)if(s>>i&1^1){
                ng[s|1<<i]=(ng[s|1<<i]+(ll)g[s]*f[y][i])%mod;
            }
        }
        swap(g,ng);
    }
    for(int i=0;i<m;i++){
        f[x][i]=(ll)g[msk[i]]*atm[i]%mod;
    }
    ans=(ans+f[x][rt])%mod;
}

void prec(int x,int p){
    map<node,int> mp;
    atm[x]=1;
    msk[x]=0;
    h[x]=node();
    for(int y:gt[x])if(y!=p){
        prec(y,x);
        h[x].add(h[y]);
        mp[h[y]]++;
        msk[x]|=1<<y;
    }
    for(auto &[k,v]:mp)atm[x]=(ll)atm[x]*inv[v]%mod;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve();
    initialization();

    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        gs[u].emplace_back(v);
        gs[v].emplace_back(u);
    }
    cin>>m;
    for(int i=1;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        gt[u].emplace_back(v);
        gt[v].emplace_back(u);
    }
    set<node> s;
    for(rt=0;rt<m;rt++){
        prec(rt,-1);
        if(s.find(h[rt])==s.end()){
            s.insert(h[rt]);
            dfs(0,-1);
        }
    }
    cout<<ans;

    return 0;
}