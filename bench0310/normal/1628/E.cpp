#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300005;
function<int(int,int)> path;
vector<int> opt(N,-1);

struct obj
{
    int l,r;
    int c,a,b;
    int mx,full_mx;
    int lazy;
    array<int,3> old;
    void ini(int _l,int _r){l=_l;r=_r;a=b=c=0;mx=full_mx=-1;lazy=-1;old={-1,-1,-1};}
    void pull(obj &x,obj &y)
    {
        c=x.c+y.c;
        a=(x.c>0?x.a:y.a);
        b=(y.c>0?y.b:x.b);
        mx=max(x.mx,y.mx);
        if(x.c>0&&y.c>0)
        {
            auto &[ox,oy,val]=old;
            if(ox!=x.b||oy!=y.a) old={x.b,y.a,path(x.b,y.a)};
            mx=max(mx,val);
        }
    }
    void apply(int t)
    {
        if(t==0)
        {
            mx=-1;
            c=0;
        }
        else
        {
            mx=full_mx;
            c=r-l+1;
            a=l; b=r;
        }
        lazy=t;
    }
    void push(obj &x,obj &y)
    {
        if(lazy!=-1)
        {
            x.apply(lazy);
            y.apply(lazy);
            lazy=-1;
        }
    }
};

vector<obj> tree(4*N);

void pull(int idx){tree[idx].pull(tree[2*idx],tree[2*idx+1]);}
void apply(int idx,int t){tree[idx].apply(t);}
void push(int idx){tree[idx].push(tree[2*idx],tree[2*idx+1]);}

void build(int idx,int l,int r)
{
    tree[idx].ini(l,r);
    if(l<r)
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx].full_mx=max({tree[2*idx].full_mx,tree[2*idx+1].full_mx,path(m,m+1)});
    }
}

void update(int idx,int l,int r,int ql,int qr,int t)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) apply(idx,t);
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),t);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,t);
        pull(idx);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<array<int,2>> v[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    vector<array<int,19>> p(n+1),mx(n+1);
    vector<int> depth(n+1,0);
    for(int i=0;i<=n;i++)
    {
        p[i].fill(0);
        mx[i].fill(-1);
    }
    function<void(int)> dfs=[&](int a)
    {
        depth[a]=depth[p[a][0]]+1;
        for(int i=1;i<19;i++)
        {
            p[a][i]=p[p[a][i-1]][i-1];
            mx[a][i]=max(mx[a][i-1],mx[p[a][i-1]][i-1]);
        }
        for(auto [to,c]:v[a])
        {
            if(to==p[a][0]) continue;
            p[to][0]=a;
            mx[to][0]=c;
            dfs(to);
        }
    };
    dfs(1);
    path=[&](int a,int b)
    {
        if(a+1==b&&opt[a]!=-1) return opt[a];
        if(a==b) return -1;
        if(depth[a]>depth[b]) swap(a,b);
        int m=-1;
        for(int i=18;i>=0;i--) if(depth[p[b][i]]>=depth[a]) {m=max(m,mx[b][i]);b=p[b][i];}
        if(a==b) return m;
        for(int i=18;i>=0;i--) if(p[a][i]!=p[b][i]) {m=max({m,mx[a][i],mx[b][i]});tie(a,b)={p[a][i],p[b][i]};}
        return max({m,mx[a][0],mx[b][0]});
    };
    for(int i=1;i<n;i++) opt[i]=path(i,i+1);
    build(1,1,n);
    //every update does at most two calls to path, so O(n log n)
    while(q--)
    {
        int t;
        cin >> t;
        if(t<=2)
        {
            int l,r;
            cin >> l >> r;
            update(1,1,n,l,r,t&1);
        }
        else
        {
            int a;
            cin >> a;
            int res=tree[1].mx;
            if(tree[1].c>0) res=max(res,path(a,tree[1].a));
            cout << res << "\n";
        }
    }
    return 0;
}