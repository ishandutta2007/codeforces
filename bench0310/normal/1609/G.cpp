#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;

struct obj
{
    ll l=0;
    ll sum=0;
    ll val=0;
    ll sz=0;
    ll lazy=0;
    void ini(ll a)
    {
        l=sum=val=a;
        sz=1;
    }
    void pull(obj &a,obj &b)
    {
        l=a.l;
        sum=a.sum+b.sum;
        val=a.val+b.sz*a.sum+b.val;
        sz=a.sz+b.sz;
    }
    void apply(ll d)
    {
        l+=d;
        sum+=sz*d;
        val+=((sz*(sz+1)/2)*d);
        lazy+=d;
    }
    void push(obj &a,obj &b)
    {
        a.apply(lazy);
        b.apply(lazy);
        lazy=0;
    }
};

const int N=100005;
vector<ll> y(N,0);
vector<obj> tree(4*N);

void pull(int idx){tree[idx].pull(tree[2*idx],tree[2*idx+1]);}
void apply(int idx,ll d){tree[idx].apply(d);}
void push(int idx){tree[idx].push(tree[2*idx],tree[2*idx+1]);}

void build(int idx,int l,int r)
{
    if(l==r) tree[idx].ini(y[l]);
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        pull(idx);
    }
}

void update(int idx,int l,int r,int ql,int qr,ll d)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) apply(idx,d);
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),d);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,d);
        pull(idx);
    }
}

obj query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return obj();
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    push(idx);
    obj one=query(2*idx,l,m,ql,min(qr,m));
    obj two=query(2*idx+1,m+1,r,max(ql,m+1),qr);
    obj three;
    three.pull(one,two);
    return three;
}

int descend(int idx,int l,int r,ll lim)
{
    if(l==r) return l;
    int m=(l+r)/2;
    push(idx);
    if(tree[2*idx+1].l>lim) return descend(2*idx,l,m,lim);
    else return descend(2*idx+1,m+1,r,lim);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<ll> x(n+1,0);
    for(int i=1;i<n;i++) x[i]=a[i+1]-a[i];
    vector<ll> b(m+1,0);
    for(int i=1;i<=m;i++) cin >> b[i];
    for(int i=1;i<m;i++) y[i]=b[i+1]-b[i];
    ll zero=a[1]+b[1];
    build(1,1,m-1);
    while(q--)
    {
        int t,k,d;
        cin >> t >> k >> d;
        if(t==1)
        {
            if(k==n){zero+=d;k--;}
            for(int i=n-k;i<=n-1;i++) x[i]+=d;
        }
        else
        {
            if(k==m){zero+=d;k--;}
            update(1,1,m-1,m-k,m-1,d);
        }
        ll res=(n+m-1)*zero;
        ll e=n+m-2;
        int l=1;
        auto add=[&](ll lim)
        {
            int r=(tree[1].l<=lim?descend(1,1,m-1,lim):0);
            obj o=query(1,1,m-1,l,r);
            res+=(o.val+(e-o.sz)*o.sum);
            l=r+1;
            e-=o.sz;
        };
        for(int i=1;i<=n-1;i++)
        {
            add(x[i]);
            res+=(e*x[i]);            
            e--;
        }
        add(1ll<<60);
        cout << res << "\n";
    }
    return 0;
}