#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
int n;
vector<ll> tree(4*N,0);
vector<int> mx(4*N,0);
vector<int> id(4*N,0);
vector<int> val(N,0);

void build(int idx,int l,int r)
{
    if(l==r)
    {
        tree[idx]=mx[idx]=val[l];
        id[idx]=l;
    }
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
        mx[idx]=max(mx[2*idx],mx[2*idx+1]);
        if(mx[2*idx]>=mx[2*idx+1]) id[idx]=id[2*idx];
        else id[idx]=id[2*idx+1];
    }
}

array<int,2> descend(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return {0,0};
    if(l==ql&&r==qr) return {mx[idx],id[idx]};
    int m=(l+r)/2;
    return max(descend(2*idx,l,m,ql,min(qr,m)),descend(2*idx+1,m+1,r,max(ql,m+1),qr));
}

void update(int idx,int l,int r,int pos,ll x)
{
    if(l==r) tree[idx]=mx[idx]=x;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,x);
        else update(2*idx+1,m+1,r,pos,x);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
        mx[idx]=max(mx[2*idx],mx[2*idx+1]);
        if(mx[2*idx]>=mx[2*idx+1]) id[idx]=id[2*idx];
        else id[idx]=id[2*idx+1];
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
    int m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> val[i];
    build(1,1,n);
    while(m--)
    {
        int t;
        cin >> t;
        if(t==1||t==2)
        {
            int l,r;
            cin >> l >> r;
            if(t==1) cout << query(1,1,n,l,r) << "\n";
            else
            {
                int x;
                cin >> x;
                array<int,2> a;
                while((a=descend(1,1,n,l,r))[0]>=x) update(1,1,n,a[1],a[0]%x);
            }
        }
        else
        {
            int k,x;
            cin >> k >> x;
            update(1,1,n,k,x);
        }
    }
    return 0;
}