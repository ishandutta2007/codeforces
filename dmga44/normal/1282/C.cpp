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
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll c[2];

int solve(ll time,vector<int>& f)
{
    if(time<0)
        return -oo;
    ll res=0;
    ll add=min((ll)f[0],time/c[0]);
    time-=add*c[0];
    res+=add;
    add=min((ll)f[1],time/c[1]);
    res+=add;
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,t;
        cin >> n >> t >> c[0] >> c[1];
        vector<int> ty(n);
        map<int,vector<int> > mm;
        vector<int> f(2);
        for(int i=0;i<n;i++)
        {
            cin >> ty[i];
            f[ty[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            int ti;
            cin >> ti;
            mm[ti].push_back(i);
        }

        ll cant=0;
        ll sum=0;
        ll res=0;
        for(auto y : mm)
        {
            int time=y.f;
            vector<int> xs=y.s;
            if(time)
                res=max(res,cant+solve(time-1-sum,f));
            for(auto id : xs)
            {
                cant++;
                sum+=c[ty[id]];
                f[ty[id]]--;
            }
        }
        res=max(res,cant+solve(t-sum,f));
        db(res)
    }

    return 0;
}