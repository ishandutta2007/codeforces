#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct obj
{
    int sz=0;
    int al=0,ar=0;
    int cl=0,cr=0;
    ll cnt=0;
    obj(int a){sz=1;al=ar=a;cl=cr=1;cnt=1;}
    friend obj operator+(const obj &a,const obj &b)
    {
        if(a.al==-1) return b;
        if(b.al==-1) return a;
        obj c(0);
        c.sz=a.sz+b.sz;
        c.al=a.al;
        c.ar=b.ar;
        c.cl=a.cl;
        c.cr=b.cr;
        c.cnt=a.cnt+b.cnt;
        if(a.ar<=b.al)
        {
            c.cnt+=(ll(a.cr)*b.cl);
            if(a.cl==a.sz) c.cl+=b.cl;
            if(b.cr==b.sz) c.cr+=a.cr;
        }
        return c;
    }
};

const int N=200005;
vector<obj> tree(4*N,obj(0));

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]=obj(val);
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

obj query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return obj(-1);
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        update(1,1,n,i,a);
    }
    while(q--)
    {
        int t,x,y;
        cin >> t >> x >> y;
        if(t==1) update(1,1,n,x,y);
        else cout << query(1,1,n,x,y).cnt << "\n";
    }
    return 0;
}