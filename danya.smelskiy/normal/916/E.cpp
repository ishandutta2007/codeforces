#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100005];
int sz;
long long ob[500005];
long long t[500005];
int dp[100005][18];
int depth[100005];
vector<int> v[100005];
int tin[100005];
int tout[100005];
int timer;
int poc[100005];
int lastroot;

void dfs(int x,int y) {
    dp[x][0]=y;
    for (int i=1;i<=17;++i)
        dp[x][i]=dp[dp[x][i-1]][i-1];
    depth[x]=depth[y]+1;
    tin[x]=++timer;
    poc[timer]=x;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to!=y) dfs(to,x);
    }
    tout[x]=timer;
}

inline bool f_pred(int x,int y) {
    return (tin[x]<=tin[y] && tout[x]>=tout[y]);
}

int get_lca(int x,int y) {
    if (f_pred(x,y)) return x;
    else if (f_pred(y,x)) return y;
    for (int i=17;i>=0;--i)
        if (dp[x][i] && f_pred(dp[x][i],y)==false) x=dp[x][i];
    return dp[x][0];
}

inline void push(int x,int l,int r) {
    ob[x+x]+=ob[x];
    ob[x+x+1]+=ob[x];
    int mid=(l+r)>>1;
    t[x+x]+=1ll*(mid-l+1)*ob[x];
    t[x+x+1]+=1ll*(r-mid)*ob[x];
    ob[x]=0;
}

void update(int l,int r,int ll,int rr,int x,int y) {
    if (l>r || ll>r || l>rr) return;
    if (l>=ll && r<=rr) {
        ob[x]+=y;
        t[x]+=1ll*(r-l+1)*y;
        return;
    }
    int mid=(l+r)>>1;
    if (ob[x]) push(x,l,r);
    update(l,mid,ll,rr,x+x,y);
    update(mid+1,r,ll,rr,x+x+1,y);
    t[x]=t[x+x]+t[x+x+1];
}

long long get(int l,int r,int ll,int rr,int x) {
    if (l>r || ll>r || l>rr) return 0;
    if (l>=ll && r<=rr) return t[x];
    int mid=(l+r)>>1;
    if (ob[x]) push(x,l,r);
    return get(l,mid,ll,rr,x+x)+get(mid+1,r,ll,rr,x+x+1);
}

int get_len(int x,int y) {
    if (depth[x]>depth[y]) swap(x,y);
    if (f_pred(x,y)) return depth[y]-depth[x];
    int c=get_lca(x,y);
    return depth[x]+depth[y]-(2*depth[c]);
}

int get_new_pred(int x,int y) {
    for (int i=17;i>=0;--i)
        if (dp[y][i] && !f_pred(dp[y][i],x)) y=dp[y][i];
    return y;
}

inline void update_q(int x,int y,int z) {
    if (depth[x]>depth[y]) swap(x,y);
    int c=get_lca(x,y);
    if (!f_pred(c,lastroot)) {
        update(1,sz,tin[c],tout[c],1,z);
        return;
    }
    if (get_len(x,lastroot)+get_len(lastroot,y)==get_len(x,y)) {
        update(1,sz,1,n,1,z);
        return;
    }
    update(1,sz,1,n,1,z);
    int c1=get_lca(x,lastroot);
    int h1=depth[lastroot]-depth[c1];
    int c2=get_lca(y,lastroot);
    int h2=depth[lastroot]-depth[c2];
    if (h1>h2)swap(c1,c2);
    c=get_new_pred(c1,lastroot);
    update(1,sz,tin[c],tout[c],1,-z);
}

inline long long get_res(int x) {
    if (x==lastroot) return get(1,sz,1,sz,1);
    if (!f_pred(x,lastroot)) return get(1,sz,tin[x],tout[x],1);
    int c=get_new_pred(x,lastroot);
    return get(1,sz,1,sz,1)-get(1,sz,tin[c],tout[c],1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i) {
        t[sz+i-1]=a[poc[i]];
    }
    for (int i=sz-1;i>0;--i)
        t[i]=(t[i+i]+t[i+i+1]);
    lastroot=1;
    int tp,x,y,z;
    while (m--) {
        cin>>tp;
        if (tp==1) {
            cin>>x;
            lastroot=x;
            continue;
        } else if (tp==2) {
            cin>>x>>y>>z;
            update_q(x,y,z);
        } else {
            cin>>x;
            cout<<get_res(x)<<'\n';
        }
    }
}