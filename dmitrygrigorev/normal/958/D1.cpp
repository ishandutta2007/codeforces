#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <iostream>
#include <string>  	
#include <stdio.h>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <random>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define int long long
#define double long double
#define Matrix vector<vector<int> >
#define bublic public
#define kektor vector
#define pii pair<int, int>
#define pp pair
#define all(x) x.begin(), x.end()
#define rand() (rand() << 15)
    
using namespace std;
    
typedef long long ll;

     
int RandInt(int min, int max) {
    if (max < min) swap(min, max);
    random_device rd;                                                                                                                                                                        
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}
                                                                      
const int maxn = 3e5, mod = 1e9 + 7, inf = 1e18;
const double eps = 1e-9, pi = 3.141592653589793238462643; 
int n; 
pii cnt[maxn]; 

int gcd(int a, int b) {
	while (b) {
		int c = a % b; 
		a = b; 
		b = c; 
	}
	return a; 
}

pii get(string &s) {
	int a = 0, b = 0, c; 
	int last = 1; 
	a += (s[last++] - '0');
	if (s[last] == '+') {
		++last; 
	} else {
		a *= 10; 
		a += (s[last++] - '0'); 
		last++; 
	}
	b = (s[last++] - '0'); 
	if (s[last] == ')') {
		++last;
	} else {
		b *= 10; 
		b += (s[last++] - '0'); 
		++last; 
	}
	++last; 	
	c = (s[last++] - '0'); 
	if (last != s.size()) {
		c *= 10; 
		c += (s[last] - '0'); 
	}
	a += b; 
	return mp(a, c); 
}                   

map<pii, int> have; 
              
void solve() {     
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s; 
		cnt[i] = get(s);
		int dd = gcd(cnt[i].ff, cnt[i].ss); 
		cnt[i].ff /= dd; 
		cnt[i].ss /= dd; 
		if (have.find(mp(cnt[i].ff, cnt[i].ss)) == have.end()) {
			have[mp(cnt[i].ff, cnt[i].ss)] = 1;
		} else {
			have[mp(cnt[i].ff, cnt[i].ss)]++;		
		}
	}	   
	for (int i = 0; i < n; ++i) {
		cout << have[mp(cnt[i].ff, cnt[i].ss)] << " "; 
	}
}                               
    
signed main() {
	srand(time(0)); 
    cout.precision(10);
    cout << fixed;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//	freopen("bricks.in", "r", stdin);
//	freopen("bricks.out", "w", stdout);
    #ifdef offline_judge 
        freopen("TASK.in", "r", stdin);
        freopen("TASK.out", "w", stdout);
    #endif   
    solve();
    return 0;                                        

}