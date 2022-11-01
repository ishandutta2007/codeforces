#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)a.size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const int ma = 128 * 1024;
const ll mod = ll(1e9) + 7;
const int N = 5 * 100 * 1000;

int n, cl[N], nm = 1;
vector<int> e[2 * N], rev[2 * N];
vector<int> nuk;

string ss[N], tt[N];

bool dfs(int nu) {
	nuk.push_back(nu);
	string q;
	if (cl[nu] == 1) q = ss[nu];
	else
		q = tt[nu];
	bool ok = true;
	forn (i, n) {
		if (nu != i) {
			if (ss[i] == ss[nu] && cl[nu] == 1)
				re false;
			if (ss[i] != q && tt[i] != q) continue;
			if (cl[i] == 0) {
				if (ss[i] == ss[nu])
					cl[i] = 2;
				else
				if (ss[i] == q)
					cl[i] = 2;
				else
					cl[i] = 1;
				if (!dfs(i)) ok = false;
			}
			if ((cl[i] == 1 && ss[i] == q) || (cl[i] == 2 && tt[i] == q) || (cl[nu] == 1 && ss[i] == ss[nu]) || (cl[i] == 1 && ss[i] == ss[nu]))
				re false;
		}
	}
	re ok;
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	cin >> n;
	forn (i, n) {
		string s, t;
		cin >> s >> t;
		ss[i] = "";
		forn (j, 3)
			ss[i] += s[j];
		tt[i] = "";
		forn (j, 2)
			tt[i] += s[j];
		tt[i] += t[0];
	}
	forn (i, n) {
		if (cl[i] == 0) {
			cl[i] = 1;
			nuk.resize(0);
			if (!dfs(i)) {
				for (int v : nuk)
					cl[v] = 0;
				cl[i] = 2;
				nuk.resize(0);
				if (!dfs(i)) {
					cout << "NO\n";
					exit(0);
				}
			}
		}
	}
	cout << "YES\n";
	forn (i, n) {
		if (cl[i] == 1)
			cout << ss[i] << "\n";
		else
			cout << tt[i] << "\n";
	}
}