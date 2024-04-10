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
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN (ll)(4e5+5)

mt19937 rng(time(0));

template<typename T>
struct treap
{
    ///1-indexed functions
    ///this treap extends array functionalities
    struct node{
        node *l,*r;
        int sz,prior;
        bool rev;
        T v;
        node(T v) : v(v),l(0),r(0),sz(1),rev(0),prior(rng()) {}
    };
    typedef node* pnode;
    pnode root;
    treap() : root(0) {}

    int sz(pnode p) { return p ? p->sz : 0; }

    void update(pnode p)
    {
        if(!p)
            return ;
        p->sz=1+sz(p->l)+sz(p->r);
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
        return find_kth(root,i);
    }

    T find_kth(pnode p,int k)
    {
        push(p);
        if(sz(p->l)<k-1)
            return find_kth(p->r,k-sz(p->l)-1);
        else if(sz(p->l)==k-1)
            return p->v;
        return find_kth(p->l,k);
    }
};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q,m,a;
    cin >> n >> q >> m;
    treap<int> t;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        t.insert(a,i);
    }
    for(int i=0;i<q;i++)
    {
        int ty,l,r;
        cin >> ty >> l >> r;
        if(ty==1)
        {
            if(l==r)
                continue;
            t.swap_intervals(l,r-1,r,r);
        }
        if(ty==2)
            t.reverse(l,r);
    }

    for(int i=0;i<m;i++)
    {
        cin >> a;
        cout << t[a] << ' ';
    }
    cout << '\n';

    return 0;
}
/**
6 3 5
1 2 3 4 5 6
2 1 3
2 3 6
1 1 6
2 2 1 5 3
**/