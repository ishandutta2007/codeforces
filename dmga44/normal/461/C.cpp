#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

typedef ll T;

mt19937 rng(time(0));
struct node{
    node *l,*r;
    int sz,prior;
    bool rev;
    T v;
    ll sum;
    node(T v) : v(v),l(0),r(0),sz(1),prior(rng()),sum(v) {}
};
typedef node* pnode;

//template<typename T>
struct treap
{
    pnode root;
    treap() : root(0) {}

    int sz(pnode p) { return p ? p->sz : 0; }
    int size() {return sz(root);}
    int sum(pnode p)
    {
        if(p)
        {
            push(p);
            return p->sum;
        }
        return 0;
    }

    void update(pnode p)
    {
        if(!p)
            return ;
        p->sz=1+sz(p->l)+sz(p->r);
        p->sum=(p->v+sum(p->l)+sum(p->r));
    }

    void push(pnode p)
    {
        if(!p)
            return ;
        if(p->rev)
        {
            swap(p->l,p->r);
            if(p->l)
                p->l->rev^=1;
            if(p->r)
                p->r->rev^=1;
            p->rev=0;
        }
    }

    void split(pnode p,int key,pnode &l,pnode &r)
    {
        push(p);
        if(!p)
        {
            l=r=0;
            return ;
        }
        int cur_pos=sz(p->l);
        if(key<=cur_pos)
        {
            split(p->l,key,l,p->l);
            r=p;
        }
        else
        {
            split(p->r,key-cur_pos-1,p->r,r);
            l=p;
        }
        update(p);
    }

    void merge(pnode &p,pnode l,pnode r)
    {
        push(l);
        push(r);
        if(!l || !r)
        {
            if(l)
                p=l;
            else
                p=r;
        }
        else if(l->prior>r->prior)
        {
            merge(l->r,l->r,r);
            p=l;
        }
        else
        {
            merge(r->l,l,r->l);
            p=r;
        }
        update(p);
    }

    ///0 means at the begining of the treap(array)
    void insert(T v,int pos)
    {
        pos=max(0,pos);
        pos=min(sz(root),pos);
        pnode it=new node(v);
        pnode l,r;
        split(root,pos,l,r);
        merge(l,l,it);
        merge(root,l,r);
    }

    void insert(pnode it,int pos)
    {
        pnode l,r;
        split(root,pos,l,r);
        merge(l,l,it);
        merge(root,l,r);
    }

    void erase(int pos) { erase_interval(pos,pos); }

    void erase_interval(int l,int r)
    {
        if(l>r)
            swap(l,r);
        if(l<=0 || r>sz(root))
            return ;

        pnode pl,pr,_discard;
        split(root,l-1,pl,pr);
        split(pr,r-l+1,_discard,pr);
        merge(root,pl,pr);
    }

    void reverse(int l,int r)
    {
        pnode l1,r1,m;
        split(root,l-1,l1,r1);
        split(r1,r-l+1,m,r1);
        m->rev^=1;
        merge(r1,m,r1);
        merge(root,l1,r1);
    }

    ///intervals have to be disjoint and non-empty
    ///(both ends inclusive: [l1,r1]->[l2,r2])
    void swap_intervals(int l1,int r1,int l2,int r2)
    {
        if(l1>l2)
        {
            swap(l1,l2);
            swap(r1,r2);
        }
        pnode i1,i2;
        pnode m1,m2,m3;

        split(root,l1-1,m1,i1);
        split(i1,r1-l1+1,i1,m2);
        split(m2,l2-r1-1,m2,i2);
        split(i2,r2-l2+1,i2,m3);

        merge(m1,m1,i2);
        merge(m1,m1,m2);
        merge(m3,i1,m3);
        merge(root,m1,m3);
    }

    ///position has to exist(1<=i<=sz(root))
    T operator[](int i)
    {
        assert(1<=i && i<=sz(root));
        return find_kth(root,i)->v;
    }

    void assign(T v,int pos)
    {
        pnode p=find_kth(root,pos);
        p->v=v;
    }

    pnode find_kth(pnode p,int k)
    {
        push(p);
        if(sz(p->l)<k-1)
            return find_kth(p->r,k-sz(p->l)-1);
        else if(sz(p->l)==k-1)
            return p;
        return find_kth(p->l,k);
    }

    void find_kth_add(pnode p,int k,int x)
    {
        push(p);
        if(sz(p->l)<k-1)
        {
            find_kth_add(p->r,k-sz(p->l)-1,x);
            update(p);
            return;
        }
        else if(sz(p->l)==k-1)
        {
            p->v+=x;
            update(p);
            return;
        }
        find_kth_add(p->l,k,x);
        update(p);
    }

    ll query(int l,int r)
    {
        pnode li,mi,ri;
        split(root,l-1,li,mi);
        split(mi,r-l+1,mi,ri);
        push(mi);
        ll res=mi->sum;
        merge(mi,mi,ri);
        merge(root,li,mi);
        return res;
    }

    void fold(int p)
    {
        int szl=p,szr=size()-p;
        if(szl<szr)
        {
            vector<int> vs;
            for(int i=1;i<=p;i++)
                vs.push_back(find_kth(root,i)->v);
            pnode _,nr;
            split(root,p,_,nr);
            root=nr;
            for(int i=1;i<=p;i++)
                find_kth_add(root,i,vs[p-i]);
        }
        else
        {
            root->rev^=1;
            p=size()-p;

            vector<int> vs;
            for(int i=1;i<=p;i++)
                vs.push_back(find_kth(root,i)->v);
            pnode _,nr;
            split(root,p,_,nr);
            root=nr;
            for(int i=1;i<=p;i++)
                find_kth_add(root,i,vs[p-i]);
        }
    }

    void imp(pnode p)
    {
        if(!p)
            return ;
        imp(p->l);
        cout << p->v << ' ' << p->sum << ' ' << p->sz << '\n';
        imp(p->r);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    treap t;
    for(int i=0;i<n;i++)
        t.insert(1,i);

//    t.imp(t.root);
    for(int i=0;i<q;i++)
    {
        int ty;
        cin >> ty;
        if(ty==1)
        {
            int p;
            cin >> p;
            t.fold(p);
        }
        else
        {
            int l,r;
            cin >> l >> r;
            l++;
            db(t.query(l,r))
        }
//        db("xxx")
//        db(i)
//        t.imp(t.root);
    }

    return 0;
}