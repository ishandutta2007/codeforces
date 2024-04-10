#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
struct node
{
    ll best,l,r,sum;
    node(){best=0;l=0;r=0;sum=0;}
    node(ll a,ll b){best=0;l=a+2*b;r=2*b;sum=a;}
};
vector<ll> d(N,0);
vector<ll> h(N,0);
vector<node> tree(4*N,node());

node operator+(const node &a,const node &b)
{
    if(a.l==0) return b;
    if(b.l==0) return a;
    node c;
    c.best=max(max(a.best,b.best),a.l+b.r);
    c.l=max(b.l,a.l+b.sum);
    c.r=max(a.r,a.sum+b.r);
    c.sum=a.sum+b.sum;
    return c;
}

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=node(d[l],h[l]);
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

node query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return node();
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> d[i];
    for(int i=1;i<=n;i++) cin >> h[i];
    build(1,1,n);
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        if(a>b) cout << query(1,1,n,b+1,a-1).best << "\n";
        else cout << (query(1,1,n,b+1,n)+query(1,1,n,1,a-1)).best << "\n";
    }
    return 0;
}