#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct line
{
    ll k,n;
    mutable ll r;
    line(ll a,ll b):k(a),n(b){r=0;}
    bool operator<(const line &o)const{return (k>o.k);}
    bool operator<(ll o)const{return (r<o);}
};

struct cht
{
    set<line,less<>> s;
    const ll inf=(1ll<<60);
    ld intersect(line a,line b){return ((ld)b.n-a.n)/(a.k-b.k);}
    bool bad(line a,line b,line c){return (intersect(a,b)>intersect(b,c));}
    void add(ll k,ll n)
    {
        line now(k,n);
        auto it=s.lower_bound(now);
        if(it!=s.end()&&(it->k)==k)
        {
            if(it->n>n) it=s.erase(it);
            else return;
        }
        if(it!=s.begin()&&it!=s.end()&&bad(*prev(it),now,*it)) return;
        s.insert(now);
        while(it!=s.end()&&next(it)!=s.end()&&bad(now,*it,*next(it))) it=s.erase(it);
        it--;
        while(it!=s.begin()&&prev(it)!=s.begin()&&bad(*prev(prev(it)),*prev(it),now)) s.erase(prev(it));
        if(it!=s.begin()) prev(it)->r=floor(intersect(*prev(it),now));
        if(next(it)!=s.end()) it->r=floor(intersect(now,*next(it)));
        else it->r=inf;
    }
    ll query(ll a)
    {
        line best=(*s.lower_bound(a));
        return (best.k*a+best.n);
    }
};

const int N=100005;
int a[N];
int sum[N];
cht tree[4*N];

void build(int idx,int l,int r)
{
    if(l==r) tree[idx].add(a[l],l*a[l]-sum[l]);
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        for(line b:tree[2*idx].s) tree[idx].add(b.k,b.n);
        for(line b:tree[2*idx+1].s) tree[idx].add(b.k,b.n);
    }
}

int query(int idx,int l,int r,int ql,int qr,int x)
{
    if(ql>qr) return (1<<30);
    if(l==ql&&r==qr) return tree[idx].query(x);
    int m=(l+r)/2;
    return min(query(2*idx,l,m,ql,min(qr,m),x),query(2*idx+1,m+1,r,max(ql,m+1),qr,x));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum[i]=sum[i-1]+a[i];
    }
    build(1,1,n);
    int m;
    cin >> m;
    while(m--)
    {
        int r,c;
        cin >> r >> c;
        cout << sum[c]+query(1,1,n,c-r+1,c,r-c) << "\n";
    }
    return 0;
}