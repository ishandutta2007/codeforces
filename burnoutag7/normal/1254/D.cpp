#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ftq=998244353;

int qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1){
            res=res*a%ftq;
        }
        a=a*a%ftq;
        n>>=1;
    }
    return res;
}

int inv,n,q;
vector<int> g[150005];
int hson[150005],fa[150005],dep[150005],sz[150005],top[150005],dfn[150005],fin[150005],dfncnt,rnk[150005];
int bit[150005];

int hldprec(int x,int p,int d){
    dep[x]=d;
    sz[x]=1;
    for(int &y:g[x])if(y!=p){
        sz[x]+=hldprec(y,x,d+1);
        fa[y]=x;
        if(sz[y]>sz[hson[x]]){
            hson[x]=y;
        }
    }
    return sz[x];
}

void hlddec(int x,int head){
    top[x]=head;
    dfn[x]=++dfncnt;
    rnk[dfncnt]=x;
    if(hson[x]){
        hlddec(hson[x],head);
        for(int &y:g[x])if(y!=fa[x]&&y!=hson[x]){
            hlddec(y,y);
        }
    }
    fin[x]=dfncnt;
}

int sum(int pos){
    int res=0;
    while(pos>0){
        res=(res+bit[pos])%ftq;
        pos-=pos&-pos;
    }
    return res;
}

void add(int pos,int val){
    while(pos<=n){
        bit[pos]=(bit[pos]+val)%ftq;
        pos+=pos&-pos;
    }
}

int val[150005];

int deal(int x){
    int res=0;
    while(x&&fa[top[x]]){
        res=(res+(ll)(n-sz[top[x]])*val[fa[top[x]]]%ftq*inv%ftq)%ftq;
        x=fa[top[x]];
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    inv=qpow(n,ftq-2);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    hldprec(1,-1,0);
    hlddec(1,1);
    while(q--){
        int typ,v,d;
        cin>>typ>>v;
        if(typ==1){
            cin>>d;
            val[v]=(val[v]+d)%ftq;
            add(1,(ll)sz[v]*d%ftq*inv%ftq);
            add(dfn[v],(ftq-(ll)sz[v]*d%ftq*inv%ftq)%ftq);
            add(fin[v]+1,(ll)sz[v]*d%ftq*inv%ftq);
            if(hson[v]){
                add(dfn[hson[v]],(ll)(n-sz[hson[v]])*inv%ftq*d%ftq);
                add(fin[hson[v]]+1,(ftq-(ll)(n-sz[hson[v]])*inv%ftq*d%ftq)%ftq);
            }
        }else{
            int res=(sum(dfn[v])+val[v])%ftq;
            res=(res+deal(v))%ftq;
            cout<<res<<'\n';
        }
    }

    return 0;
}