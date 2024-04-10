#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;



using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;	

const int nax = 3005, pod = (1 << 12);

struct drzewo {
	int d[2 * pod];
	void init() {
		for(int i = 1; i < 2 * pod; ++i)
			d[i] = 1e9;
	}
	void add(int pos, int val) {
		d[pos + pod] = val;
		pos = (pos + pod) / 2;
		while(pos) {
			d[pos] = min(d[pos * 2], d[pos * 2 + 1]);
			pos /= 2;
		}
	}
	int daj(int l, int r) {
		r++;
		int res = 1e9;
		for(l += pod, r += pod; l < r; l /= 2, r /= 2) {
			if(l & 1)
				res = min(res, d[l++]);
			if(r & 1)
				res = min(res, d[--r]);
		}
		return res;
	}
};

int n, m, a, b;
int g0, x, y, z;

int daj() {
	int res = g0;
	g0 = ((ll) g0 * x + y) % z;
	return res;
	//int x;
	//cin >> x;
	//return x;
}
ll ans = 0;

deque <pair<int, int>> s[nax], now;

void add(int nr, int val, int pos) {
	while(ss(s[nr]) && s[nr].back().fi >= val)
		s[nr].pop_back();
	s[nr].pb(mp(val, pos));
}

int main() {
	cin >> n >> m >> a >> b >> g0 >> x >> y >> z;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			int val = daj();
			add(j, val, i);
		}
		if(i > a) {
			for(int j = 1; j <= m; ++j) {
				if(s[j].front().se == i - a)
					s[j].pop_front();
			}
		}
		if(i >= a) {
			now.clear();
			for(int j = 1; j <= b; ++j) {
				int val = s[j].front().fi;
				int pos = j;
				while(ss(now) && now.back().fi >= val)
					now.pop_back();
				now.pb(mp(val, pos));
			}
			ans += now.front().fi;
			for(int j = b + 1; j <= m; ++j) {
				int val = s[j].front().fi;
				int pos = j;
				while(ss(now) && now.back().fi >= val)
					now.pop_back();
				now.pb(mp(val, pos));
				if(now.front().se == j - b)
					now.pop_front();
				ans += now.front().fi;
			}
		}
		
	}
	cout << ans;
	return 0;
}