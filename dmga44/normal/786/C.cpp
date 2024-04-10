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
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)
#define MAXP (ll)(1e7+5)
///up to change
typedef int T;
struct node{
    int l,r;
    T v;
};

int vn[MAXN];
node pool[MAXP];
int actual;

int next()
{
    actual++;
    return actual;
}

//template<typename T>
struct pst{
    vector<int> versions;
    int n;
    pst() : n(0) {}
    pst(int n) : n(n) {}
    pst(vector<T> &a) : n(a.size()) { versions.push_back(build(0,n-1,a)); }

    T merge(T v1,T v2)
    {
        return v1+v2;
    }

    void up(int p,T v)
    {
        pool[p].v+=v;
    }

    int build(int l,int r,vector<T> &a)
    {
        int ans=next();
        if(l==r)
        {
            pool[ans].v=a[l];
            return ans;
        }
        int mid=(l+r)>>1;
        pool[ans].l=build(l,mid,a);
        pool[ans].r=build(mid+1,r,a);
        pool[ans].v=merge(pool[pool[ans].l].v,pool[pool[ans].r].v);
        return ans;
    }

    int build(int l,int r,T* a)
    {
        int ans=next();
        if(l==r)
        {
            pool[ans].v=a[l];
            return ans;
        }
        int mid=(l+r)>>1;
        pool[ans].l=build(l,mid,a);
        pool[ans].r=build(mid+1,r,a);
        pool[ans].v=merge(pool[pool[ans].l].v,pool[pool[ans].r].v);
        return ans;
    }

    int clone(int p)
    {
        int ans=next();
        pool[ans].l=pool[p].l;
        pool[ans].r=pool[p].r;
        pool[ans].v=pool[p].v;
        return ans;
    }

    void update(int ver,int pos,T v) { versions.push_back(update(versions[ver],0,n-1,pos,v)); }
    void update(int pos,T v) { versions.push_back(update(versions.back(),0,n-1,pos,v)); }

    int update(int p,int l,int r,int pos,T v)
    {
        p=clone(p);

        if(r==l)
        {
            up(p,v);
            return p;
        }
        int mid=(l+r)>>1;
        if(pos<=mid)
            pool[p].l=update(pool[p].l,l,mid,pos,v);
        else
            pool[p].r=update(pool[p].r,mid+1,r,pos,v);
        pool[p].v=merge(pool[pool[p].l].v,pool[pool[p].r].v);
        return p;
    }

    T query(int t,int l,int r) { return query(versions[t],0,n-1,l,r); }

    T query(int p,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
            return pool[p].v;

        int mid=(l+r)>>1;
        if(R<=mid)
            return query(pool[p].l,l,mid,L,R);
        if(L>mid)
            return query(pool[p].r,mid+1,r,L,R);
        return merge(query(pool[p].l,l,mid,L,R),query(pool[p].r,mid+1,r,L,R));
    }

    int qq(int u,int k)
    {
        int ini=0;
        if(u)
            ini+=query(vn[u],0,u-1);
        int tot=query(vn[u],0,n-1);
        if(ini+k>=tot)
            return n-1;
        vector<int> ps={versions[vn[u]]};
        vector<int> sg={1};
        return multi_kth(ps,sg,0,n-1,ini+k+1)-1;
    }

    int multi_kth(vector<int> &p,vector<int> &sg,int l,int r,int k)
    {
        if(l==r)
            return l;

        int mid=(l+r)>>1;
        int sl=0;
        for(int i=0;i<p.size();i++)
            sl+=(pool[pool[p[i]].l].v)*(sg[i]);
        if(sl>=k)
        {
            vector<int> next;
            for(auto pp : p)
                next.push_back(pool[pp].l);
            return multi_kth(next,sg,l,mid,k);
        }
        k-=sl;

        vector<int> next;
        for(auto pp : p)
            next.push_back(pool[pp].r);
        return multi_kth(next,sg,mid+1,r,k);
    }
};

int last[MAXN];
vector<int> ps[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        ps[last[x]].push_back(i);
        last[x]=i+1;
    }

    vector<int> ini(n);
    pst st(ini);

    for(int i=0;i<n;i++)
    {
        for(auto y : ps[i])
            st.update(y,1);
        vn[i]=st.versions.size()-1;
    }

    for(int i=1;i<=n;i++)
    {
        int pos=-1;
        int res=0;
        while(pos!=n-1)
        {
            pos++;
            res++;
            pos=st.qq(pos,i);
        }
        cout << res << ' ';
    }

    return 0;
}
/**
5
1 3 4 3 3

5
1 2 3 4 5

5
1 1 1 1 1

8
1 5 7 8 1 7 6 1
**/