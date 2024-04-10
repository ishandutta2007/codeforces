#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<array<ll,2>,2> mat;

const ll mod=1000000009;
const int D=2;
mat zero={array<ll,2>{0,0},array<ll,2>{0,0}};
const int N=300005;
vector<mat> p(N,zero);
vector<int> val(N,0);
vector<ll> tree(4*N,0);
vector<array<ll,2>> lazy(4*N,{0,0});

mat operator*(const mat &a,const mat &b)
{
    mat c=zero;
    for(int i=0;i<D;i++) for(int j=0;j<D;j++) for(int k=0;k<D;k++) c[i][k]=(c[i][k]+a[i][j]*b[j][k])%mod;
    return c;
}

ll fib(ll a,ll b,ll n)
{
    if(n==1) return a;
    else return (b*p[n-2][0][0]+a*p[n-2][0][1])%mod;
}

ll sum(ll a,ll b,ll n)
{
    return (fib(a,b,n+2)-b+mod)%mod;
}

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=val[l];
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=(tree[2*idx]+tree[2*idx+1])%mod;
    }
}

void push(int idx,int l,int r,int m)
{
    auto [a,b]=lazy[idx];
    tree[2*idx]=(tree[2*idx]+sum(a,b,m-l+1));
    lazy[2*idx][0]=(lazy[2*idx][0]+a)%mod;
    lazy[2*idx][1]=(lazy[2*idx][1]+b)%mod;
    ll c=fib(a,b,m+1-l+1);
    ll d=fib(a,b,m+1-l+2);
    tree[2*idx+1]=(tree[2*idx+1]+sum(c,d,r-(m+1)+1));
    lazy[2*idx+1][0]=(lazy[2*idx+1][0]+c)%mod;
    lazy[2*idx+1][1]=(lazy[2*idx+1][1]+d)%mod;
    lazy[idx]={0,0};
}

void update(int idx,int l,int r,int ql,int qr,ll a,ll b)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]=(tree[idx]+sum(a,b,r-l+1))%mod;
        lazy[idx][0]=(lazy[idx][0]+a)%mod;
        lazy[idx][1]=(lazy[idx][1]+b)%mod;
    }
    else
    {
        int m=(l+r)/2;
        push(idx,l,r,m);
        if(ql<=m)
        {
            update(2*idx,l,m,ql,min(qr,m),a,b);
            ll c=fib(a,b,m+1-ql+1);
            ll d=fib(a,b,m+1-ql+2);
            update(2*idx+1,m+1,r,max(ql,m+1),qr,c,d);
        }
        else update(2*idx+1,m+1,r,ql,qr,a,b);
        tree[idx]=(tree[2*idx]+tree[2*idx+1])%mod;
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    push(idx,l,r,m);
    return (query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr))%mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    mat f={array<ll,2>{1,1},array<ll,2>{1,0}};
    p[0][0][0]=p[0][1][1]=1;
    for(int i=1;i<N;i++) p[i]=f*p[i-1];
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> val[i];
    build(1,1,n);
    while(m--)
    {
        int t,l,r;
        cin >> t >> l >> r;
        if(t==1) update(1,1,n,l,r,1,1);
        else cout << query(1,1,n,l,r) << "\n";
    }
    return 0;
}