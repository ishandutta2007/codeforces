#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e2+5)

mt19937 rng(time(0));

template<typename T>
struct treap2
{
    struct node
    {
        T key;
        ll v;
        ll mi;
        int sz;
        int prior;
        node *l,*r;
        node(T key,ll _v = 0) : l(0),r(0),key(key),sz(1),prior(rng()),v(_v),mi(_v) {}
    };
    typedef node* pnode;
    pnode root;
    treap2() : root(0){}

    int sz(pnode p)
    {
        return p ? p->sz : 0;
    }

    ll mi(pnode p)
    {
        return p ? p->mi : 1e18;
    }

    void update(pnode p)
    {
        if(p)
        {
            p->sz=1+sz(p->l)+sz(p->r);
            p->mi=min(p->v,min(mi(p->l),mi(p->r)));
        }
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
        erase(root,key);
    }

    ///returns the number of elements less than or equal to the key
    int order_of_key(T key) { return order_of_key(root,key); }

    ///returns the k-th(1-indexed) in the ordered set of keys of the treap
    pii find_kth(int k) {return find_kth(root,k);}

    int size() { return sz(root); }

    int order_of_key(pnode p,T key)
    {
        if(!p)
            return 0;
        if(p->key<=key)
            return sz(p->l)+1+order_of_key(p->r,key);
        return order_of_key(p->l,key);
    }

    pii find_kth(pnode p,int k)
    {
        int pos=sz(p->l)+1;
        if(pos==k)
            return pii(p->key,p->v);
        if(pos>k)
            return find_kth(p->l,k);
        return find_kth(p->r,k-pos);
    }

    void insert(pnode& p,pnode it)
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

    int count(T key) { return find(root,key);}

    bool find(T key) { return find(root,key);}

    bool find(pnode &p,T key)
    {
        if(!p)
            return 0;
        if(p->key==key)
            return 1;
        else if(key<p->key)
            return find(p->l,key);
        else
            return find(p->r,key);
    }

    ll& operator[](T key)
    {
        if(!find(key))
        {
//            db("xxx2")
            insert(key);
//            db("xxx2")
        }
        return index(root,key);
    }

    void set(T key,ll v)
    {
        if(!find(key))
        {
//            db("xxx2")
            insert(key);
//            db("xxx2")
        }
        index(root,key)=v;
        upd(root,key);
    }

    void upd(pnode p,T key)
    {
        if(p->key==key)
        {
            ///upd
        }
        else if(key<p->key)
            upd(p->l,key);
        else
            upd(p->r,key);
        update(p);
    }

    ll& index(pnode p,T key)
    {
        if(p->key==key)
            return p->v;
        else if(key<p->key)
            return index(p->l,key);
        else
            return index(p->r,key);
    }
};

struct state{
    ll ofs;
    treap2<int> best;

    state() : ofs(0){}
};

int n,ss;
int cont;

void swap(treap2<ll>& a,treap2<ll>& b)
{
    swap(a.root,b.root);
}

state& solve(state& ini)
{
    while(1)
    {
        if(cont==n)
            return ini;

        string s;
        cin >> s;
        cont++;
        if(s=="end")
            return ini;
        if(s=="if")
        {
            int y;
            cin >> y;
            ll v=1e18;
            if(ini.best.count(y))
                v=ini.best[y]+ini.ofs;
            state ne;
            ne.best.set(y,v);

            state el_if=solve(ne);

            bool doit=1;
            if(el_if.best.size()>ini.best.size())
            {
                swap(el_if.best,ini.best);
                swap(el_if.ofs,ini.ofs);
                doit=0;
            }

            for(int i=1;i<=el_if.best.size();i++)
            {
                pii p=el_if.best.find_kth(i);
                int key=p.f;
                ll v=p.s;
                v+=el_if.ofs;
                bool no_hay=!ini.best.count(key);
                ll v2=1e18;
                if(!no_hay)
                    v2=ini.best[key];
                if((no_hay || v2+ini.ofs>v || key==y) && (key!=y || doit))
                    ini.best.set(key,v-ini.ofs);
            }
        }
        if(s=="set")
        {
            ll x,v;
            cin >> x >> v;
            ini.ofs+=v;
            if(x!=ss)
            {
                ll nv=ini.best.root->mi;
                ini.best.set(x,nv-v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> ss;
    state ini;
    ini.best[0]=0;
    state ans=solve(ini);

    ll res=ans.ofs;
    res+=ans.best.root->mi;
    db(res)

    return 0;
}
/**
5 1
set 1 10
set 2 15
if 2
set 1 7
end
**/