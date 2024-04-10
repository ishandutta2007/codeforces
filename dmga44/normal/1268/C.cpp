#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

typedef ll T;

mt19937 rng(time(0));
struct node{
    node *l,*r,*p;
    ll sz,prior;
    bool rev;
    T v;
    ll lazy,sum;
    node(T v) : v(v),l(0),r(0),sz(1),prior(rng()),sum(v),lazy(0),p(0) {}
};
typedef node* pnode;

//template<typename T>
struct treap
{
    pnode root;
    treap() : root(0) {}

    ll sz(pnode p) { return p ? p->sz : 0; }
    ll sum(pnode p)
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
        if(p->l)
            p->l->p=p;
        if(p->r)
            p->r->p=p;
        p->p=0;
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
        if(p->lazy)
        {
            p->v=(p->v+p->lazy);
            p->sum=p->sum+sz(p)*p->lazy;
            if(p->l)
                p->l->lazy=(p->l->lazy+p->lazy);
            if(p->r)
                p->r->lazy=(p->r->lazy+p->lazy);
            p->lazy=0;
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
    void insert(T v,ll pos)
    {
        pos=max(0ll,pos);
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

    void app(int l,int r,ll v)
    {
        pnode li,mi,ri;
        split(root,l-1,li,mi);
        split(mi,r-l+1,mi,ri);
        mi->lazy=mi->lazy+v;
        merge(mi,mi,ri);
        merge(root,li,mi);
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

    int index(pnode p)
    {
        int res=1;
        if(p->l)
            res+=sz(p->l);
        pnode last=p;
        p=p->p;
        while(p)
        {
            if(last==p->r)
                res+=sz(p->l)+1;
            last=p;
            p=p->p;
        }
        return res;
    }

    void imp(pnode p)
    {
        if(!p)
            return ;
        imp(p->l);
        cout << p->v << ' ' << p->sum << ' ' << p->lazy << ' ' << p->sz << '\n';
        imp(p->r);
    }

    ll size() {return sz(root);}
};

ll abi[MAXN];

void update(int p,int v)
{
    while(p<MAXN)
    {
        abi[p]+=v;
        p+=(p&-p);
    }
}

ll query(int p)
{
    int res=0;
    while(p)
    {
        res+=abi[p];
        p-=(p&-p);
    }
    return res;
}

ll a[MAXN];
ll p[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        p[a[i]]=i+1;
    }

    treap t;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        ll oks=query(p[i]);
        update(p[i],1);
        sum+=i-1-oks;
        if(oks!=i-1)
            t.app(oks+1,t.size(),-1);
        t.insert(p[i]-oks,oks);
        ll v=t[(t.size()+1)/2];
        ll sum1=t.query(1,(t.size()+1)/2);
        ll sum2=0;
        if(t.size()!=(t.size()+1)/2)
            sum2=t.query(((t.size()+1)/2)+1,t.size());
        sum1=(v*((t.size()+1)/2))-sum1;
        sum2=sum2-v*(t.size()-((t.size()+1)/2));
        cout << sum+sum1+sum2 << ' ';
    }
    cout << '\n';

    return 0;
}
/**
4
1 3 4 2
5
1 3 5 2 4
**/