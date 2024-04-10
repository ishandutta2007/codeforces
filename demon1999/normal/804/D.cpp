#include <bits/stdc++.h>  
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define prev previ
#define tm tmmm
#define div divv
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll mod = ll(1e9) + 7;
  
const int ma = 2 * 256 * 1024;
const int bub = 300;
  
int n, m, q, cl;
int use[100000], hh[100000];
vector<int> ed[100000], szz;
vector<ll> ans[100000], c[100000], d[100000], e[100000];

void dfs(int nu, int pr, int h) {
	//cout << nu << "\n";
	use[nu] = cl;
	hh[nu] = 0;
	szz[use[nu]]++;
	for (int v : ed[nu]) {
		if (v != pr) {
			dfs(v, nu, h + 1);
			hh[nu] = max(hh[nu], hh[v] + 1);
		}
	}
}

void dfs1(int nu, int pr, int h) {
	int h1 = h, h2 = 0;
	for (int v : ed[nu]) {
		if (v != pr) {
			if (hh[v] + 1 > h1) {
				h2 = h1;
				h1 = hh[v] + 1;
			} else {
				h2 = max(h2, hh[v] + 1);
			}
		}
	}
	//cout << nu << " " << h1 << " " << h2 << "\n";
	while (sz(c[use[nu]]) < h1 + 1)
		c[use[nu]].push_back(0);
	c[use[nu]][h1]++;
	for (int v : ed[nu]) {
		if (v != pr) {
			if (hh[v] + 1 == h1) {
				dfs1(v, nu, h2 + 1);
			} else {
				dfs1(v, nu, h1 + 1);
			}
		}
	}
}

ll get_ans(int i, int j) {
	ll sum = 0;
	ll k = max(sz(c[i]) - 1, sz(c[j]) - 1);
	int pos = k;
	if (sz(c[i]) > sz(c[j])) swap(i, j);
	for (int ps = 0; ps < sz(c[i]); ps++) {
		if (pos < sz(c[j])) {
			sum += c[i][ps] * (e[j][pos] + ll(ps + 1) * d[j][pos] + (d[j][0] - d[j][pos]) * k);
		} else {
			sum += c[i][ps] * d[j][0] * k;
		}
		if (pos) pos--;
	}
	re sum;
}

map<pair<int, int>, ll> ann;

int main() {
   	iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("a.in", "r", stdin);
    cin >> n >> m >> q;
    forn (i, m) {
    	int a, b;
    	cin >> a >> b;
    	a--;; b--;
    	ed[a].push_back(b);
    	ed[b].push_back(a);
    }
    forn (i, n) use[i] = -1;
    forn (i, n) {
    	if (use[i] == -1) {
    		szz.push_back(0);
    		dfs(i, -1, 0);
    		dfs1(i, -1, 0);
    		d[cl].resize(sz(c[cl]));
    		e[cl].resize(sz(c[cl]));
    		for (int i = sz(c[cl]) - 1; i >= 0; i--) {
    			d[cl][i] = c[cl][i];
    			e[cl][i] = c[cl][i] * i;
    			if (i + 1 < sz(c[cl])) {
    				d[cl][i] += d[cl][i + 1];
    				e[cl][i] += e[cl][i + 1];
    			}
    		} 
    		cl++;
    	}
    }
    cout.precision(30);
    /*forn (i, cl) {
    	if (sz (c[i]) > bub) {
    		forn (j, cl) {
				if (i == j) {
					ans[i].push_back(0);				
				}  else
					ans[i].push_back(get_ans(j, i));
    		}
    	}
    }*/
    forn (i, q) {
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	if (use[a] == use[b]) {
    		cout << "-1\n";
    		continue;
    	}
    	int n1 = use[a], n2 = use[b];
    	if (sz(c[n1]) < sz(c[n2]))
    		swap(n1, n2);
    	ll sum = 0;
    	if (ann.find(mp(n1, n2)) != ann.end()) {
    		sum = ann[mp(n1, n2)];
    	} else {
    		sum = get_ans(n1, n2);
    		ann[mp(n1, n2)] = ann[mp(n2, n1)] = sum;
    	}
    	double an = sum;
		an /= double(szz[n1]);
		an /= double(szz[n2]);;
		cout << an << "\n";
    }
    re 0;
}