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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 3000
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
        while(a[i] % 2 == 0) {
            a[i] /= 2;
        }
    }
    multiset<int> s;
    for(int i=0;i<n;++i) {
        cin >> b[i];
        while(b[i] % 2 == 0) {
            b[i] /= 2;
        }
        s.insert(b[i]);
    }
    sort(all(a), greater<int>());
    for(int i=0;i<n;++i) {
        while(*s.rbegin() > a[i]) {
            int t = *s.rbegin();
            s.erase(s.find(*s.rbegin()));
            --t;
            while(t > 0 and t % 2 == 0) {
                t /= 2;
            }
            if(t > 0) {
                s.insert(t);
            }
        }
        if(s.find(a[i]) != s.end()) {
            s.erase(s.find(a[i]));
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}