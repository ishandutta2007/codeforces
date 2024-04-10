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
    vector<vector<int>> a(n+1,vector<int>(m+1,0)),b(n+1,vector<int>(m+1));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    }
    vector<int> ans;
    ans = a[1];
    for(int i=1;i<=m;++i)
    {
        int sum = 0;
        for(int j=2;j<=n;++j)
        {
            if(a[j][i] != a[1][i])
                b[j][i] = 1;
            sum += b[j][i];
        }
    }
    bool ok = true;
    int mx = 0,val = 0;
    for(int i=1;i<=n;++i)
    {
        int cnt = 0;
        for(int j=1;j<=m;++j)
            cnt += b[i][j];
        if(cnt > 2)
            ok = false;
        if(cnt > mx)
            mx = cnt,val = i;
    }
    if(mx > 4)
    {
        cout<<"No\n";return 0;
    }
    if(ok)
    {
        cout<<"Yes\n";
        for(int i=1;i<=m;++i)
            cout<<ans[i]<<" ";
        cout<<"\n";
        return 0;
    }
    auto check = [&](vector<int> &A)
    {
        for(int i=1;i<=n;++i)
        {
            int cnt = 0;
            for(int j=1;j<=m;++j)
            {
                if(a[i][j] != A[j])
                    ++cnt;
            }
            if(cnt > 2)
                return false;
        }
        return true;
    };
    auto print = [&](vector<int> &A)
    {
        cout<<"Yes\n";
        for(int i=1;i<=m;++i)
            cout<<A[i]<<" ";
        cout<<'\n';
        exit(0);
    };
    if(mx == 4)
    {
        vector<int> t;
        for(int j=1;j<=m;++j)
        {
            if(b[val][j] == 1)
                t.pb(j);
        }
        assert(sz(t) == 4);
        for(int i=0;i<(1<<4);++i)
        {
            if(popcount(i) != 2)
                continue;
            for(int j=0;j<4;++j)
            {
                if(i&(1<<j))
                    ans[t[j]] = a[1][t[j]];
                else
                    ans[t[j]] = a[val][t[j]];
            }
            if(check(ans))
                print(ans);
        }
        cout<<"No\n";return 0;
    }
    assert(mx == 3);
    vector<int> t;
    for(int j=1;j<=m;++j)
    {
        if(b[val][j] == 1)
            t.pb(j);
    }
    auto get = [&](int l,int r,int x)
    {
        ans[l] = a[1][l];
        ans[r] = a[val][r];
        set<int> s;
        for(int i=1;i<=n;++i)
        {
            int cnt = 0;
            for(int j=1;j<=m;++j)
            {
                if(j!=x)
                {
                    if(ans[j] != a[i][j])
                        ++cnt;
                }
            }
            if(cnt >= 2)
                s.insert(a[i][x]);
        }
        if(!s.empty())
            ans[x] = *s.begin();    
        if(check(ans))
            print(ans);
        for(int i=1;i<=m;++i)
            ans[i] = a[1][i];
    };
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            for(int k=0;k<3;++k)
            {
                if(i != j && j!=k && k!=i)
                    get(t[i],t[j],t[k]);
            }
        }
    }
    cout<<"No\n";
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