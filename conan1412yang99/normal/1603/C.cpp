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

const int INF = 1e9 + 7, M = 998244353;

void add(int& a, int b) {
	a += b;
	if(a >= M)
		a -= M;
}

const int N = 1e5 + 7;

int dp[N];

vi get(int x) { // find all possible values of ceil(x / i)
	vi ans;
	for(int i = 1; i <= x; i++) {
		int l = (x + i - 1) / i;
		i = x / (x / i);
		int r = (x + i - 1) / i;
		if(ans.empty() || ans.back() != l)
			ans.PB(l);
		if(ans.empty() || ans.back() != r)
			ans.PB(r);
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	vi a(n), w(n, 1);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	V<pi> tt;
	for(int i = 0; i < n; i++) {
		V<pi> ntt;
		vi aux = get(a[i]);
		if(i == 0) {
			for(int x:aux) {
				ntt.EB(x, x - 1);
			}
		} else {
			for(int x:aux) {
				int num = a[i] / x;
				int ndp = (a[i - 1] > num ? dp[(a[i - 1] + num - 1) / num] : dp[1]);
				add(ndp, 1LL * (x - 1) * (i + 1) % M);
				ntt.EB(x, ndp);
			}
		}

		for(auto[x, y]:tt)
			dp[x] = 0;
		for(auto[x, y]:ntt) {
			// debug(x, y);
			dp[x] = y;
		}
		swap(ntt, tt);
		add(ans, dp[1]);
	}
	for(auto[x, y]:tt)
		dp[x] = 0;
	cout << ans << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

}