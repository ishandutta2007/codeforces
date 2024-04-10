#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;


string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b?"true":"false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(V<bool> v) {
	string res;
	for(int i=0;i<(int)v.size();i++) res+=char('0'+v[i]);
	return res;
}
template<class T1, class T2> string to_string(pair<T1, T2> p) {return "(" + to_string(p.F) + ", " + to_string(p.S) + ")";}
template<size_t S> string to_string(bitset<S> b) {
	string res;
	for(int i=0;i<S;i++) res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    for(auto x:v){
		if(!f) res+=' ';
		f=0; res+=to_string(x);
	}
    return res;
}


string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif


const int INF = 1e9 + 7, N = 1e5 + 7, M = 998244353;

void add(int& a, int b) {
	a += b;
	if(a >= M)
		a -= M;
}

int ways[N];
int n;

int solve(vi l, vi r, int m) {
	assert(int(l.size()) == n);
	assert(int(r.size()) == n);
	vi dp(m + 1);
	dp[0] = 1;
	for(int i = 0; i < n; i++) {
		vi ndp(m + 1);
		for(int j = 0; j <= m; j++) {
			int lb = j + l[i], rb = min(j + r[i], m);
			if(lb > rb) continue;
			add(ndp[lb], dp[j]);
			if(rb + 1 <= m)
				add(ndp[rb + 1], M - dp[j]);
		}
		for(int j = 1; j <= m; j++) 
			add(ndp[j], ndp[j - 1]);
		swap(dp, ndp);
	}
	int ans = 0;
	for(int i:dp)
		add(ans, i);
	return ans;
}

signed main()
{
	IO_OP;

	int m;
	cin >> n >> m;
	vi l(n), r(n);
	for(int i = 0; i < n; i++)
		cin >> l[i] >> r[i];

	for(int g = m; g >= 1; g--) {
		vi lt = l, rt = r;
		for(int i = 0; i < n; i++) {
			rt[i] /= g;
			lt[i] = (lt[i] + g - 1) / g;
		}
		int mt = m / g;
		ways[g] = solve(lt, rt, mt);
		debug(g, ways[g]);
		for(int gg = g * 2; gg <= m; gg += g)
			add(ways[g], M - ways[gg]);
	}
	cout << ways[1] << '\n';
}