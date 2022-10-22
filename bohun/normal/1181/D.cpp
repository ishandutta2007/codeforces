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

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;



const int nax = 500005, inf = 1e9 + 1, mod = 998244353, pod = (1 << 20);

int n, m, q;
int t[nax];
int ile[nax];
ll k;
vector <pair<int, int>> v;
ll res[nax];
int sum[nax];

vector <int> si[nax];

vector <pair<ll, int>> qu;


int d[pod * 3];
void add(int pos) {
	pos += pod;
	d[pos]++;
	pos /= 2;
	while(pos) {
		d[pos] = d[pos * 2] + d[pos * 2 + 1];
		pos /= 2;
	}
}

int daj(int e, int node = 1, int le = 0, int pr = pod - 1) {
	if(le == pr) {
		return le;
	}
	int mid = (le + pr) / 2;
	if(d[2 * node] >= e)
		return daj(e, 2 * node, le, mid);
	else
		return daj(e - d[2 * node], 2 * node + 1, mid + 1, pr);
}
		
int odp[nax];



int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int maks = 0;
	
	cin >> m >> n >> q;
	int Q = q;
	for(int i = 1; i <= m; ++i) {
		cin >> t[i];
		ile[t[i]]++;
	}
	for(int i = 1; i <= n; ++i) {
		maks = max(maks, ile[i]);
		si[ile[i]].pb(i);
		v.pb(mp(ile[i], i));
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; ++i) {
		sum[i] = v[i].fi;
		if(i)
			sum[i] += sum[i - 1];
	}
	for(int i = 0; max(m, n) >= i; ++i) {
		int id = upper_bound(v.begin(), v.end(), mp(i, n + 5)) - v.begin() - 1;
		if(id == -1)
			res[i] = 0;
		else {
			res[i] = (ll) (id + 1) * i - sum[id];
		}
	}
	int j = 0;
	while(q--) {
		cin >> k;
		k -= m;
		j++;
		qu.pb(mp(k, j));
	}
	sort(qu.begin(), qu.end());
	int wsk = 0;
	
	for(int i = 0; i < maks; ++i) {
		for(auto it: si[i])
			add(it);
		while(wsk < Q && qu[wsk].fi <= res[i + 1]) {
			//cout << qu[wsk].se << " " << d[1] << " " << qu[wsk].fi - res[i] << " " << i << " " << ss(si[i]) << endl;
			odp[qu[wsk].se] = daj(qu[wsk].fi - res[i]);
			++wsk;
		}
	}
	while(wsk < Q) {
			ll h = res[maks];
			ll K = qu[wsk].fi;
			K -= h;
			K %= n;
			//cout << qu[wsk].se << "aa " << " " << K << " " << h << endl;
			if(K == 0)
				odp[qu[wsk].se] = n;
			else
				odp[qu[wsk].se] = K;
			wsk++;
	}
	for(int i = 1; i <= Q; ++i)
		cout << odp[i] << endl;
	
			
	
	
	
	
		
	
	
				
	
	
    return 0;
}