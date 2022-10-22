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
#define mod (int)(1e4+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

struct e{
    ll sum;
    ll u,m;
    e() : sum(0),u(0),m(0){}
};

e m[MAXN][50];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,kk;
    cin >> n >> kk;
    for(int i=0;i<n;i++)
        cin >> m[i][0].u;
    for(int i=0;i<n;i++)
    {
        cin >> m[i][0].sum;
        m[i][0].m=m[i][0].sum;
    }

    for(int k=1;k<50;k++)
        for(int i=0;i<n;i++)
        {
            m[i][k].u=m[m[i][k-1].u][k-1].u;
            m[i][k].sum=m[i][k-1].sum+m[m[i][k-1].u][k-1].sum;
            m[i][k].m=min(m[i][k-1].m,m[m[i][k-1].u][k-1].m);
        }

    for(int i=0;i<n;i++)
    {
        ll sum=0,mm=1e9;
        int u=i;
        for(ll po=40;po>=0;po--)
            if(kk&(1ll<<po))
            {
                sum+=m[u][po].sum;
                mm=min(mm,m[u][po].m);
                u=m[u][po].u;
            }
        cout << sum << ' ' << mm << '\n';
    }

    return 0;
}
/**
7 3
1 2 3 4 3 2 6
6 3 1 4 2 2 3
**/