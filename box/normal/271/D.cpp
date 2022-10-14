
// Problem : D. Good Substrings
// Contest : Codeforces Round #166 (Div. 2)
// URL : https://codeforces.com/problemset/problem/271/D
// Memory Limit : 512.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

set<uint64_t> hsh;
bool e[26];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string t; cin >> t;
	rep(i, 26) { char c; cin >> c; e[i] = 1-c+'0'; }
	int k; cin >> k; k++;
	rep(i, t.length()) {
		uint64_t s = 0; int c = k;
		for(int j=i; j<t.length() && c; j++) {
			hsh.insert(s);
			s = (s * 29 + (t[j] - 'a' + 1)) % 998244359987710483ull;
			c -= e[t[j]-'a'];			
		}
		if(c) hsh.insert(s);
	}
	cout << hsh.size()-1 << endl;
}