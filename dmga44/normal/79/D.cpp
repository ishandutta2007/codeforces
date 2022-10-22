#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e9+5);
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k,l;
    cin >> n >> k >> l;
    vector<bool> mk(n);
    for(int i=0;i<k;i++)
    {
        int x;
        cin >> x;
        x--;
        mk[x]=1;
    }

    vector<int> a(l);
    for(int i=0;i<l;i++)
        cin >> a[i];

    vector<int> ps;
    if(mk[0])
        ps.push_back(0);
    if(mk[n-1])
        ps.push_back(n);
    for(int i=1;i<n;i++)
        if(mk[i]^mk[i-1])
            ps.push_back(i);

    int borders=ps.size();
    vector<vector<int>> dist(borders,vector<int>(borders));
    for(int i=0;i<borders;i++)
    {
        queue<int> q;
        vector<bool> mk(n+1);
        vector<int> d(n+1,oo);
        q.push(ps[i]);
        mk[ps[i]]=1;
        d[ps[i]]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            for(auto x : a)
            {
                if(u>=x && !mk[u-x])
                {
                    q.push(u-x);
                    mk[u-x]=1;
                    d[u-x]=d[u]+1;
                }
                if(u+x<=n && !mk[u+x])
                {
                    q.push(u+x);
                    mk[u+x]=1;
                    d[u+x]=d[u]+1;
                }
            }
        }

        for(int j=0;j<borders;j++)
            dist[i][j]=d[ps[j]];
    }

//    db(borders)
//    for(int i=0;i<borders;i++,cout << '\n')
//        for(int j=0;j<borders;j++)
//            cout << dist[i][j] << ' ';

    vector<int> dp(1<<borders,oo);
    dp[0]=0;
    for(int i=0;i<(1<<borders);i++)
    {
        if((__builtin_popcount(i)&1) || !i)
            continue;
        dp[i]=oo;
        int lowest=i&-i;
        int plow=log2(lowest);
        for(int j=0;j<borders;j++)
            if((1<<j)&(i^lowest))
                dp[i]=min(dp[i],dp[(i^lowest)^(1<<j)]+dist[j][plow]);
    }

    if(dp[(1<<borders)-1]!=oo)
        db(dp[(1<<borders)-1])
    else
        db(-1)

    return 0;
}