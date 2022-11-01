#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct ST
{
    int n;
    vector<ll> tree;
    vector<ll> lazy;
    void ini(int _n)
    {
        n=_n;
        tree.assign(4*n,0);
        lazy.assign(4*n,0);
        build(1,1,n);
    }
    void pull(int idx){tree[idx]=tree[2*idx]+tree[2*idx+1];}
    void build(int idx,int l,int r)
    {
        if(l==r) tree[idx]=1;
        else
        {
            int m=(l+r)/2;
            build(2*idx,l,m);
            build(2*idx+1,m+1,r);
            pull(idx);
        }
    }
    void apply(int idx,int l,int r,int x)
    {
        tree[idx]+=(ll(r-l+1)*x);
        lazy[idx]+=x;
    }
    void push(int idx,int l,int r,int m)
    {
        apply(2*idx,l,m,lazy[idx]);
        apply(2*idx+1,m+1,r,lazy[idx]);
        lazy[idx]=0;
    }
    void update(int idx,int l,int r,int ql,int qr,int x)
    {
        if(ql>qr) return;
        if(l==ql&&r==qr) apply(idx,l,r,x);
        else
        {
            int m=(l+r)/2;
            push(idx,l,r,m);
            update(2*idx,l,m,ql,min(qr,m),x);
            update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
            pull(idx);
        }
    }
    ll query(int idx,int l,int r,int ql,int qr)
    {
        if(ql>qr) return 0;
        if(l==ql&&r==qr) return tree[idx];
        int m=(l+r)/2;
        push(idx,l,r,m);
        return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
    }
    void upd(int ql,int qr,int x){update(1,1,n,ql,qr,x);}
    ll qry(int ql,int qr){return query(1,1,n,ql,qr);}
};

ST st;
const int inf=(1<<30);

struct obj
{
    int mx,smx,cnt;
    void ini(int a)
    {
        mx=a;
        cnt=1;
        smx=-inf;
    }
    void pull(obj &a,obj &b)
    {
        mx=max(a.mx,b.mx);
        cnt=((a.mx==mx)*a.cnt+(b.mx==mx)*b.cnt);
        smx=-inf;
        for(int t:{a.mx,a.smx,b.mx,b.smx}) if(t<mx) smx=max(smx,t);
    }
};

struct STBeats
{
    int n;
    vector<obj> tree;
    STBeats(int _n)
    {
        n=_n;
        tree.resize(4*n);
        build(1,1,n);
    }
    void pull(int idx){tree[idx].pull(tree[2*idx],tree[2*idx+1]);}
    void build(int idx,int l,int r)
    {
        if(l==r) tree[idx].ini(l);
        else
        {
            int m=(l+r)/2;
            build(2*idx,l,m);
            build(2*idx+1,m+1,r);
            pull(idx);
        }
    }
    void apply(int idx,int x){tree[idx].mx=min(tree[idx].mx,x);}
    void push(int idx)
    {
        for(int i=0;i<2;i++) apply(2*idx+i,tree[idx].mx);
    }
    void update(int idx,int l,int r,int ql,int qr,int x)
    {
        if(ql>qr||tree[idx].mx<=x) return;
        if(l==ql&&r==qr&&tree[idx].smx<x&&x<tree[idx].mx)
        {
            st.upd(x+1,tree[idx].mx,-tree[idx].cnt);
            tree[idx].mx=x;
        }
        else
        {
            int m=(l+r)/2;
            push(idx);
            update(2*idx,l,m,ql,min(qr,m),x);
            update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
            pull(idx);
        }
    }
    void update_one(int idx,int l,int r,int pos,int x)
    {
        if(l==r) tree[idx].ini(x);
        else
        {
            int m=(l+r)/2;
            push(idx);
            if(pos<=m) update_one(2*idx,l,m,pos,x);
            else update_one(2*idx+1,m+1,r,pos,x);
            pull(idx);
        }
    }
    void upd(int ql,int qr,int x){update(1,1,n,ql,qr,x);}
    void upd_one(int pos,int x){update_one(1,1,n,pos,x);}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    st.ini(n);
    STBeats beets(n); //Dwight's preferred spelling
    while(q--)
    {
        int t,l,r;
        cin >> t >> l >> r;
        if(t==1)
        {
            beets.upd(1,l,l-1);
            beets.upd_one(l,r);
            st.upd(l,r,1);
        }
        else cout << st.qry(l,r) << "\n";
    }
    return 0;
}