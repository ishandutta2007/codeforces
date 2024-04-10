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
    int n;
    cin>>n;
    vector<ll> a(n+1),b(n+1);
    for(int i=1;i<=n;++i)
        cin >> a[i];
    for(int i=1;i<=n;++i)   
        cin >> b[i];

    if(n == 1)
    {
        if(a == b)
            cout<<"SMALL\n0\n";
        else
            cout<<"IMPOSSIBLE\n";
        return 0;
    }

    auto is_inc = [&](vector<ll> &x)
    {
        for(int i=1;i<=n;++i)
            if(x[i] <= x[i-1])
                return false;
        return true;
    };
    auto is_dec = [&](vector<ll> &x)
    {
        for(int i=2;i<=n;++i)
            if(x[i] >= x[i-1])
                return false;
        return true;
    };

    long long sec = 0;
    if(n == 2) 
    {
        // Handle here
        vector<pair<char,int>> ans;
        while(true)
        {
            if(b == a)
                break;
            bool rev = true;
            for(int i=1;i<=n;++i)
            {
                if(b[i] != a[n+1-i])
                    rev = false;
            }
            if(rev)
            {
                ans.push_back({'R',1});
                break;
            }
            if(is_inc(b))
            {
                ll dif = b[2] - b[1];
                vector<ll> t = a;
                sort(all(a));
                if(a[1] == b[1])
                {
                    if(b[2] < a[2])
                    {
                        cout<<"IMPOSSIBLE\n";return 0;
                    }
                    ll d2 = b[2] - a[2];
                    if(d2 % b[1] == 0)
                    {
                        sec += d2 / b[1];
                        ans.push_back({'P',d2/b[1]});
                        if(t != a)
                            ans.push_back({'R',1});
                        break;
                    }
                }
                a = t;
                sec += b[2]/b[1];
                ans.push_back({'P',b[2]/b[1]});
                b[2] = b[2] % b[1];
                if(b[2] == 0)
                {
                    cout<<"IMPOSSIBLE\n";return 0;
                }
                continue;
            }
            else if(is_dec(b))
            {
                reverse(1+all(b));
                ans.push_back({'R',1});
                continue;
            }
            else
            {
                cout<<"IMPOSSIBLE\n";return 0;
            }
        }
        if(sec > 2e5)
        {
            cout<<"BIG\n"<<sec<<"\n";
            return 0;
        }
        cout<<"SMALL\n";
        reverse(all(ans));
        string t;
        for(auto &[j,k]:ans)
        {
            while(k--)
                t += j;
        }
        cout<<sz(t)<<"\n"<<t<<"\n";
        return 0;
    }
    string ans; 
    while(true)
    {
        if(b == a)
            break;
        bool rev = true;
        for(int i=1;i<=n;++i)
        {
            if(b[i] != a[n+1-i])
                rev = false;
        }
        if(rev)
        {
            ans += "R";
            break;
        }
        if(is_inc(b))
        {
            for(int i=n;i>=1;--i)
            {
                b[i] = b[i] - b[i-1];
                if(b[i] <= 0)
                {
                    cout<<"IMPOSSIBLE\n";return 0;
                }
            }
            ans += "P";
            ++sec;
            continue;
        }
        else if(is_dec(b))
        {
            reverse(1+all(b));
            ans += "R";
            continue;
        }
        else
        {
            cout<<"IMPOSSIBLE\n";return 0;
        }
    }
    if(sec > 2e5)
    {
        cout<<"BIG\n"<<sec<<"\n";return 0;
    }
    cout<<"SMALL\n"<<sz(ans)<<"\n";
    reverse(ans.begin(),ans.end());
    cout << ans << "\n";
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