#include <bits/stdc++.h>

using namespace std;

const int N=200005;
vector<int> v[N];
vector<int> depth(N,0);
vector<int> tin(N,0);
vector<int> tout(N,0);
vector<int> h(N,0); //tin->a
int tcnt=1;
vector<int> tree(4*N,0);
vector<array<int,2>> lazy(4*N,{0,0});

int upd(int a,int t,int val)
{
    if(((depth[a]-t)%2)==0) return val;
    else return -val;
}

void push(int idx,int l,int r,int m)
{
    for(int t=0;t<=1;t++)
    {
        if(l==m) tree[2*idx]+=upd(h[l],t,lazy[idx][t]);
        if(m+1==r) tree[2*idx+1]+=upd(h[r],t,lazy[idx][t]);
        lazy[2*idx][t]+=lazy[idx][t];
        lazy[2*idx+1][t]+=lazy[idx][t];
        lazy[idx][t]=0;
    }
}

void update(int idx,int l,int r,int ql,int qr,int t,int val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        if(l==r) tree[idx]+=upd(h[l],t,val);
        lazy[idx][t]+=val;
    }
    else
    {
        int m=(l+r)/2;
        push(idx,l,r,m);
        update(2*idx,l,m,ql,min(qr,m),t,val);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,t,val);
    }
}

int query(int idx,int l,int r,int pos)
{
    if(l==r) return tree[idx];
    int m=(l+r)/2;
    push(idx,l,r,m);
    if(pos<=m) return query(2*idx,l,m,pos);
    else return query(2*idx+1,m+1,r,pos);
}

void dfs(int a,int p=0)
{
    depth[a]=depth[p]+1;
    h[tcnt]=a;
    tin[a]=tcnt++;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
    }
    tout[a]=tcnt-1;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> x(n+1,0);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    while(m--)
    {
        int t,a;
        scanf("%d%d",&t,&a);
        if(t==1)
        {
            int val;
            scanf("%d",&val);
            update(1,1,n,tin[a],tout[a],depth[a]&1,val);
        }
        else printf("%d\n",x[a]+query(1,1,n,tin[a]));
    }
    return 0;
}