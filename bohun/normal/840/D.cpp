#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORd(i, n) for(int i = n; 1 <= i; --i)
#define po(x) cerr << #x << " = " << x << endl;

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;

const int pod = (1 << 19), nax = (1 << 20) + 5;

int n, q;
int a;
int l[nax], r[nax], k[nax];
vector <int> can[nax];
vector <pair<int, int>> d[nax][5];
int ile[nax];
vector <int> dd;


void rob(vector <pair<int, int>> &a, vector <pair<int, int>> b, vector <pair<int, int>> c, int w) {
	a.clear();
	dd.clear();
	for(auto it: b) {
		if(!ile[it.fi])
			dd.pb(it.fi);
		ile[it.fi] += it.se;
	}
	for(auto it: c) {
		if(!ile[it.fi])
			dd.pb(it.fi);
		ile[it.fi] += it.se;
	}
	
	for(auto it: dd) {
		a.pb(mp(it, ile[it]));
	}
	for(auto it: dd) {
		ile[it] = 0;
	}
	
	while(ss(a) >= w) {
		dd.clear();
		for(int j = 0; j < w; ++j) {
			a[j].se--;
			int ile = a[j].se;
			if(!ile)	
				dd.pb(j);
		}
		for(int j = ss(dd) - 1; 0 <= j; --j) {
			swap(a[dd[j]], a.back());
			a.pop_back();
		}
	}
}

vector <pair<int, int>> daj(int x, int y, int w) {
	vector <pair<int, int>> ans;
	y++;
	for(x += pod, y += pod; x < y; x >>= 1, y >>= 1) {
		if(x & 1)
			rob(ans, ans, d[x++][w], w);
		if(y & 1)
			rob(ans, ans, d[--y][w], w);
	}
	return ans;
}

int mam[nax];
vector <pair<int, pair<int, int>>> v[nax];
int fre = 0;
int ans[nax];
int res[nax * 3], t[nax], val[nax * 3];
		
		
		
	
	

int main() {
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		t[i] = a;
		for(int j = 2; j <= 5; ++j)
			d[pod + i][j].pb(mp(a, 1));
	}
	
	for(int i = pod - 1; 1 <= i; --i) {
		for(int j = 2; j <= 5; ++j) {
			rob(d[i][j], d[2 * i][j], d[2 * i + 1][j], j);
		}
	}
	
	for(int i = 1; i <= q; ++i) {
		scanf("%d%d%d", &l[i], &r[i], &k[i]);
		vector <pair<int, int>> x = daj(l[i], r[i], k[i]);
		for(auto it: x) {
			v[l[i] - 1].pb(mp(++fre, mp(it.fi, -1)));
			v[r[i]].pb(mp(fre, mp(it.fi, 1)));
			can[i].pb(fre);
			val[fre] = it.fi;
		}
		ans[i] = nax;
	}
	
	for(int i = 1; i < nax; ++i) {
		mam[t[i]]++;
		for(auto it: v[i]) {
			res[it.fi] += it.se.se * mam[it.se.fi];
		}
	}
	
	
	for(int i = 1; i <= q; ++i) {
		int w = (r[i] - l[i] + 1) / k[i];
		for(auto it: can[i]) {
			if(res[it] > w && ans[i] > val[it])
				ans[i] = val[it];
		}
		printf("%d\n", (ans[i] == nax ? -1 : ans[i]));
	}
	
	
	
	return 0;
}