#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 2005;
char a[N][N];

int row[N][20],row2[N][20];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
    vector<ll> ans(10,0);
    for(int i=0;i<10;++i)
        row[0][i] = n+1,row2[n+1][i] = -1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<10;++j)
            row[i][j] = row[i-1][j];
        for(int j=1;j<=n;++j)
            amin(row[i][a[i][j]-'0'],i);
    }
    for(int i=n;i>=1;--i)
    {
        for(int j=0;j<10;++j)
            row2[i][j] = row2[i+1][j];
        for(int j=1;j<=n;++j)
            amax(row2[i][a[i][j]-'0'],i);
    }
    for(int i=1;i<=n;++i)
    {
        vector<int> l(10,n+1),r(10,-1);
        for(int j=1;j<=n;++j)
        {
            amin(l[a[i][j]-'0'],j);
            amax(r[a[i][j]-'0'],j);
        }
        for(int j=0;j<10;++j)
        {
            if(r[j]==-1)
                continue;
            if(row[i][j]<=n)
            {
                amax(ans[j],max(l[j]-1,r[j]-1)*1LL*(i-row[i][j]));
                amax(ans[j],max((n-l[j]),n-r[j])*1LL*(i-row[i][j]));
                if(row2[i][j]>=1)
                {
                    amax(ans[j],max(l[j]-1,r[j]-1)*1LL*(row2[i][j]-i));
                    amax(ans[j],max((n-l[j]),n-r[j])*1LL*(row2[i][j]-i));
                }
            }
            amax(ans[j],(r[j]-l[j])*1LL*(i-1));
            amax(ans[j],(r[j]-l[j])*1LL*(n-i));
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            swap(a[i][j],a[j][i]);
        }
    }
    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=1;j<=n;++j)
    //     {
    //         // swap(a[i][j],a[j][i]);
    //         cout<<a[i][j];
    //     }
    //     cout<<"\n";
    // }
    for(int i=0;i<10;++i)
        row[0][i] = n+1,row2[n+1][i] = -1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<10;++j)
            row[i][j] = row[i-1][j];
        for(int j=1;j<=n;++j)
            amin(row[i][a[i][j]-'0'],i);
    }
    for(int i=n;i>=1;--i)
    {
        for(int j=0;j<10;++j)
            row2[i][j] = row2[i+1][j];
        for(int j=1;j<=n;++j)
            amax(row2[i][a[i][j]-'0'],i);
    }
    for(int i=1;i<=n;++i)
    {
        vector<int> l(10,n+1),r(10,-1);
        for(int j=1;j<=n;++j)
        {
            amin(l[a[i][j]-'0'],j);
            amax(r[a[i][j]-'0'],j);
        }
        for(int j=0;j<10;++j)
        {
            if(r[j]==-1)
                continue;
            if(row[i][j]<=n)
            {
                amax(ans[j],max(l[j]-1,r[j]-1)*1LL*(i-row[i][j]));
                amax(ans[j],max((n-l[j]),n-r[j])*1LL*(i-row[i][j]));
                if(row2[i][j]>=1)
                {
                    amax(ans[j],max(l[j]-1,r[j]-1)*1LL*(row2[i][j]-i));
                    amax(ans[j],max((n-l[j]),n-r[j])*1LL*(row2[i][j]-i));
                }
            }
            amax(ans[j],(r[j]-l[j])*1LL*(i-1));
            amax(ans[j],(r[j]-l[j])*1LL*(n-i));
        }
    }
    for(int i=0;i<10;++i)
    {
        assert(ans[i]>=0);
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}