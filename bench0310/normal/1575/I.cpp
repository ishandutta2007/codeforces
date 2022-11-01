#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<int> v[N];
vector<int> depth(N,0);
vector p(N,vector(17,0));
int tcnt=0;
vector<int> tin(N,0);
vector<int> tout(N,0);
vector<ll> tree(4*N,0);

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<17;i++) p[a][i]=p[p[a][i-1]][i-1];
    tin[a]=++tcnt;
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs(to);
    }
    tout[a]=tcnt;
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=16;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
    if(a==b) return a;
    for(int i=16;i>=0;i--) if(p[a][i]!=p[b][i]) tie(a,b)={p[a][i],p[b][i]};
    return p[a][0];
}

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]+=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        a[i]=abs(a[i]);
    }
    auto upd=[&](int x,int d)
    {
        update(1,1,n,tin[x],d);
        if(tout[x]<n) update(1,1,n,tout[x]+1,-d);
    };
    auto qry=[&](int x)->ll{return query(1,1,n,1,tin[x]);};
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++) upd(i,a[i]);
    while(q--)
    {
        int t,x,y;
        cin >> t >> x >> y;
        if(t==1)
        {
            y=abs(y);
            upd(x,y-a[x]);
            a[x]=y;
        }
        else
        {
            int l=lca(x,y);
            ll res=2*(qry(x)+qry(y)-qry(l)-qry(p[l][0]))-a[x]-a[y];
            if(x==y) res=0;
            cout << res << "\n";
        }
    }
    return 0;
}