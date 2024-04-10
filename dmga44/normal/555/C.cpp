#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

struct node
{
    int lazy;
    int v;
    node *ls,*rs;
    node() : ls(0),rs(0),v(oo),lazy(oo) {}
};
typedef node* pnode;

struct implicit_st
{
    pnode root;
    int n;

    implicit_st(int _n) : n(_n){root=new node();}

    void app(pnode p,int v)
    {
        p->v=min(p->v,v);
        p->lazy=min(p->lazy,v);
    }

    void push(pnode p,int l,int r)
    {
        if(l==r || p->lazy==oo)
            return ;
        int v=p->lazy;
        int mid=(l+r)>>1;
        if(!(p->ls))
            p->ls=new node();
        if(!(p->rs))
            p->rs=new node();

        app(p->ls,v);
        app(p->rs,v+mid-l+1);
        p->lazy=oo;
    }

    void update(int l,int r,int  v) {update(root,0,n-1,l,r,v);}
    void update(pnode p,int l,int r,int L,int R,int v)
    {
        if(L<=l && r<=R)
        {
            app(p,v+l-L);
            return ;
        }
        push(p,l,r);

        int mid=(l+r)>>1;
        if(L<=mid)
        {
            if(!p->ls)
                p->ls=new node();
            update(p->ls,l,mid,L,R,v);
        }
        if(R>mid)
        {
            if(!p->rs)
                p->rs=new node();
            update(p->rs,mid+1,r,L,R,v);
        }
    }

    int query(int pos) {return query(root,0,n-1,pos);}
    int query(pnode p,int l,int r,int pos)
    {
        if(r==l && r==pos)
            return p->v;
        push(p,l,r);

        ll mid=(l+r)>>1;

        if(pos<=mid)
        {
            if(!p->ls)
                p->ls=new node();
            return query(p->ls,l,mid,pos);
        }
        if(pos>mid)
        {
            if(!p->rs)
                p->rs=new node();
            return query(p->rs,mid+1,r,pos);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    implicit_st stu(n);
    implicit_st stl(n);
    for(int i=0;i<q;i++)
    {
        int x,y;
        char ty;
        cin >> x >> y >> ty;
        if(ty=='U')
        {
            int res=min(y,stu.query(n-x));
            stu.update(n-x,n-x,0);
            if(res)
                stl.update(n-y,n-y+res-1,0);
            db(res)
        }
        else
        {
            int res=min(x,stl.query(n-y));
            stl.update(n-y,n-y,0);
            if(res)
                stu.update(n-x,n-x+res-1,0);
            db(res)
        }
    }

    return 0;
}
/**
6 5
3 4 U
6 1 L
2 5 L
1 6 U
4 3 U

10 6
2 9 U
10 1 U
1 10 U
8 3 L
10 1 L
6 5 U
**/