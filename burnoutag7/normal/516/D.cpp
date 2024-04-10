#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,q,root,st[100005],sz;
ll d[100005],dis,bit[100005],ans;
vector<pair<int,int>> g[100005];

ll sum(int pos){
    ll res=0;
    while(pos>0){
        res+=bit[pos];
        pos-=pos&-pos;
    }
    return res;
}

void add(int pos,ll val){
    while(pos<=100000){
        bit[pos]+=val;
        pos+=pos&-pos;
    }
}

ll pred(int x,int p){
    for(pair<int,int> &e:g[x])if(e.first!=p){
        d[x]=max(d[x],pred(e.first,x)+e.second);
    }
    return d[x];
}

void getd(int x,int p,ll cd){
    d[x]=max(d[x],cd);
    ll mx=0,sm=0;
    for(pair<int,int> &e:g[x])if(e.first!=p){
        ll cur=d[e.first]+e.second;
        if(cur>mx)sm=mx,mx=cur;
        else if(cur>sm)sm=cur;
    }
    for(pair<int,int> &e:g[x])if(e.first!=p){
        getd(e.first,x,max(cd,d[e.first]+e.second==mx?sm:mx)+e.second);
    }
}

void dfs(int x,int p){
    st[++sz]=x;
    for(pair<int,int> &e:g[x])if(e.first!=p){
        dfs(e.first,x);
    }
    int l=1,r=sz,m;
    ll res;
    while(l<=r){
        m=l+r>>1;
        if(d[x]-d[st[m]]<=dis){
            res=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
    add(res,1);
    add(sz+1,-1);
    res=sum(sz);
    ans=max(ans,res);
    add(sz,-res);
    add(sz+1,res);
    sz--;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    pred(1,-1);
    getd(1,-1,0);
    root=min_element(d+1,d+n+1)-d;
    cin>>q;
    while(q--){
        cin>>dis;
        ans=0;
        memset(bit,0,sizeof(bit));
        dfs(root,-1);
        cout<<ans<<'\n';
    }

    return 0;
}