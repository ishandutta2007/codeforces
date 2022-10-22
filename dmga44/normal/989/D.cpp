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
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

vector<ll> abib[MAXN];
vector<ll> abibb[MAXN];

void update(int p,ll w)
{
    while(p<MAXN)
    {
        abib[p].push_back(w);
        p+=(p&-p);
    }
}

int query(int p,ll w)
{
    int res=0;
    while(p)
    {
        res+=upper_bound(all(abib[p]),w)-abib[p].begin();
        p-=(p&-p);
    }
    return res;
}

void updateb(int p,ll w)
{
    while(p<MAXN)
    {
        abibb[p].push_back(w);
        p+=(p&-p);
    }
}

int queryb(int p,ll w)
{
    int res=0;
    while(p)
    {
        res+=upper_bound(all(abibb[p]),w)-abibb[p].begin();
        p-=(p&-p);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,l,w;
    cin >> n >> l >> w;
    vector<ll> f;
    vector<ll> b;
    for(int i=0;i<n;i++)
    {
        int x,t;
        cin >> x >> t;
        if(t==1)
            f.push_back(x);
        else
            b.push_back(x);
    }

    sort(all(f));
    sort(all(b));

    n=f.size();
    int m=b.size();
    for(int i=0;i<m;i++)
    {
        update(i+1,(w-1)*b[i]);
        updateb(i+1,(w+1)*b[i]);
    }

    ll res=0;
    for(int i=0;i<n;i++)
    {
//        db(res)
        ll x1=f[i];
        ll lim=-x1-l;
        res+=max(0,upper_bound(all(b),lim)-lower_bound(all(b),max(lim,x1)));
        if(lim>x1)
        {
            int ini=upper_bound(all(b),x1)-b.begin();
            int fin=lower_bound(all(b),lim)-b.begin()-1;
            if(fin>=ini)
                res+=(fin-ini+1)-(queryb(fin+1,(w-1)*x1-(w+1)*l)-queryb(ini,(w-1)*x1-(w+1)*l));
        }
        lim=max(lim,x1);
        int ini=upper_bound(all(b),lim)-b.begin();
        int fin=m-1;
        if(fin>=ini)
            res+=(fin-ini+1)-(query(fin+1,(w+1)*x1-(w-1)*l)-query(ini,(w+1)*x1-(w-1)*l));
    }
    db(res)

    return 0;
}
/**
5 1 2
-2 1
2 1
3 -1
5 -1
7 -1
4 10 1
-20 1
-10 -1
0 1
10 -1
**/