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
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(2e9+99);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll dp1[MAXN];
ll dp2[MAXN];
ll dp3[MAXN];
ll dp4[MAXN];
ll v1[MAXN];
ll v2[MAXN];
ll v3[MAXN];
ll v4[MAXN];
set<int> g2[MAXN];
set<int> g3[MAXN];
set<int> g4[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n1,n2,n3,n4;
    cin >> n1 >> n2 >> n3 >> n4;
    for(int i=0;i<MAXN;i++)
    {
        dp1[i]=oo;
        dp2[i]=oo;
        dp3[i]=oo;
        dp4[i]=oo;
    }

    for(int i=0;i<n1;i++)
        cin >> v1[i];
    for(int i=0;i<n2;i++)
        cin >> v2[i];
    for(int i=0;i<n3;i++)
        cin >> v3[i];
    for(int i=0;i<n4;i++)
        cin >> v4[i];

    for(int i=0;i<n1;i++)
        dp1[i]=v1[i];
    priority_queue<pii,vector<pii>,greater<pii>> pq;

    while(!pq.empty())
        pq.pop();
    for(int i=0;i<n1;i++)
        pq.push(pii(dp1[i],i));
    int m1;
    cin >> m1;
    for(int i=0;i<m1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g2[v].insert(u);
    }

    for(int i=0;i<n2;i++)
    {
        ll mi=oo;
        vector<pii> tp;
        while(!pq.empty())
        {
            auto xx=pq.top();
            pq.pop();
            tp.push_back(xx);
            if(g2[i].count(xx.s))
                continue;
            mi=xx.f;
            break;
        }
        for(auto x : tp)
            pq.push(x);
        dp2[i]=mi+v2[i];
    }

    while(!pq.empty())
        pq.pop();
    for(int i=0;i<n2;i++)
        pq.push(pii(dp2[i],i));
    int m2;
    cin >> m2;
    for(int i=0;i<m2;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g3[v].insert(u);
    }

    for(int i=0;i<n3;i++)
    {
        ll mi=oo;
        vector<pii> tp;
        while(!pq.empty())
        {
            auto xx=pq.top();
            pq.pop();
            tp.push_back(xx);
            if(g3[i].count(xx.s))
                continue;
            mi=xx.f;
            break;
        }
        for(auto x : tp)
            pq.push(x);
        dp3[i]=mi+v3[i];
    }

    while(!pq.empty())
        pq.pop();
    for(int i=0;i<n3;i++)
        pq.push(pii(dp3[i],i));
    int m3;
    cin >> m3;
    for(int i=0;i<m3;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g4[v].insert(u);
    }

    for(int i=0;i<n4;i++)
    {
        ll mi=oo;
        vector<pii> tp;
        while(!pq.empty())
        {
            auto xx=pq.top();
            pq.pop();
            tp.push_back(xx);
            if(g4[i].count(xx.s))
                continue;
            mi=xx.f;
            break;
        }
        for(auto x : tp)
            pq.push(x);
        dp4[i]=mi+v4[i];
    }

    ll mi=oo;
    for(int i=0;i<n4;i++)
        mi=min(mi,dp4[i]);

    if(mi>1e17)
        db(-1)
    else
        db(mi)

    return 0;
}