#include <bits/stdc++.h>
using namespace std;



pair<int,pair<int,int> > b[500005];
int n,m,k;
vector<int> v1,v2;
vector<int> v[500005];
int tin[500005];
int tin2[1000005];
bool used2[500005];
int timer,all;
int tout[500005];
int dp[500005][20];
int p[500005];
int poc[1000005];
vector<int> q1[500005];
vector<int> q2[500005];
int ans[500005];

int get(int x) {
    if (x==p[x]) return x;
    return p[x]=get(p[x]);
}

inline void add_path(int x,int y,int z) {
    if (x==y) return;
    ++all;
    poc[all]=z;
    q1[y].push_back(all);
    q2[x].push_back(all);
}

void dfs(int x,int y) {
    tin[x]=++timer;
    dp[x][0]=y;
    for (int i=1;i<=19;++i)
        dp[x][i]=dp[dp[x][i-1]][i-1];
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to!=y) dfs(to,x);
    }
    tout[x]=timer;
}

inline bool f_pred(int x,int y) {
    return (tin[x]<=tin[y] && tout[x]>=tout[y]);
}

inline int get_lca(int x,int y) {
    if (f_pred(x,y)) return x;
    if (f_pred(y,x)) return y;
    for (int i=19;i>=0;--i)
        if (dp[x][i] && !f_pred(dp[x][i],y)) x=dp[x][i];
    return dp[x][0];
}

void dfs2(int x,int y) {
    tin[x]=++timer;
    for (int i=0;i<q1[x].size();++i) {
        int to=q1[x][i];
        tin2[to]=++timer;
    }
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to!=y) dfs2(to,x);
    }
    tout[x]=timer;
}


int sz;
int t[5000005];

void update(int x,int y) {
    x+=sz-1;
    t[x]=y;
    x>>=1;
    while (x) {
        t[x]=t[x+x];
        if (t[x+x+1]<t[x]) t[x]=t[x+x+1];
        x>>=1;
    }
}

int get(int l,int r,int ll,int rr,int x) {
    if (l>r || ll>r || l>rr || ll>rr) return 2e9;
    if (l>=ll && r<=rr) return t[x];
    int mid=(l+r)>>1;
    return min(get(l,mid,ll,rr,x+x),get(mid+1,r,ll,rr,x+x+1));
}

void solve(int x,int y) {
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to!=y) solve(to,x);
    }
    for (int i=0;i<q1[x].size();++i) {
        int to=q1[x][i];
        update(tin2[to],poc[to]);
    }
    for (int i=0;i<q2[x].size();++i) {
        int to=q2[x][i];
        update(tin2[to],2e9);
    }
    ans[x]=get(1,sz,tin[x],tout[x],1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i)
        p[i]=i;
    int x,y;
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        x=get(x);
        y=get(y);
        p[x]=y;
    }
    for (int i=1;i<=k;++i) {
        cin>>b[i].second.first>>b[i].second.second>>b[i].first;
    }
    sort(b+1,b+k+1);
    for (int i=1;i<=k;++i) {
        x=b[i].second.first;
        y=b[i].second.second;
        x=get(x);
        y=get(y);
        if (x==y) {
            v2.push_back(i);
        } else {
            v1.push_back(i);
            p[x]=y;
            x=b[i].second.first;
            y=b[i].second.second;
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }
    dfs(1,0);
    int xx,yy,zz;
    for (int i=0;i<v2.size();++i) {
        x=v2[i];
        xx=b[x].second.first;
        yy=b[x].second.second;
        zz=get_lca(xx,yy);
        add_path(zz,xx,b[x].first);
        add_path(zz,yy,b[x].first);
    }
    timer=0;
    dfs2(1,0);
    sz=1;
    while (sz<timer) sz+=sz;
    for (int i=1;i<=sz+sz;++i)
        t[i]=2e9;
    solve(1,0);
    for (int i=0;i<v1.size();++i) {
        x=v1[i];
        xx=b[x].second.first;
        yy=b[x].second.second;
        if (tin[xx]>tin[yy]) swap(xx,yy);
        used2[yy]=true;
    }
    long long res=0;
    for (int i=2;i<=n;++i)
    if (used2[i]==false && ans[i]>1e9) {
        cout<<"-1";
        return 0;
    } else if (used2[i]==false) res+=ans[i];
    cout<<res;
}