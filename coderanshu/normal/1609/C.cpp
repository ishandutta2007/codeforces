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
#define debug(...) 2401
#endif

#define runSieve
const int N=1000005;
bool prime[N];
ll pf[N];
void sieve()
{
    int k=sqrt(N-2);
    for(int i=1;i<=N-2;++i)
        prime[i]=true;
    for(int i=2;i<=k;++i)
    {
        if(prime[i])
        {
            for(int k=i*i;k<=N-2;k+=i)
            {
                prime[k]=false;
                pf[k]=i;
            }
        }
    }
}

int _runtimeTerror_()
{
    int n, e;
    cin >> n >> e;
    ll ans = 0;
    vector<int> a(n+1);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    for(int i=0;i<e;++i) {
        vector<int> st;
        vector<int> t;
        for(int j=i;j<n;j+=e) {
            t.push_back(a[j]);
        }
        int n = sz(t);
        // debug(t);
        for(int i=n-1;i>=0;--i) {
            if(t[i] > 1) {
                st.push_back(i);
            }
            int r = n;
            if(sz(st) >= 1) {
                if(prime[t[st.back()]]) {
                    r = n - 1;
                    if(sz(st) >= 2) {
                        r = st[sz(st) - 2] - 1;
                    }
                    // debug(r, st);
                    ans += r - st.back() + 1;
                    ans -= st.back() == i;
                }
                else {
                    r = st.back() - 1;
                }
            }
        }   
        // debug(ans);
    }
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
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}