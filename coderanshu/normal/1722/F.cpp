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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<int>> a(n, vector<int>(m, -1));
    for(int i=0;i<n;++i) {
        cin >> s[i];
        for(int j=0;j<m;++j) {
            if(s[i][j] == '.') {
                a[i][j] = 0;
            }
        }
    }
    int cnt = 1;
    for(int i=0;i<n-1;++i) {
        for(int j=0;j<m-1;++j) {
            int emp = 0;
            for(int k=0;k<2;++k) {
                for(int l=0;l<2;++l) {
                    if(s[i + k][j + l] == '.') {
                        ++emp;
                    }
                }
            }
            if(emp == 1) {
                for(int k=0;k<2;++k) {
                    for(int l=0;l<2;++l) {
                        if(s[i + k][j + l] == '*') {
                            a[i + k][j + l] = cnt;
                        }
                    }
                }
                ++cnt;
            }
        }
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(s[i][j] == '*' and a[i][j] == -1) {
                cout << "NO\n";
                return 0;
            }
            if(a[i][j] == 0) {
                continue;
            }
            for(int x=-1;x<=1;++x) {
                for(int y=-1;y<=1;++y) {
                    if(i + x >= 0 and i + x < n and j + y >= 0 and j + y < m) {
                        if(a[i + x][j + y] != 0 and a[i + x][j + y] != a[i][j]) {
                            cout << "NO\n";
                            return 0;
                        }
                    }
                }
            }
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