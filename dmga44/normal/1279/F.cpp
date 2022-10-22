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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

int a[MAXN];
pii dp[MAXN];
int n,k,l;

pii solve(int cost)
{
    for(int i=0;i<=n;i++)
        dp[i]=pii(oo,oo);
    dp[0]=pii(0,0);
    for(int i=0;i<n;i++)
    {
        dp[i+1]=min(dp[i+1],pii(dp[i].first+a[i],dp[i].second));
        dp[min(i+l,n)]=min(dp[min(i+l,n)],pii(dp[i].first+cost,dp[i].second+1));
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> l;
    string s;
    cin >> s;
    for(int i=0;i<n;i++)
        a[i]=('a'<=s[i] && s[i]<='z');

    int cost=-1;
    for(int po=(1<<19);po;po>>=1)
        if(solve(cost+po).second>k)
            cost+=po;
    cost++;
    int res=solve(cost).first-k*cost;
    for(int i=0;i<n;i++)
        a[i]=('A'<=s[i] && s[i]<='Z');

    cost=-1;
    for(int po=(1<<19);po;po>>=1)
        if(solve(cost+po).second>k)
            cost+=po;
    cost++;

    res=min(res,(int)solve(cost).first-k*cost);
    db(res)

    return 0;
}