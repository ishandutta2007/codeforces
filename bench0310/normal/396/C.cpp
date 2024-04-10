#include <bits/stdc++.h>

using namespace std;

const int N=300005;
const int mod=1000000007;
vector<int> v[N];
vector<array<int,2>> tree(4*N);
vector<array<int,2>> lazy(4*N);
vector<long long> depth(N,0);
vector<int> in(N,0);
vector<int> out(N,0);
int now=1;

void push(int idx)
{
    for(int i=0;i<2;i++)
    {
        tree[2*idx][i]=(tree[2*idx][i]+lazy[idx][i])%mod;
        lazy[2*idx][i]=(lazy[2*idx][i]+lazy[idx][i])%mod;
        tree[2*idx+1][i]=(tree[2*idx+1][i]+lazy[idx][i])%mod;
        lazy[2*idx+1][i]=(lazy[2*idx+1][i]+lazy[idx][i])%mod;
        lazy[idx][i]=0;
    }
}

void update(int idx,int l,int r,int ql,int qr,array<int,2> val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        for(int i=0;i<2;i++)
        {
            tree[idx][i]=(tree[idx][i]+val[i])%mod;
            lazy[idx][i]=(lazy[idx][i]+val[i])%mod;
        }
    }
    else
    {
        push(idx);
        int m=(l+r)/2;
        update(2*idx,l,m,ql,min(qr,m),val);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,val);
        for(int i=0;i<2;i++) tree[idx][i]=(tree[2*idx][i]+tree[2*idx+1][i])%mod;
    }
}

array<int,2> query(int idx,int l,int r,int pos)
{
    if(l==r) return tree[idx];
    push(idx);
    int m=(l+r)/2;
    if(pos<=m) return query(2*idx,l,m,pos);
    else return query(2*idx+1,m+1,r,pos);
}

void dfs(int a)
{
    in[a]=now++;
    for(int to:v[a])
    {
        depth[to]=depth[a]+1;
        dfs(to);
    }
    out[a]=now-1;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        v[p].push_back(i);
    }
    dfs(1);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int t,a;
        scanf("%d%d",&t,&a);
        if(t==1)
        {
            int x,k;
            scanf("%d%d",&x,&k);
            update(1,1,n,in[a],out[a],{-k,(int)((x+k*depth[a])%mod)});
        }
        else
        {
            auto [m,b]=query(1,1,n,in[a]);
            int res=(((depth[a]*m+b)%mod)+mod)%mod;
            printf("%d\n",res);
        }
    }
    return 0;
}