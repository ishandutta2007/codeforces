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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(6e5+15)

template <typename T>
struct ST{
    vector< T > st,lazy;
    int sz;
    T neutroQ,neutroL;

    ST (int n,T neutroq,T neutrol) : sz(n),st(4*n),lazy(4*n),neutroQ(neutroq),neutroL(neutrol) {}

    T merge(T v1,T v2)
    {
        return min(v1,v2);
    }

    void up(int p,int l,int r,T v)
    {
        st[p]+=v;
        lazy[p]+=v;
    }

    void push(int p,int l,int r)
    {
        if(l==r)
        {
            lazy[p]=neutroL;
            return ;
        }
        if(lazy[p]==neutroL)
            return ;
        ///(basic) up to code
        T v=lazy[p];
        up((p<<1),l,(l+r)>>1,v);
        up((p<<1)+1,((l+r)>>1)+1,r,v);
        lazy[p]=neutroL;
    }

    void build(vector<T> &arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,vector<T> &arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            lazy[p]=neutroL;
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
        lazy[p]=neutroL;
    }

    void build(T *arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,T *arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            lazy[p]=neutroL;
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
        lazy[p]=neutroL;
    }

    void update(int L,int R,T v) { update(1,0,sz-1,L,R,v); }

    void update(int p,int l,int r,int L,int R,T v)
    {
        push(p,l,r);
        if(L<=l && r<=R)
        {
            up(p,l,r,v);
            return ;
        }

        int mid=(l+r)>>1;

        if(L<=mid)
            update(p<<1,l,mid,L,R,v);
        if(R>mid)
            update((p<<1)+1,mid+1,r,L,R,v);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    T query(int L,int R) { return query(1,0,sz-1,L,R); }

    T query(int p,int l,int r,int L,int R)
    {
        push(p,l,r);
        if(L<=l && r<=R)
        {
//            cout << p << ' ' << l << ' ' << r << ' ' << st[p] << '\n';
            if(st[p])
                return neutroQ;
            if(l==r)
                return l;
            int mid=(l+r)>>1;
            if(!st[p<<1])
                return query(p<<1,l,mid,L,R);
            return query((p<<1)+1,mid+1,r,L,R);
        }
        else if(L>r || l>R)
            return neutroQ;

        int mid=(l+r)>>1;

        int r1=query(p<<1,l,mid,L,R);
        if(r1==neutroQ)
            return query((p<<1)+1,mid+1,r,L,R);
        return r1;
    }

    int q2(int p,int l,int r,int pos)
    {
        if(r==l && r==pos)
            return st[p];
        else if(pos>r || l>pos)
            return neutroQ;
        push(p,l,r);

        int mid=(l+r)>>1;

        return merge(q2(p<<1,l,mid,pos),q2((p<<1)+1,mid+1,r,pos));
    }
};

int abi[MAXN];

void update(int p,int v)
{
    while(p<MAXN)
    {
        abi[p]+=v;
        p+=(p&-p);
    }
}

int query(int p)
{
    int res=0;
    while(p)
    {
        res+=abi[p];
        p-=(p&-p);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k,m,x,y;
    cin >> n >> k >> m;
    ST<int> st(MAXN,1e6,0);
    map<pii,bool> mk;
    int cant=0;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        int pos=abs(k-x)+y;
        if(!mk[pii(x,y)])
        {
            cant++;
            mk[pii(x,y)]=1;
            st.update(pos,MAXN-1,1);

            int sum=query(pos-1);
            int act=pos-1;
            for(int po=(1<<19);po;po>>=1)
                if(act+po<MAXN && act+po-pos+1==query(act+po)-sum)
                    act+=po;
            act++;

            update(act,1);
            st.update(act,MAXN-1,-1);
//            cout << pos << ' ' << act << '\n';
        }
        else
        {
            cant--;
            mk[pii(x,y)]=0;
            int tar=st.query(pos,MAXN-1);

            update(tar,-1);
            st.update(tar,MAXN-1,1);
            st.update(pos,MAXN-1,-1);
//            cout << pos << ' ' << tar << '\n';
        }

        pos=0;
        int ac=0;
        for(int po=(1<<19);po;po>>=1)
            if(pos+po<MAXN && ac+abi[pos+po]<cant)
            {
                pos+=po;
                ac+=abi[pos];
            }
        pos++;
        db(max(0,pos-n))
//        cout << "0 ";
//        for(int i=0;i<9;i++)
//            cout << query(i+1)-query(i) << ' ';
//        cout << '\n';
//        for(int i=0;i<10;i++)
//            cout << st.q2(1,0,MAXN-1,i) << ' ';
//        cout << '\n';
//        db("")
    }

    return 0;
}
/**
5 3 5
4 4
3 5
2 4
3 4
3 5
**/