// Har Har Mahadev
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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char>(m));
    int cnt = 0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>a[i][j];
            cnt += a[i][j] != '.';
        }
    }
    if(cnt == 0)
        a[0][0] = 'R';
    vector<int> dx = {1,-1,0,0},dy = {0,0,1,-1};
    while(true)
    {
        int have = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                bool red = false,white = false;
                if(a[i][j] != '.')
                    continue;
                for(int k=0;k<4;++k)
                {
                    int x = i + dx[k],y = j + dy[k];
                    if(x >= 0 && x < n && y >= 0 && y < m)
                    {
                        if(a[x][y] == 'R')
                            red = true;
                        else if(a[x][y] == 'W')
                            white = true;
                    }
                }
                if(red && white)
                {
                    cout<<"NO\n";return 0;
                }
                if(!(red || white))
                    continue;
                if(red)
                    a[i][j] = 'W';
                else
                    a[i][j] = 'R';
                have = 1;
            }
        }
        if(have == 0)
            break;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(i > 0 && a[i][j] == a[i-1][j])
            {
                cout<<"NO\n";return 0;
            }
            if(j > 0 && a[i][j] == a[i][j-1])
            {
                cout<<"NO\n";return 0;
            }
        }
    }cout<<"YES\n";
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            cout<<a[i][j];
        cout<<"\n";
    }
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