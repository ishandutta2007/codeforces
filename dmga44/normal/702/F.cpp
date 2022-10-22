#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

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
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (int)(1e4+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

mt19937 rng(time(0));

pii operator+(pii a,pii b)
{
    return pii(a.f+b.f,a.s+b.s);
}

template<typename T>
struct treap
{
    struct node{
        node *l,*r;
        int sz,prior;
        int res;
        pii lazy;
        T key;
        node(T v,int res) : key(v),l(0),r(0),sz(1),prior(rng()),res(res),lazy(pii(0,0)) {}
    };
    typedef node* pnode;
    pnode root;
    treap() : root(0){}

    int sz(pnode p)
    {
        return p ? p->sz : 0;
    }

    void update(pnode p)
    {
        if(p)
            p->sz=1+sz(p->l)+sz(p->r);
    }

    void up(pnode p,pii x)
    {
        if(!p)
            return ;
        p->key.first+=x.f;
        p->res+=x.s;
        p->lazy=p->lazy+x;
    }

    void push(pnode p)
    {
        if(!p)
            return ;
        if(p->lazy==pii(0,0))
            return ;
        up(p->l,p->lazy);
        up(p->r,p->lazy);
        p->lazy=pii(0,0);
    }

    void update(int c)
    {
        pnode l,r;
        split(root,pii(c-1,MAXN),l,r);
        up(r,pii(-c,1));
        push(r);
        if(!sz(l) || !sz(r))
        {
            merge(root,l,r);
            return ;
        }

        int szl=sz(l);
        pii last=find_kth(l,szl)->key;
        while(sz(r))
        {
            pnode kk=find_kth(r,1);
            pii ke=kk->key;
            int res=kk->res;

            if(ke>last)
                break;

            erase(r,pii(ke));
            pnode nn=new node(ke,res);
            insert(l,nn);
        }
        merge(root,l,r);
    }

    ///left subtree will contain elements less than or equal to key
    void split(pnode p,T key,pnode &l,pnode &r)
    {
        push(p);
        if(!p)
            l=r=0;
        else if(key<p->key)
        {
            split(p->l,key,l,p->l);
            r=p;
        }
        else
        {
            split(p->r,key,p->r,r);
            l=p;
        }
        update(p);
    }

    void insert(T key,int res)
    {
        pnode add=new node(key,res);
        insert(root,add);
    }

    void erase(T key)
    {
        int pos=order_of_key(key);
        if(pos && key==find_kth(pos))
            erase(root,key);
    }

    ///returns the number of elements less than or equal to the key
    int order_of_key(T key) { return order_of_key(root,key); }

    ///returns the k-th(1-indexed) in the ordered set of keys of the treap
    T find_kth(int k) {return find_kth(root,k)->key;}

    int size() { return sz(root); }

    int order_of_key(pnode p,T key)
    {
        push(p);
        if(!p)
            return 0;
        if(p->key<=key)
            return sz(p->l)+1+order_of_key(p->r,key);
        return order_of_key(p->l,key);
    }

    pnode find_kth(pnode p,int k)
    {
        push(p);
        int pos=sz(p->l)+1;
        if(pos==k)
            return p;
        if(pos>k)
            return find_kth(p->l,k);
        return find_kth(p->r,k-pos);
    }

    void insert(pnode &p,pnode it)
    {
        push(p);
        if(!p)
            p=it;
        else if(it->prior>p->prior)
        {
            split(p,it->key,it->l,it->r);
            p=it;
        }
        else
        {
            if(it->key<p->key)
                insert(p->l,it);
            else
                insert(p->r,it);
        }
        update(p);
    }

    void merge(pnode &p,pnode l,pnode r)
    {
        push(p);
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

    void erase(pnode &p,T key)
    {
        push(p);
        if(p->key==key)
            merge(p,p->l,p->r);
        else if(key<p->key)
            erase(p->l,key);
        else
            erase(p->r,key);
        update(p);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> cs;
    for(int i=0;i<n;i++)
    {
        int c,q;
        cin >> c >> q;
        cs.push_back(pii(q,-c));
    }

    sort(allr(cs));

    int k;
    cin >> k;
    vector<pii> vt;
    for(int i=0;i<k;i++)
    {
        int x;
        cin >> x;
        vt.push_back(pii(x,i));
    }

    sort(all(vt));

    treap<pii> t;
    for(int i=0;i<k;i++)
        t.insert(pii(vt[i].first,vt[i].second),0);

    for(int i=0;i<n;i++)
    {
        int c=-cs[i].s;
        t.update(c);
    }

    vector<int> res(k);
    for(int i=1;i<=k;i++)
    {
        int r1=t.find_kth(t.root,i)->res;
        int id=t.find_kth(t.root,i)->key.s;
        res[id]=r1;
    }
    for(int i=0;i<k;i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}
/**
3
7 5
3 5
4 3
2
13 14

2
100 500
50 499
4
50 200 150 100
**/