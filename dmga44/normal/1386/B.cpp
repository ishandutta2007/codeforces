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
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-12)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

point f;
point vals[MAXN];
int lims[MAXN][2];
int res[MAXN];

point process(ld x,ld y,ld z)
{
    ll g=0;
    if(((ll)x) || ((ll)y))
        g=__gcd((ll)x,(ll)y);
    g=__gcd(g,(ll)z);
    x/=g;
    y/=g;
    z/=g;
    ld sum=x+y+z;
    x/=sum;
    y/=sum;
    z/=sum;
    ld xx=(sqrt(3.0)-1)/2.0;
//    cout << x << ' ' << y << ' ' << z << '\n';
    return point(y-xx*x,z-xx*x);
}

ld cross(point a, point b) { return imag(conj(a) * b); }

int quad(point x)
{
    if(x.imag()>=0 && x.real()>0) return 0;
    if(x.imag()>0 && x.real()<=0) return 1;
    if(x.imag()<=0 && x.real()<0) return 2;
    return 3;
}

bool operator<(const point &a,const point &b)
{
    if(quad(a)!=quad(b))
        return quad(a)<quad(b);
    return cross(a,b)>0;
}

mt19937 rng(time(0));

template<typename T>
struct treap
{
    struct node
    {
        T key;
        ll sz;
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
        if(pos && fabs(key-find_kth(pos))<eps)
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
        if(p->key<key || fabs(p->key-key)<eps)
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
        if(fabs(p->key-key)<eps)
            merge(p,p->l,p->r);
        else if(key<p->key)
            erase(p->l,key);
        else
            erase(p->r,key);
        update(p);
    }
};

ld trans(point x)
{
    int q=quad(x);
    if(fabs(x.real())<eps)
        return pi/2*q;
    ld ang=atan(x.imag()/x.real());
    if(ang<0)
        ang+=pi;
//    cout << ang << ' ' << q << '\n';
    if(q>=2)
        ang+=pi;
    return ang;
}

struct ans
{
    bool ok[4];
    ans()
    {
        for(int i=0;i<3;i++)
            ok[i]=0;
        ok[3]=1;
    }
};

template <typename T>
struct ST{
    vector< vector<T> > st;
    int sz;

    ST (int n) : sz(n),st(4*n) {}

    void up(int p,T v)
    {
        st[p].push_back(v);
    }

    void update(int L,int R,T v) { update(1,0,sz-1,L,R,v); }

    void update(int p,int l,int r,int L,int R,T v)
    {
        if(L<=l && r<=R)
        {
            up(p,v);
            return ;
        }

        int mid=(l+r)>>1;

        if(L<=mid)
            update(p<<1,l,mid,L,R,v);
        if(R>mid)
            update((p<<1)+1,mid+1,r,L,R,v);
    }

    void solve()
    {
        ans ini;
        treap<ld> act;
        query(1,0,sz-1,ini,act);
    }

    void query(int p,int l,int r,ans k,treap<ld>& act)
    {
//        db("")
//        db(p)
//        cout << l << ' ' << r << '\n';
        vector<ld> adds;
        for(auto y : st[p])
        {
//            cout << y.real() << ' ' << y.imag() << '\n';
            y=y-f;
            if(abs(y)<eps)
            {
                k.ok[0]=1;
                continue;
            }
            y=point((1/abs(y))*y.real(),(1/abs(y))*y.imag());
            ld a=trans(y);
            int pos=act.order_of_key(a);
            if(pos && fabs(act.find_kth(pos)-a)<eps)
                continue;

            adds.push_back(a);
            act.insert(a);
            if(act.size()>=2)
            {
                if(!k.ok[1])
                {
                    ld ant;
                    if(a>=pi)
                        ant=a-pi;
                    else
                        ant=a+pi;
                    int p1=act.order_of_key(ant)-1;
                    if(p1==-1)
                        p1=act.size()-1;
                    p1++;
                    point pp1=act.find_kth(p1);
                    if(fabs(pp1-ant)<eps)
                        k.ok[1]=1;
                }
                if(!k.ok[2] && act.size()>=3)
                {
                    int p1=act.order_of_key(a)-1;
                    int p0=(p1-1+act.size())%act.size();
                    int p2=(p1+1)%act.size();
                    p0++;
                    p1++;
                    p2++;
                    ld pp0=act.find_kth(p0);
                    ld pp2=act.find_kth(p2);
                    ld d1=a-pp0;
                    if(d1<0)
                        d1+=2*pi;
                    ld d2=pp2-a;
                    if(d2<0)
                        d2+=2*pi;
                    ld d3=pp0-pp2;
                    if(d3<0)
                        d3+=2*pi;
                    if(d1<pi && d2<pi && d3<pi)
                        k.ok[2]=1;
                }
            }
        }

//        db("dentro")
//        for(int i=0;i<act.size();i++)
//        {
//            point y=act.find_kth(i+1);
//            cout << y.real() << ' ' << y.imag() << '\n';
//        }
//        db("borrar")
//        for(auto y : adds)
//            cout << y.real() << ' ' << y.imag() << '\n';

        if(l==r)
        {
            for(int i=0;i<4;i++)
                if(k.ok[i])
                {
                    res[l]=i;
                    break;
                }
        }
        else
        {
            int mid=(l+r)>>1;

            query(p<<1,l,mid,k,act);
            query((p<<1)+1,mid+1,r,k,act);
        }

        for(auto y : adds)
            act.erase(y);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    db(trans(point(0,-1)))
//    db(trans(point(0,5)))
//    db(trans(point(0.5,0.5)))
//    db(trans(point(0,1)))
//    db(trans(point(0,1)))
//    db(trans(point(-1,-1)))
//    db(trans(point(-1,1)))
//    db(trans(point(1,-1)))

//    db(__gcd(0,0))

    ll x,y,z;
    cin >> x >> y >> z;
    f=process(x,y,z);

//    cout << f.real() << ' ' << f.imag() << '\n';
    int n;
    cin >> n;
    if(!n)
        return 0;
    int cont=0;
    for(int i=0;i<n;i++)
    {
        char ty;
        cin >> ty;
        if(ty=='A')
        {
            cin >> x >> y >> z;
            vals[cont]=process(x,y,z);
//            cout << vals[cont].real() << ' ' << vals[cont].imag() << '\n';
            lims[cont][0]=i;
            cont++;
        }
        else
        {
            cin >> x;
            x--;
            lims[x][1]=i;
        }
    }

    for(int i=0;i<cont;i++)
    {
        if(lims[i][1])
            lims[i][1]--;
        else
            lims[i][1]=n-1;
    }

    ST<point> st(n);
    for(int i=0;i<cont;i++)
        st.update(lims[i][0],lims[i][1],vals[i]);

    st.solve();

    for(int i=0;i<n;i++)
        cout << (res[i]+1)%4 << '\n';

    return 0;
}
/**
1 1 1
10
A 2 1 1
A 1 2 1
A 1 1 2
A 1 2 3
A 3 2 1
A 2 2 2
R 5
R 6
R 1
R 2

1 2 3
9
A 5 6 7
A 3 10 17
A 5 6 27
A 5 10 15
R 4
R 2
A 2 1 3
A 3 2 1
A 3 1 2

4 1 2
43
A 234 55 124
A 250 87 76
A 220 27 166
A 240 67 106
A 236 59 118
A 208 3 202
A 226 39 148
R 7
R 1
R 2
A 258 103 52
A 218 23 172
R 3
A 222 31 160
A 274 135 4
A 272 131 10
A 262 111 40
R 4
A 260 107 46
R 6
A 214 15 184
A 244 75 94
A 266 119 28
A 240 67 106
A 274 135 4
R 14
A 242 71 100
A 212 11 190
A 216 19 178
R 20
A 248 83 82
R 17
A 234 55 124
A 220 27 166
A 250 87 76
A 228 43 142
A 236 59 118
A 262 111 40
A 234 55 124
R 10
A 210 7 196
R 5
R 8
**/