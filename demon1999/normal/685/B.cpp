














#include <bits/stdc++.h> 

using namespace std; 
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define gi get_int() 
#define x1 xxx111
#define y1 yyy111
typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll cnn = 800, md = 1000000007, sz_g = 200000, pq = 100000000, inf = 1000000000LL,
 mod2 = 5000000, ma = 1024 * 1024, ma1 = 8, inf11 = 5LL * inf * inf;

void my_assert() {
	while(true);
}
ll llabs(int k) {
	if (k < 0) re -k;
	re k;
}
ll get_int() {
	int n;
	scanf("%d", &n);
	re n;
}
int n, m, szz[1000 * 1000], msz[1000 * 1000], nm[1000 * 1000];
pair<int, int> tr[2 * ma], psh[2 * ma];
vector<int> edge[1000 * 1000];
vector<pair<pair<int, int>, int> > qq; 

/*void push_(int nu) {
	psh[nu] = 0;
	psh[2 * nu] = psh[2 * nu + 1] = 1;
	tr[2 * nu] = tr[nu];
}*/

void neww(int nu, int l, int r, int ql, int qr, pii ab) {
	if (l > qr || r < ql) re;
	/*if (psh[nu]) {
		push_(nu);
	}*/
	if (ql <= l && r <= qr) {
		tr[nu] = min(tr[nu], ab);
		psh[nu] = min(psh[nu], ab);
		re;
	}
	neww(2 * nu, l, (l + r) / 2, ql, qr, ab);
	neww(2 * nu + 1, (l + r) / 2 + 1, r, ql, qr, ab);
	tr[nu] = min(tr[2 * nu], tr[2 * nu + 1]);
}

pii get_(int nu, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) re mp(inf, -1);
	if (ql <= l && r <= qr) {
		re tr[nu];
	}
	re min(min(get_(2 * nu, l, (l + r) / 2, ql, qr), get_(2 * nu + 1, (l + r) / 2 + 1, r, ql, qr)),
		psh[nu]);
}

void dfs(int nu, set<pair<int, pair<int, int> > > &pq, int &szk) {
	//cout << nu << " Heh" << endl;
	pq.clear();
	set<pair<int, pii> > qq;
	int sz1 = 0, sz2;
	szz[nu] = 1;
	for (int v : edge[nu]) {
		dfs(v, qq, sz2);
		if (sz2 > sz1) {
			swap(pq, qq);
			swap(sz2, sz1);
		}
		sz1 += sz2;
		while (!qq.empty()) {
			pq.insert(*qq.begin());
			auto cc = (*qq.begin());
			qq.erase(qq.begin());
			while (true) {
				auto it = pq.find(cc);
				auto it1 = it;
				if (it != pq.begin()) {
					it1--;
					if ((it1 -> se.fi) >= cc.se.fi) {
						pq.erase(it1);
						sz1--;
						continue;
					}
					break;
				}
				break;
			}
			auto it = pq.find(cc);
			auto it1 = it;
			it1++;
			if (it1 != pq.end() && (it1 -> se.fi) <= cc.se.fi) {
				sz1--;
				pq.erase(it);
			}
		}
		szz[nu] += szz[v];
		msz[nu] = max(msz[nu], szz[v]);
	}
	while (!pq.empty() && (pq.begin() -> fi) < szz[nu]) {
		pq.erase(pq.begin());
		sz1--;
	}
	auto cc = mp(2 * szz[nu], mp(2 * msz[nu], nu));
	sz1++;
	pq.insert(cc);
	while (true) {
		auto it = pq.find(cc);
		auto it1 = it;
		if (it != pq.begin()) {
			it1--;
			if ((it1 -> se.fi) >= cc.se.fi) {
				pq.erase(it1);
				sz1--;
				continue;
			}
			break;
		}
		break;
	}
	auto it = pq.find(cc);
	auto it1 = it;
	it1++;
	if (it1 != pq.end() && (it1 -> se.fi) <= cc.se.fi) {
		sz1--;
		pq.erase(it);
	}
	szk = sz1;
	nm[nu] = (pq.begin()->se.se);
}

int main() {
    //iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("sum.in", "r", stdin);
    //freopen("kingrook.out", "w", stdout);
    n = gi; m = gi;
    forn (i, 2 * ma)
    	tr[i] = psh[i] = mp(inf, -1);
    forn (i, n - 1) {
    	int k = gi;
    	k--;
    	edge[k].push_back(i + 1);
    }
    set<pair<int, pii> > qp;
    int pp;
    dfs(0, qp, pp);
    sort(qq.begin(), qq.end());
    reverse(qq.begin(), qq.end());
    int minn = inf, num = -1;
    forn(i, sz(qq)) {
    	if (qq[i].fi.se == inf) {
    		nm[qq[i].se] = num;
    		assert(num >= 0);
    	}
    	else {
    		if (minn > qq[i].fi.se) {
    			minn = qq[i].fi.se;
    			num = qq[i].se;
    		}
    	}
    }
    forn (i, m) {
    	int nu = gi;
    	nu--;
    	printf("%d\n", nm[nu] + 1);
    }
    return 0;
}