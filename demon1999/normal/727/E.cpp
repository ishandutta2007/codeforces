#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const ll mod[4] = {ll(1e9) + 7, ll(1e9) + 9, 27644437, 1073676287}, pr[4] = {239, 37, 53, 59}; 
int n, k, m, pos[3000000];
vector<ll> p[4], hs[4], hs1[4];
vector<pair<ll, ll> > a[4];
vector<pair<pair<pll, pll>, ll> > aa;
char t[3000000], s[300000];


int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	scanf("%d%d", &n, &k);
	getchar();
	forn (q, 4) {
		p[q].assign(n * k + 1, 1);
		forn (i, n * k)
			p[q][i + 1] = (p[q][i] * pr[q]) % mod[q];
		hs[q].assign(n * k + k + 1, 0);
		hs1[q].assign(n * k + k + 1, 0);
	}
	forn (i, n * k) {
		t[i] = getchar();
		forn (q, 4) {
			hs[q][i + 1] = (hs[q][i] * pr[q] + ll(t[i])) % mod[q];
		}
	}
	for (int i = n * k; i < n * k + k; i++) {
		t[i] = t[i - n * k];
		forn (q, 4)
			hs[q][i + 1] = (hs[q][i] * pr[q] + ll(t[i])) % mod[q];
	}
	scanf("%d", &m);
	getchar();
	forn (i, 4)
		a[i].assign(m, mp(0, 0));
	forn (i, m) {
		forn (j, k) {
			s[j] = getchar();
			forn (q, 4) {
				a[q][i].fi = (a[q][i].fi * pr[q] + ll(s[j])) % mod[q];
			}
		}
		forn (q, 4)
			a[q][i].se = i + 1;
		if (i + 1 < m) {
			char cc = getchar();
		}
	}
	forn (i, m) {
		aa.push_back(mp(mp(mp(a[0][i].fi, a[1][i].fi), mp(a[2][i].fi, a[3][i].fi)), i + 1));
		//cout << a[0][i].fi << " " << a[1][i].fi << "\n";
	}
	sort(aa.begin(), aa.end());
	forn (i, n * k) {
		forn (q, 4) {
			hs1[q][i] = (((hs[q][i + k] - hs[q][i] * p[q][k])%mod[q] + mod[q])%mod[q]);
			//cout << hs1[q][i] << " ";
		}
		//cout << endl;
		pair<pll, pll> qqq = mp(mp(hs1[0][i], hs1[1][i]), mp(hs1[2][i], hs1[3][i]));
		int nu = lower_bound(aa.begin(), aa.end(), mp(qqq, 0LL)) - aa.begin();
		//cout << nu << endl;
		pos[i] = -1;
		if (nu < sz(aa) && aa[nu].fi == qqq) {
			pos[i] = aa[nu].se;
		}
	}
	for (int i = 0; i < k; i++) {
		set<int> pqq;
		for (int j = i; j < n * k; j += k) {
			pqq.insert(pos[j]);
		}
		if (sz(pqq) != n || (*pqq.begin()) == -1) continue;
		cout << "YES\n";
		for (int j = i; j < n * k; j += k) {
			cout << pos[j] << " ";
		}
		re 0;
	}
	cout << "NO";
	re 0;
}