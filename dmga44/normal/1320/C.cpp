#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN (ll)(1e6+5)

ll st[4*MAXN],lazy[4*MAXN],base[MAXN],mss[MAXN],nss[MAXN];

void build(int p,int l,int r)
{
    if(l==r)
    {
        st[p]=base[l];
        return;
    }
    int mid=(l+r)>>1;

    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);

    st[p]=max(st[p<<1],st[(p<<1)+1]);
}

void push(int p,int l,int r)
{
    if(!lazy[p])
        return ;
    if(l==r)
    {
        lazy[p]=0;
        return;
    }

    st[p<<1]+=lazy[p];
    lazy[p<<1]+=lazy[p];
    st[(p<<1)+1]+=lazy[p];
    lazy[(p<<1)+1]+=lazy[p];
    lazy[p]=0;
}

void update(int p,int l,int r,int L,int R,ll v)
{
    push(p,l,r);
    if(L<=l && r<=R)
    {
        st[p]+=v;
        lazy[p]+=v;
        return ;
    }
    if(l>R || L>r)
        return;
    int mid=(l+r)>>1;

    update(p<<1,l,mid,L,R,v);
    update((p<<1)+1,mid+1,r,L,R,v);

    st[p]=max(st[p<<1],st[(p<<1)+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,p;
    cin >> n >> m >> p;
    vector<pii> ws(n),as(m);
    for(int i=0;i<MAXN;i++)
        nss[i]=mss[i]=MAXN*MAXN;
    for(int i=0;i<n;i++)
    {
        cin >> ws[i].first >> ws[i].second;
        nss[ws[i].first]=min(nss[ws[i].first],ws[i].second);
    }
    for(int i=0;i<m;i++)
    {
        cin >> as[i].first >> as[i].second;
        mss[as[i].first]=min(mss[as[i].first],as[i].second);
    }

    vector<pip> ps(p);
    for(int i=0;i<p;i++)
    {
        cin >> ps[i].first >> ps[i].second.first >> ps[i].second.second;
        base[ps[i].second.first+1]+=ps[i].second.second;
    }

    sort(ps.rbegin(),ps.rend());

    for(int i=1;i<MAXN;i++)
        base[i]=base[i-1]+base[i];
    for(int i=0;i<MAXN;i++)
        base[i]=base[i]-mss[i];

    build(1,0,MAXN-1);

    int pos=0;
    ll res=-(MAXN*MAXN);
    for(int i=MAXN-1;i>=1;i--)
    {
        ll v=-nss[i];
        while(pos<p && ps[pos].first>=i)
        {
            update(1,0,MAXN-1,ps[pos].second.first+1,MAXN-1,-ps[pos].second.second);
            pos++;
        }
        ll ans=st[1];
        res=max(res,ans+v);
    }
    db(res)

    return 0;
}
/**
2 2 7
100 1
101 2
100 1
101 2

10 10 4
99 100 4
100 99 4
100 100 4
100 101 4
101 100 4
101 101 4
**/