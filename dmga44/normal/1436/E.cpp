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
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

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

template <typename T>
struct ST{
    vector< T > st;
    int sz;

    ST (int n) : sz(n),st(4*n) {}

    void up(int p,int v)
    {
        st[p].insert(v);
    }

    void update(int pos,int v) { update(1,0,sz-1,pos,v); }

    void update(int p,int l,int r,int pos,int v)
    {
        up(p,v);
        if(pos<=l && r<=pos)
            return ;
        int mid=(l+r)>>1;

        if(pos<=mid)
            update(p<<1,l,mid,pos,v);
        if(pos>mid)
            update((p<<1)+1,mid+1,r,pos,v);
    }

    int query(int L,int R,int x) { return query(1,0,sz-1,L,R,x); }

    int query(int p,int l,int r,int L,int R,int x)
    {
        if(L<=l && r<=R)
            return st[p].order_of_key(x);

        int mid=(l+r)>>1;

        if(R<=mid)
            return query(p<<1,l,mid,L,R,x);
        if(L>mid)
            return query((p<<1)+1,mid+1,r,L,R,x);
        return query(p<<1,l,mid,L,R,x)+query((p<<1)+1,mid+1,r,L,R,x);
    }
};

vector<int> pos[MAXN];

int32_t main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n+2;i++)
        pos[i].push_back(-i);
    int kk=1;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        kk=(kk&(a==1));
        pos[a].push_back(i);
    }

    ST<treap<int> > st(n+5);

    if(kk)
        db(1)
    else
    {
        int res=1;
        for(int i=1;i<pos[1].size();i++)
            st.update(pos[1][i],pos[1][i-1]);
        while(1)
        {
            pos[res+1][0]=-1;

//            db("")
//            db(res+1)
            bool kk=0;
            pos[res+1].push_back(n);
            for(int i=1;i<pos[res+1].size();i++)
            {
                if(pos[res+1][i-1]+1<pos[res+1][i])
                {
//                    cout << pos[res+1][i-1] << ' ' << pos[res+1][i] << ' ' << st.query(pos[res+1][i-1]+1,pos[res+1][i]-1,pos[res+1][i-1]) << '\n';
                    kk=(kk|(st.query(pos[res+1][i-1]+1,pos[res+1][i]-1,pos[res+1][i-1])==res));
                }
            }
            if(!kk)
                break;
            else
                res++;

            pos[res][0]=-res;
            for(int i=1;i<pos[res].size()-1;i++)
                st.update(pos[res][i],pos[res][i-1]);
        }
        db(res+1)
    }

    return 0;
}