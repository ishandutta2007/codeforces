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
const int inf = 1000000000, ma = 2 * 256 * 1024;
int n, m, p, segtr[2 * ma], nu[2 * ma];
set<int> qq;
char aa[1000000], bb[1000000];
string s, t;

void neww(int l, int r) {
	if (l > r) re;
	if (l % 2) {
		segtr[l] = 1;
		neww(l + 1, r); re;
	}
	if (r % 2 == 0) {
		segtr[r] = 1;
		neww(l, r - 1); re;
	}
	neww(l / 2, r / 2);
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("sumb.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &p);
	scanf("%s", aa);
	s = aa;
	scanf("%s", bb);
	t = bb;
	p--;
	forn (i, n) {
		qq.insert(i);
	}
	vector<int> q;
	forn (i, sz(s)) {
		if (s[i] == '(') {
			q.push_back(i);
		}
		else {
			nu[i] = q[sz(q) - 1];
			nu[q[sz(q) - 1]] = i;
			q.pop_back();
		}
	}
	auto it = qq.find(p);
	forn (i, m) {
		//cout << *it << endl;
		if (t[i] == 'L') {
			it--;
		}
		if (t[i] == 'R') {
			it++;
		}
		if (t[i] == 'D') {
			p = *it;
			//neww(min(nu[p], p) + ma, max(nu[p], p) + ma);
			auto it1 = qq.find(min(nu[p], p));
			vector<int> j;
			while (*it1 != max(nu[p], p)) {
				j.push_back(*it1);
				it1++;
			}
			forn (i, sz(j))
				qq.erase(j[i]);
			it = qq.find(max(nu[p], p));
			it++;
			int nunu = 0;
			if (it != qq.end()) {
				nunu = *it;
			}
			else {
				it--; it--;
				nunu = *it;
			}
			qq.erase(max(nu[p], p));
			it = qq.find(nunu);
		}
	}
	for (auto v : qq) {
		cout << s[v];
	}
	/*forn (i, n) {
		int j = n + ma, k = 0;
		while (j) {
			k |= segtr[j];
			j >>= 1;
		}
		if (k == 0) cout << s[i];
	}*/
	re 0;
}