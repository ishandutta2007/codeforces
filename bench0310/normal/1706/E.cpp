#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<array<int,2>> mn(4*N);
vector<array<int,2>> mx(4*N);
vector<array<int,2>> val(N);

void build(int idx,int l,int r)
{
    if(l==r) mn[idx]=mx[idx]=val[l];
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        mn[idx]=min(mn[2*idx],mn[2*idx+1]);
        mx[idx]=max(mx[2*idx],mx[2*idx+1]);
    }
}

array<int,2> query(int idx,int l,int r,int ql,int qr,int t)
{
    if(ql>qr) return {t==0?(1<<30):0,0};
    if(l==ql&&r==qr) return (t==0?mn[idx]:mx[idx]);
    int m=(l+r)/2;
    array<int,2> one=query(2*idx,l,m,ql,min(qr,m),t);
    array<int,2> two=query(2*idx+1,m+1,r,max(ql,m+1),qr,t);
    if(t==0) return min(one,two);
    else return max(one,two);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,q;
        cin >> n >> m >> q;
        vector<int> v[n+m+1];
        vector<int> p(n+m+1,0);
        for(int i=1;i<=n+m;i++) p[i]=i;
        function<int(int)> find_set=[&](int a)->int
        {
            if(a==p[a]) return a;
            else return p[a]=find_set(p[a]);
        };
        int e=0;
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin >> a >> b;
            a=find_set(a);
            b=find_set(b);
            if(a!=b)
            {
                p[a]=p[b]=n+i;
                v[n+i].push_back(a);
                v[n+i].push_back(b);
                e=i;
            }
        }
        vector<int> depth(n+m+1,0);
        vector<int> tin(n+m+1,0);
        int tcnt=0;
        vector<array<int,19>> u(n+m+1);
        for(int i=0;i<=n+m;i++) u[i].fill(0);
        function<void(int)> dfs=[&](int a)
        {
            depth[a]=depth[u[a][0]]+1;
            tin[a]=(++tcnt);
            for(int i=1;i<19;i++) u[a][i]=u[u[a][i-1]][i-1];
            for(int to:v[a])
            {
                u[to][0]=a;
                dfs(to);
            }
        };
        dfs(n+e);
        for(int i=1;i<=n;i++) val[i]={tin[i],i};
        build(1,1,n);
        auto lca=[&](int a,int b)->int
        {
            if(depth[a]>depth[b]) swap(a,b);
            for(int i=18;i>=0;i--) if(depth[u[b][i]]>=depth[a]) b=u[b][i];
            if(a==b) return a;
            for(int i=18;i>=0;i--) if(u[a][i]!=u[b][i]) tie(a,b)={u[a][i],u[b][i]};
            return u[a][0];
        };
        for(int i=1;i<=q;i++)
        {
            int l,r;
            cin >> l >> r;
            int a=query(1,1,n,l,r,0)[1];
            int b=query(1,1,n,l,r,1)[1];
            cout << (a!=b?lca(a,b)-n:0) << " \n"[i==q];
        }
    }
    return 0;
}