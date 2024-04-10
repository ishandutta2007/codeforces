#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
int n;
vector<ll> tree(4*N,0);

void update(int idx,int l,int r,int pos,ll val)
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

void upd(int pos,ll val)
{
    update(1,1,n,pos,val);
}

ll qry(int pos)
{
    return query(1,1,n,1,pos);
}

ll eval(ll a)
{
    if(a>=0) return (a+1)/2;
    else return a/2;
}

ll getb(int i)
{
    return max(0ll,qry(i)-qry(i-1));
}

ll getc(int i)
{
    return min(0ll,qry(i)-qry(i-1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        upd(i,a);
        if(i+1<=n) upd(i+1,-a);
    }
    ll bx=0;
    ll cx=0;
    for(int i=2;i<=n;i++)
    {
        bx+=getb(i);
        cx+=getc(i);
    }
    cout << max(eval(bx+qry(1)),eval(qry(n)-cx)) << "\n";
    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        ll x;
        cin >> l >> r >> x;
        if(l>1)
        {
            bx-=getb(l);
            cx-=getc(l);
        }
        if(r<n)
        {
            bx-=getb(r+1);
            cx-=getc(r+1);
        }
        upd(l,x);
        if(r+1<=n) upd(r+1,-x);
        if(l>1)
        {
            bx+=getb(l);
            cx+=getc(l);
        }
        if(r<n)
        {
            bx+=getb(r+1);
            cx+=getc(r+1);
        }
        cout << max(eval(bx+qry(1)),eval(qry(n)-cx)) << "\n";
    }
    return 0;
}