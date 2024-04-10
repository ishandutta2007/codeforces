#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;
typedef array<array<int,2>,2> mat;

const int N=100005;
const ll mod=1000000007;
const int D=2;
mat zero={array<int,2>{0,0},array<int,2>{0,0}};
mat id={array<int,2>{1,0},array<int,2>{0,1}};
mat f={array<int,2>{1,1},array<int,2>{1,0}};
vector<array<int,2>> tree(4*N,{0,0});
vector<ll> lazy(4*N,0);
vector<int> val(N,0);
vector<mat> p(47,zero);

array<int,2> operator+(const array<int,2> &a,const array<int,2> &b)
{
    array<int,2> c={0,0};
    for(int i=0;i<2;i++) c[i]=(a[i]+b[i])%mod;
    return c;
}

mat operator*(const mat &a,const mat &b)
{
    mat c=zero;
    for(int i=0;i<D;i++) for(int j=0;j<D;j++) for(int k=0;k<D;k++) c[i][k]=(c[i][k]+(ll)a[i][j]*b[j][k])%mod;
    return c;
}

mat fpow(ll e)
{
    mat res=id;
    for(int i=0;i<47;i++) if(e&(1ll<<i)) res=res*p[i];
    return res;
}

ll fib(ll a,ll b,ll n)
{
    if(n==1) return a;
    mat m=fpow(n-2);
    return (b*m[0][0]+a*m[0][1])%mod;
}

void build(int idx,int l,int r)
{
    if(l==r)
    {
        tree[idx][0]=fib(0,1,val[l]);
        tree[idx][1]=fib(0,1,val[l]+1);
    }
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

void push(int idx)
{
    if(lazy[idx]==0) return;
    for(int i=0;i<2;i++)
    {
        auto [a,b]=tree[2*idx+i];
        tree[2*idx+i][0]=fib(a,b,lazy[idx]+1);
        tree[2*idx+i][1]=fib(a,b,lazy[idx]+2);
        lazy[2*idx+i]+=lazy[idx];
    }
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,int x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        auto [a,b]=tree[idx];
        tree[idx][0]=fib(a,b,x+1);
        tree[idx][1]=fib(a,b,x+2);
        lazy[idx]+=x;
    }
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),x);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx][1];
    int m=(l+r)/2;
    push(idx);
    return (query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr))%mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[0]=f;
    for(int i=1;i<47;i++) p[i]=p[i-1]*p[i-1];
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> val[i];
    build(1,1,n);
    while(m--)
    {
        int t,l,r;
        cin >> t >> l >> r;
        if(t==1)
        {
            int x;
            cin >> x;
            update(1,1,n,l,r,x);
        }
        else cout << query(1,1,n,l,r) << "\n";
    }
    return 0;
}