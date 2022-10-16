#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

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

const int INF = 1e9 + 7;

int n, b;

string hidden;

int ask(string s) {
#ifdef CHEISSMART
	int res = 0;
	for(int i = 0; i < n; i++)
		res += hidden[i] == s[i];
#else
	cout << s << endl;
	int res; cin >> res;
#endif
	if(res == n)
		exit(0);
	return res;
}

int tt;
int qry(vi v) { // #T - #F
	string s(n, 'F');
	for(int i:v)
		s[i] ^= 'T' ^ 'F';
	return ask(s) - tt;
}

int tt2;
int qry2(vi v) {
	string s(n, 'F');
	for(int i = 0; i < b; i++)
		s[i + b] = 'T';
	for(int i:v)
		s[i] ^= 'T' ^ 'F';
	return ask(s) - tt2;
}

signed main()
{
	IO_OP;

#ifdef CHEISSMART
	cin >> hidden;
	n = SZ(hidden);
#else
	cin >> n;
#endif

	b = n / 3;
	tt = qry({});
	tt2 = qry2({});

	string ans(n, '@');

	for(int i = 0; i < b; i++) {
		int qq = qry({i, b + i});
		if(qq == 2) {
			ans[i] = ans[b + i] = 'T';
		} else if(qq == -2) {
			ans[i] = ans[b + i] = 'F';
		}
	}
	for(int i = 0; i < b; i++) {
		if(ans[i] == '@') {
			int qq = qry2({i, i + b, i + 2 * b});
			if(qq == -3) {
				ans[i] = ans[i + b] = 'F';
				ans[i + 2 * b] = 'F';
			} else if(qq == -1) {
				ans[i] = ans[i + b] = 'F';
				ans[i + 2 * b] = 'T';
			} else if(qq == 1) {
				ans[i] = ans[i + b] = 'T';
				ans[i + 2 * b] = 'F';
			} else {
				ans[i] = ans[i + b] = 'T';
				ans[i + 2 * b] = 'T';
			}
			ans[i + b] ^= 'T' ^ 'F';
		} else {
			ans[i + 2 * b] = qry({i + 2 * b}) == 1 ? 'T' : 'F';	
		}
	}

	for(int i = b * 3; i < n; i++) {
		ans[i] = qry({i}) == 1 ? 'T' : 'F';
	}

	cerr << ans << endl;
	ask(ans);

}