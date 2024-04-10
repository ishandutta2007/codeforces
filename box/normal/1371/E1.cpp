
// Problem : E1. Asterism (Easy Version)
// Contest : Codeforces - Codeforces Round #654 (Div. 2)
// URL : https://codeforces.com/contest/1371/problem/E1
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
int MOD = 1000000007;

int atj[4010];
int n;

int cnt(int x) {
	int ans = 1;
	rep(i, n)
		ans = ans * (atj[x+i] - i) % MOD;
	return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> MOD;
    int mk = n;
    rep(i, n) {
    	int k; cin >> k;
    	atj[k]++;
    	mk = max(mk, k+1);
    }
    rep1(i, mk*2+3) atj[i] += atj[i-1];
    vector<int> ans;
    rep1(i, mk)
    	if(cnt(i)) ans.pb(i);
    cout << ans.size() << endl;
    for(int& k:ans) cout << k << ' ';
}