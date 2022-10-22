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
typedef pair<int,int> pii;
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
#define MAXN (ll)(2e5+5)

int d[MAXN];
int a[MAXN],mam[MAXN];

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

int join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
    return -d[u];
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> vp(n);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        vp.push_back(pii(a[i],i));
    }

    sort(allr(vp));

    for(int i=0;i<n;i++)
    {
        int v=vp[i].f;
        int p=vp[i].s;
        d[p]=-1;
        int ma=1;
        if(p>1 && d[p-1])
            ma=join(p,p-1);
        if(p<n && d[p+1])
            ma=join(p,p+1);
        mam[ma]=max(mam[ma],v);
    }

    for(int i=n-1;i>0;i--)
        mam[i]=max(mam[i],mam[i+1]);

    for(int i=1;i<=n;i++)
        cout << mam[i] << " \n"[i==n];

    return 0;
}
/**
10
1 2 3 4 5 4 3 2 1 6
**/