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

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n+1,vector<char>(n+1));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
    if(n==2 && a[1][2] != a[2][1] && m%2==0)
    {
        cout<<"NO\n";return 0;
    }
    cout<<"YES\n";
    if(m%2==1)
    {
        int cur = 1;
        vector<int> ans;
        while(sz(ans)<m+1)
            ans.pb(cur),cur ^= 3;
        for(auto &j:ans)
            cout<<j<<" ";
        cout<<"\n";return 0;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[i][j] == a[j][i] && i!=j)
            {
                vector<int> ans;
                int cur = i;
                while(sz(ans)<m+1)
                    ans.pb(cur),cur ^= i^j;
                for(auto &j:ans)
                    cout<<j<<" ";
                cout<<"\n";return 0;
            }
        }
    }
    vector<int> v={1,2,3,2};
    vector<int> ans;
    int cur = -1;
    // now take three vertices and sure answer
    if(a[1][2] == a[2][3])
    {
        
    }
    else if(a[3][1] == a[2][3])
    {   
        v = {2,3,1,3};
    }
    else if(a[3][1] == a[1][2])
    {
        v = {3,1,2,1};
    }
    else
        assert(false);
    if(m%4 == 2)
    {
        cur = 0;
    }
    else
    {
        cur = 1;
    }
    while(sz(ans) < m+1)
    {
        ans.pb(v[cur]);
        cur = (cur+1)%4;
    }
    for(auto &j:ans)
        cout<<j<<" ";
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