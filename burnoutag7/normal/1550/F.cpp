#include<bits/stdc++.h>
using namespace std;

struct UnionFind{
    int sz;
    vector<int> fa;

    UnionFind(int _sz=100000){
        fa.resize((sz=_sz)+1);
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }

    void unite(int x,int y){
        x=find(x);
        y=find(y);
        fa[x]=y;
    }
}luf,ruf;

int n,q,s,d,a[200005],ll[200005],lr[200005],rl[200005],rr[200005],visc,dis[200005];
bool vis[200005];

int cost(int x){
    int res=1e9;
    if(ll[x])res=min(res,abs(d-abs(a[x]-a[ll[x]])));
    if(rl[x])res=min(res,abs(d-abs(a[x]-a[rl[x]])));
    if(lr[x]!=n+1)res=min(res,abs(d-abs(a[x]-a[lr[x]])));
    if(rr[x]!=n+1)res=min(res,abs(d-abs(a[x]-a[rr[x]])));
    return res;
}

void expand(int x,int c,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> &pq){
    if(ll[x]&&c==abs(d-abs(a[x]-a[ll[x]]))){
        if(!vis[ll[x]]){
            pq.emplace(cost(ll[x]),ll[x]);
            dis[ll[x]]=max(dis[x],c);
            vis[ll[x]]=1;
            visc++;
        }else while(vis[ll[x]-1]){
            luf.unite(ll[x],ll[x]-1);
            ll[x]=luf.find(ll[x]);
        }
        ll[x]--;
        return;
    }
    if(rl[x]&&c==abs(d-abs(a[x]-a[rl[x]]))){
        if(!vis[rl[x]]){
            pq.emplace(cost(rl[x]),rl[x]);
            dis[rl[x]]=max(dis[x],c);
            vis[rl[x]]=1;
            visc++;
        }else while(vis[rl[x]-1]){
            luf.unite(rl[x],rl[x]-1);
            rl[x]=luf.find(rl[x]);
        }
        rl[x]--;
        return;
    }
    if(lr[x]!=n+1&&c==abs(d-abs(a[x]-a[lr[x]]))){
        if(!vis[lr[x]]){
            pq.emplace(cost(lr[x]),lr[x]);
            dis[lr[x]]=max(dis[x],c);
            vis[lr[x]]=1;
            visc++;
        }else while(vis[lr[x]+1]){
            ruf.unite(lr[x],lr[x]+1);
            lr[x]=ruf.find(lr[x]);
        }
        lr[x]++;
        return;
    }
    if(rr[x]!=n+1&&c==abs(d-abs(a[x]-a[rr[x]]))){
        if(!vis[rr[x]]){
            pq.emplace(cost(rr[x]),rr[x]);
            dis[rr[x]]=max(dis[x],c);
            vis[rr[x]]=1;
            visc++;
        }else while(vis[rr[x]+1]){
            ruf.unite(rr[x],rr[x]+1);
            rr[x]=ruf.find(rr[x]);
        }
        rr[x]++;
        return;
    }
    assert(false);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q>>s>>d;
    luf=ruf=UnionFind(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1,r=1;l<=n;l++){
        while(r<=n&&a[r]-a[l]<d)r++;
        rr[l]=r;
    }
    for(int r=n,l=n;r>=1;r--){
        while(l>=1&&a[r]-a[l]<d)l--;
        ll[r]=l;
    }
    for(int l=1,r=1;l<=n;l++){
        while(r+1<=n&&a[r+1]-a[l]<=d)r++;
        rl[l]=r;
    }
    for(int r=n,l=n;r>=1;r--){
        while(l-1>=1&&a[r]-a[l-1]<=d)l--;
        lr[r]=l;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.emplace(cost(s),s);
    visc=1;
    vis[s]=1;
    while(visc!=n){
        int x=pq.top().second,c=pq.top().first;
        pq.pop();
        expand(x,c,pq);
        pq.emplace(cost(x),x);
    }
    while(q--){
        int x,k;
        cin>>x>>k;
        cout<<(dis[x]<=k?"YES\n":"NO\n");
    }

    return 0;
}