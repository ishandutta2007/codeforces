#include <bits/stdc++.h>

using namespace std;

const int N=100005;
int tree[4*N][20];
bool lazy[4*N][20];
int a[N];

void build(int idx,int l,int r)
{
    if(l==r)
    {
        for(int j=0;j<20;j++) tree[idx][j]=((a[l]>>j)&1);
    }
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        for(int j=0;j<20;j++) tree[idx][j]=tree[2*idx][j]+tree[2*idx+1][j];
    }
}

void push(int idx,int l,int r)
{
    for(int x=0;x<20;x++)
    {
        if(lazy[idx][x]==0) continue;
        int m=(l+r)/2;
        tree[2*idx][x]=(m-l+1)-tree[2*idx][x];
        tree[2*idx+1][x]=(r-(m+1)+1)-tree[2*idx+1][x];
        lazy[2*idx][x]^=1;
        lazy[2*idx+1][x]^=1;
        lazy[idx][x]=0;
    }

}

void update(int idx,int l,int r,int ql,int qr,int val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        for(int j=0;j<20;j++)
        {
            if((val&(1<<j))==0) continue;
            tree[idx][j]=(r-l+1)-tree[idx][j];
            lazy[idx][j]^=1;
        }
    }
    else
    {
        push(idx,l,r);
        int m=(l+r)/2;
        update(2*idx,l,m,ql,min(qr,m),val);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,val);
        for(int j=0;j<20;j++) tree[idx][j]=tree[2*idx][j]+tree[2*idx+1][j];
    }
}

long long query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr)
    {
        long long res=0;
        for(int j=0;j<20;j++) res+=((1ll<<j)*tree[idx][j]);
        return res;
    }
    push(idx,l,r);
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        if(t==1) printf("%I64d\n",query(1,1,n,l,r));
        else
        {
            int x;
            scanf("%d",&x);
            update(1,1,n,l,r,x);
        }
    }
    return 0;
}