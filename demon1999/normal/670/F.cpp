#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
typedef long long ll;
typedef double ld;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 1000000000, ss = 8 * 1024;
int n, m, k[10];
char aa[1000001], bb[1000001];
string s, t, ans = "";

void f1(int a[10], string b) {
	if (t[0] == '0') re;
	string q;
	q = "";
	q += t;
	forn (i, 10)
		forn (j, a[i])
			q += char(i + '0');
	//q += b;
	ans = min(ans, q);
}

void fmin1(int a[10], string b) {
	string q = "";
	for (int i = 1; i < 10; i++) {
		if (a[i]) {
			q += char(i + '0');
			a[i]--;
			break;
		}
	}
	char pp = '0';
	forn (i, sz(t))
		if (t[i] != t[0]) {
			pp = t[i];
			break;
		}
	if (q == "") re;
	bool ok = true;
	forn (i, 10) {
		forn (j, a[i]) {
			if (ok == true && (i > t[0] - '0' || (i == t[0] - '0' && pp - '0' < i))) {
				q += t;
				ok = false;
			}
			q += char(i + '0');
		}
	}
	if (ok) q += t;
	//q += b;
	ans = min(ans, q);
}

void f2(int a[10], string k, int j) {
	string c = "", q = "";
	for (int nu = 0; nu < sz(t) - j; nu++) {
		c += t[nu];
		a[t[nu] - '0']--;
		if (a[t[nu] - '0'] < 0) {
			re;
		}
	}
	//q += k;
	for (int i = 1; i < 10; i++) {
		//cout << a[i] << " ";
		if (a[i]) {
			q += char(i + '0');
			a[i]--;
			break;
		}
	}
	//cout << endl;
	forn (i, 10)
		forn (j, a[i])
			q += char(i + '0');
	q += c;
	if (q[0] == '0') re;
	//cout << q << endl;
	ans = min(ans, q);
}

void fc(int len) {
	string p = "";
	//cout << len << endl; 
	while (len) {
		p += char(len % 10 + '0');
		k[len % 10]--;
		len /= 10;
	}
	reverse(p.begin(), p.end());
	/*forn (i, sz(p)) {
		int j = sz(t) - i - 1, nu = 0;
		bool ok = true;
		for (; j < sz(t); j++, nu++) {
			if (j < 0) continue;
			if (t[j] != p[nu]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			//cout << "HEHE\n";
			f2(k, p, i + 1);
		}
	}*/
	forn (i, sz(t)) {
		k[t[i] - '0']--;
		if (k[t[i] - '0'] < 0) re;
	}
	f1(k, p);
	fmin1(k, p);
}
int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("sumb.out", "w", stdout);
	scanf("%s%s", aa, bb);
	s = aa; 
	t = bb;
	//cout << s << t << endl;
	n = sz(s), m = sz(s);
	forn (i, n) {
		ans += "9";
		k[s[i] - '0']++;
	}
	if (n == 2 && k[0] == 1 && k[1] == 1) {
		printf("0");
		re 0;
	}
	for (int len = 1; len <= n; len++) {
		ll p = len, k = 0;
		while (p) {
			k++;
			p /= 10;
		}
		//cout << k << " "
		if (k + len == n) {
			//cout << "HEH1";
			fc(len);
			//cout << "HEH";
		}
	}
	//cout << ans;
	printf("%s", ans.c_str());
	re 0;
}