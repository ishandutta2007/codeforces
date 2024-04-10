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
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e1+5)

ll pascal[MAXN*MAXN][MAXN*MAXN];
ll dp[MAXN][MAXN][MAXN*MAXN];
ll mm[MAXN][MAXN*MAXN];

ll comb(int n,int m)
{
    return pascal[n+1][m+1];
}

ll calc(int b,int k,int sz)
{
    for(int i=0;i<=b;i++)
        for(int j=0;j<=sz;j++)
            mm[i][j]=0;
    mm[0][sz]=1;
    for(int i=1;i<=b;i++)
        for(int j=sz;j>=0;j--)
            for(int c=(i<=k);c<=j;c+=2)
                mm[i][j-c]=(mm[i][j-c]+(mm[i-1][j]*comb(j,c)));
    return mm[b][0];
}

void prec()
{
    pascal[0][0]=1;
    for(int i=1;i<MAXN*MAXN;i++)
        for(int j=1;j<MAXN*MAXN;j++)
            pascal[i][j]=(pascal[i-1][j]+pascal[i-1][j-1]);

    for(int b=2;b<=10;b++)
        for(int k=0;k<=b;k++)
        {
//            ll po=1;
            for(int sz=k;sz<MAXN*MAXN;sz+=2)
            {
//                if(2e18/po<b*b)
//                    break;
//                po*=(b*b);
                dp[b][k][sz]=calc(b,k,sz);
            }
        }
}

ll solve2(vector<ll> &d,int sz,int b)
{
    vector<bool> mk(b);
    for(int i=0;i<sz;i++)
        mk[d[d.size()-1-i]]=!mk[d[d.size()-1-i]];

    ll cant=0;
    for(int i=0;i<b;i++)
        cant+=mk[i];
    return dp[b][cant][d.size()-sz];
}

ll solve(ll b,ll x)
{
    if(!x)
        return 0;
    vector<ll> ds;
    ll sum=0;
    while(x)
    {
        ds.push_back(x%b);
        sum+=x%b;
        x/=b;
    }

    ll res=0;
    for(int i=2;i<ds.size();i++)
    {
        res+=(b-1)*(dp[b][1][i-1]);
//        cout << i << ' ' << dp[b][1][i-1] << '\n';
    }
//    db(res)
//    db(ds.size())
    res+=solve2(ds,ds.size(),b);
    for(int i=0;i<sum-1;i++)
    {
        int pos=0;
        while(pos<ds.size() && !ds[pos])
            pos++;
        ds[pos]--;
        res+=solve2(ds,ds.size()-pos,b);
    }
//    db("")
    return res;
}

bool kk(int x,int b)
{
    if(!x)
        return 0;
    vector<int> mk(b);
    while(x)
    {
        mk[x%b]^=1;
        x/=b;
    }
    int cant=0;
    for(int i=0;i<b;i++)
        cant+=mk[i];
    return !cant;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    prec();

    int q;
    cin >> q;
    while(q--)
    {
        ll b,l,r;
        cin >> b >> l >> r;
        db(solve(b,r)-solve(b,l-1))
    }

//    int b;
//    cin >> b;
//    int cant=0;
//    for(int i=1;i<q;i++)
//    {
//        cant+=kk(i,b);
//        if(cant!=solve(b,i))
//            cout << cant << ' ' << solve(b,i) << ' ' << i << '\n';
//    }

    return 0;
}
/**
2
2 4 9
3 1 10
2
2 1 100
5 1 100
2
2 1 1000000000000000000
10 1 1000
**/