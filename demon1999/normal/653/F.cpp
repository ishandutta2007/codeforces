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
const int szz = 500000, ma = 1024 * 512, max_pow = 19;

int n;
ll ans;
int seg_bal[2 * ma];
int c[max_pow + 1][szz + 100], r[ma];
vector<int> pos[2 * ma]; 
string s;

ll cnt_with_bal(int nu, int l, int r) {
	nu += szz;
	if (l > r)
		re 0;
	re max(ll(lower_bound(pos[nu].begin(), pos[nu].end(), r) - lower_bound(pos[nu].begin(), pos[nu].end(), l)), 0LL);
}

int get_first(int nu, int l, int r, int k, int bal) {
	if (l + 1 == r) {
		if (seg_bal[nu] < bal) re nu - ma;
		re -1;
	}
	int mid = (l + r) / 2, ans = -1;
	if (k < mid && seg_bal[2 * nu] < bal) {
		ans = get_first(2 * nu, l, mid, k, bal);
	}
	if (ans == -1) {
		ans = get_first(2 * nu + 1, mid, r, k, bal);
	}
	re ans;
}

void get_r() {
	for (int i = 0; i < sz(s); i++) {
		int bl = 0;
		if (i)
			bl = seg_bal[ma + i - 1];
		r[i] = get_first(1, ma, 2 * ma, i + ma, bl);
		//cout << r[i] << " ";
	}
	//cout << endl;
}

char cq[szz + 100];
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	scanf("%d%s", &n, cq);
	s = cq;
	int bal = 0;
	forn (i, 2 * ma)
		seg_bal[i] = -500001;
	forn (i, sz(s)) {
		if (s[i] == '(')
			bal++;
		else
			bal--;
		seg_bal[i + ma] = bal;
		pos[bal + szz].push_back(i);
	}
	for (int i = ma - 1; i; i--)
		seg_bal[i] = min(seg_bal[2 * i], seg_bal[2 * i + 1]);
	get_r();
	s += "$";
	vector<pair<char, int> > q;
	forn (i, sz(s)) {
		q.push_back(mp(s[i], i));
	}	
	sort(q.begin(), q.end());
	int k = 0;
	forn (i, sz(q)) {
		if (i && q[i].fi != q[i - 1].fi)
			k++;
		c[0][q[i].se] = k;
	}
	vector<pair<pair<int, int>, int> > qq1, qq;
	qq1.resize(sz(s));
	qq.resize(sz(s));
	for (int j = 1; j <= max_pow; j++) {
		vector<int> pos, pos1;
		pos.assign(sz(s) + 2 + 1, 0);
		pos1.assign(sz(s) + 2 + 1, 0);
		forn (i, sz(s)) {
			pos[c[j - 1][(i + (1 << (j - 1))) % sz(s)] + 1]++;
			pos1[c[j - 1][i] + 1]++;
		}

		forn (i, sz(s) + 1) {
			pos[i + 1] += pos[i];
			pos1[i + 1] += pos1[i];
		}
		forn (i, sz(s)) {
			int k = c[j - 1][(i + (1 << (j - 1))) % sz(s)];
			///cout << k << " ";
			qq1[pos[k]] = mp(mp(c[j - 1][i], k), i);
			pos[k]++;
		}
		//cout << endl;
		forn (i, sz(s)) {
			qq[pos1[qq1[i].fi.fi]] = qq1[i];
			pos1[qq1[i].fi.fi]++;
		}
		int k = 0;
		forn (i, sz(qq)) {
			if (i && qq[i].fi != qq[i - 1].fi)
				k++;
			c[j][qq[i].se] = k;
		}
	}
	vector<pii> nu;
	forn (i, n)
		nu.push_back(mp(c[max_pow][i], i));
	sort(nu.begin(), nu.end());
	for (int i = 0; i < sz(nu); i++) {
		int pw = 0;
		if (i) {
			int pos1 = nu[i - 1].se, pos2 = nu[i].se;
			for (int j = max_pow; j >= 0; j--) {
				if (c[j][pos1] == c[j][pos2]) {
					pw += (1 << j);
					pos1 += (1 << j);
					pos2 += (1 << j);
					pos1 %= sz(s);
					pos2 %= sz(s);
				}
			}
		}
		int bl = 0;
		if (nu[i].se)
			bl = seg_bal[nu[i].se - 1 + ma];
		ans += cnt_with_bal(bl, nu[i].se + pw, r[nu[i].se]);
		//cout << nu[i].se << " " << ans << " " << r[nu[i].se] << " " << nu[i].se + pw << endl;
	}
	printf("%I64d", ans);
	re 0;
}