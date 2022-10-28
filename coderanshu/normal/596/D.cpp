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

const int N = 2006;

double dp[N][N][2][2];

int64_t x[N];

int _runtimeTerror_()
{
    double p;
    int64_t n,h;
    cin>>n>>h>>p;
    for(int i=1;i<=n;++i)
        cin>>x[i];
    x[0] = -1e12;
    sort(x+1,x+n+1);
    x[n+1] = 1e12;
    vector<int> rt(n+1),lt(n+1);
    rt[n] = n,lt[1] = 1;
    for(int i=2;i<=n;++i)
    {
        if(x[i-1] > x[i] - h)
            lt[i] = lt[i-1];
        else
            lt[i] = i;
    }
    for(int i=n-1;i>=1;--i)
    {
        if(x[i] + h > x[i+1])
            rt[i] = rt[i+1];
        else
            rt[i] = i;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=0;k<2;++k)
                for(int l=0;l<2;++l)
                    dp[i][j][k][l] = -1;
    function<double(int,int,int,int)> solve = [&](int i,int j,int k,int l)
    {
        if(i > j)
            return 0.0;
        if(i == j)
        {
            double ans = 0;
            if(k)
                ans += p * min(h,x[i] - (x[i-1]+h));
            else
                ans += p * min(h,x[i] - x[i-1]);
            if(l)
                ans += (1-p) * min(h,x[j+1]-h-x[j]);
            else
                ans += (1-p)*min(h,x[j+1]-x[j]);
            return ans;
        }
        if(dp[i][j][k][l] > -0.5)
            return dp[i][j][k][l];
        double ans = 0;
        if(k)
        {
            ans += p * (min(h,x[i]-(x[i-1]+h)) + solve(i+1,j,0,l));
            if(lt[j] <= i)
            {
                ans += p * (min(h,x[i]-(x[i-1]+h)) + x[j]-x[i]);
            }
            else
            {
                ans += p * (x[j] - x[lt[j]] + h + solve(i,lt[j]-1,k,1));
            }
        }
        else
        {
            ans += p * (min(h,x[i]-x[i-1]) + solve(i+1,j,0,l));
            if(lt[j] <= i)      
                ans += p * (min(h,x[i]-x[i-1]) + x[j]-x[i]);
            else
                ans += p * (x[j] - x[lt[j]] + h + solve(i,lt[j]-1,k,1));
        }   
        if(l)
        {
            ans += (1-p) * (min(h,x[j+1]-h-x[j]) + solve(i,j-1,k,0));
            if(rt[i] >= j)
                ans += (1-p) * (min(h,x[j+1]-h-x[j]) + x[j]-x[i]);
            else
                ans += (1-p) * (x[rt[i]] - x[i] + h + solve(rt[i]+1,j,1,l));
        }
        else
        {
            ans += (1-p) * (min(h,x[j+1]-x[j]) + solve(i,j-1,k,0));
            if(rt[i] >= j)
                ans += (1-p) * (min(h,x[j+1]-x[j]) + x[j]-x[i]);
            else
                ans += (1-p) * (x[rt[i]] - x[i] + h + solve(rt[i]+1,j,1,l));
        }   
        return dp[i][j][k][l] = ans / 2;
    };
    cout<<fixed<<setprecision(10);
    cout<<solve(1,n,0,0);
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}