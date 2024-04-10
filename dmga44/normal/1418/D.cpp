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
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

mt19937 rng(time(0));

template<typename T>
struct treap
{
    struct node
    {
        T key;
        int sz;
        int prior;
        node *l,*r;
        node(T key) : l(0),r(0),key(key),sz(1),prior(rng()) {}
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

    ///left subtree will contain elements less than or equal to key
    void split(pnode p,T key,pnode &l,pnode &r)
    {
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

    void insert(T key)
    {
        pnode add=new node(key);
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
    T find_kth(int k) {return find_kth(root,k);}

    int size() { return sz(root); }

    int order_of_key(pnode p,T key)
    {
        if(!p)
            return 0;
        if(p->key<=key)
            return sz(p->l)+1+order_of_key(p->r,key);
        return order_of_key(p->l,key);
    }

    T find_kth(pnode p,int k)
    {
        int pos=sz(p->l)+1;
        if(pos==k)
            return p->key;
        if(pos>k)
            return find_kth(p->l,k);
        return find_kth(p->r,k-pos);
    }

    void insert(pnode &p,pnode it)
    {
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
        if(p->key==key)
            merge(p,p->l,p->r);
        else if(key<p->key)
            erase(p->l,key);
        else
            erase(p->r,key);
        update(p);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    vector<int> inis(n);
    for(int i=0;i<n;i++)
        cin >> inis[i];
    sort(all(inis));

    treap<int> dif;
    treap<int> vs;
    for(int i=0;i<n;i++)
        vs.insert(inis[i]);
    for(int i=1;i<n;i++)
        dif.insert(inis[i]-inis[i-1]);
    int cant=n;
    if(cant>=3)
        cout << vs.find_kth(cant)-vs.find_kth(1)-dif.find_kth(dif.size()) << '\n';
    else
        db(0)
    while(q--)
    {
        int ty,x;
        cin >> ty>> x;
        if(ty)
        {
            cant++;
            int p=vs.order_of_key(x);
            if(vs.size())
            {
                if(p==0)
                    dif.insert(vs.find_kth(1)-x);
                else if(p==vs.size())
                    dif.insert(x-vs.find_kth(vs.size()));
                else
                {
                    dif.erase(vs.find_kth(p+1)-vs.find_kth(p));
                    dif.insert(x-vs.find_kth(p));
                    dif.insert(vs.find_kth(p+1)-x);
                }
            }
            vs.insert(x);
        }
        else
        {
            cant--;
            int p=vs.order_of_key(x);
            if(vs.size()>1)
            {
                if(p==1)
                    dif.erase(vs.find_kth(2)-x);
                else if(p==vs.size())
                    dif.erase(x-vs.find_kth(vs.size()-1));
                else
                {
                    dif.insert(vs.find_kth(p+1)-vs.find_kth(p-1));
                    dif.erase(x-vs.find_kth(p-1));
                    dif.erase(vs.find_kth(p+1)-x);
                }
            }
            vs.erase(x);
        }

        if(cant>=3)
            cout << vs.find_kth(cant)-vs.find_kth(1)-dif.find_kth(dif.size()) << '\n';
        else
            db(0)
    }

    return 0;
}