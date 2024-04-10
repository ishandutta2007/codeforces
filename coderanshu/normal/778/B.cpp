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
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n, m;
    cin >> n >> m;
    vector<vector<string>> a;
    for(int i=0;i<n;++i) {
    	string var;
    	cin >> var;
    	a.push_back({});
    	a.back().push_back(var);
    	cin >> var;
    	cin >> var;
    	a.back().push_back(var);

    	if(var[0] == '0' || var[0] == '1') {

    	}
    	else {
    		cin >> var;
    		a.back().push_back(var);
    		cin >> var;
    		a.back().push_back(var);
    	}
    }
    string lo(m,'0'), hi(m,'0');
    for(int i=0;i<m;++i) {
    	set<string> s;
    	int fon = 0;
    	for(int j=0;j<n;++j) {
    		if(sz(a[j]) == 2) {
    			if(a[j][1][i] == '1') {
    				s.insert(a[j][0]);
    				++fon;
    			}
    		}
    		else {
    			int l = s.count(a[j][1]), r = s.count(a[j][3]);
    			if(a[j][2] == "XOR" && (l ^ r)) {
    				s.insert(a[j][0]);
    				++fon;
    			}
    			if(a[j][2] == "OR" && (l | r)) {
    				s.insert(a[j][0]);
    				++fon;
    			}
    			if(a[j][2] == "AND" && (l & r)) {
    				s.insert(a[j][0]);
    				++fon;
    			}
    		}
    	}
    	s.clear();
    	s.insert("?");
    	int don = 0;
    	for(int j=0;j<n;++j) {
    		if(sz(a[j]) == 2) {
    			if(a[j][1][i] == '1') {
    				s.insert(a[j][0]);
    				++don;
    			}
    		}
    		else {
    			int l = s.count(a[j][1]), r = s.count(a[j][3]);
    			if(a[j][2] == "XOR" && (l ^ r)) {
    				s.insert(a[j][0]);
    				++don;
    			}
    			if(a[j][2] == "OR" && (l | r)) {
    				s.insert(a[j][0]);
    				++don;
    			}
    			if(a[j][2] == "AND" && (l & r)) {
    				s.insert(a[j][0]);
    				++don;
    			}
    		}
    	}
    	if(fon > don) {
    		lo[i] = '1';
    	}
    	if(don > fon) {
    		hi[i] = '1';
    	}
    }
    cout << lo << "\n" << hi << "\n";
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
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}