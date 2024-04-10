
// Problem : C. A Cookie for You
// Contest : Codeforces - Codeforces Round #654 (Div. 2)
// URL : https://codeforces.com/contest/1371/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
    	ll v, c;
    	ll good, bad; cin >> v >> c >> good >> bad;
    	if(good + bad > v + c) { cout << "No\n"; continue; }
    	// stage 1: balance
    	if(v > c) {
    		ll dt = v - c;
    		ll use = min(good, dt);
    		v -= use; good -= use;
    	} else {
    		ll dt = c - v;
    		ll use = min(good, dt);
    		c -= use; good -= use;
    	}
    	// stage 2: parallel consumption
    	ll tot = min(good, bad);
    	v -= tot; c -= tot;
    	good -= tot; bad -= tot;
    	// stage 3: ending
    	if(good) {
    		assert(!bad);
    		cout << "Yes\n";
    	} else {
    		assert(!good);
    		ll k = min(v, c);
    		if(k < bad) cout << "No\n";
    		else cout << "Yes\n";
    	}
    }
}