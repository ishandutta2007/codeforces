#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0);
 
using namespace std;
using namespace __gnu_pbds;
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;
const int K = 26, N = 205;
const ll inf = 1e18;
struct AC {
	queue <int> q;
	struct node {
		int next[K];
		int go[K];
		int link = -1;
		int p = -1;
		int znak;
		int sum = 0;
		vector <int> rev; // reverse links
		node (int x = 0, int y = 0) : p(x) , znak(y) {
			fill(next, next + K, -1);
			fill(go, go + K, -1);
		}
	};

	vector <node> ja;

	void add(string &a, int k) {
		if(ss(ja) == 0)
			ja.pb(node(0, 0));
		int v = 0;
		int n = ss(a);
		for(int i = 0; i < n; ++i) {
			int c = a[i] - 'a';
			if(ja[v].next[c] == -1) {
				ja[v].next[c] = ss(ja);
				ja.pb(node(v, c));
			}
			v = ja[v].next[c];
		}
		ja[v].sum += k;
	}

	void build() {
		int l = 0;
		int r = 1;
		q.push(0);
		while(l < r) {
			++l;
			int x = q.front();
			q.pop();
			for(int i = 0; i < K; ++i) {
				if(ja[x].next[i] != -1) {
					++r;
					q.push(ja[x].next[i]);
				}
			}
			if(x == 0 || ja[x].p == 0)
				ja[x].link = 0;
			else {
				ja[x].link = ja[ja[ja[x].p].link].go[ja[x].znak];
			}
			for(int i = 0; i < K; ++i) {
				if(ja[x].next[i] != -1)
					ja[x].go[i] = ja[x].next[i];
				else {
					ja[x].go[i] = x == 0 ? 0 : ja[ja[x].link].go[i];
				}
			}
			ja[ja[x].link].rev.pb(x);
		}
	}
		

	bitset <1000005> bit;

	void rek(int x) { // policz cos
		bit[x] = 1;
		for(auto it: ja[x].rev) {
			if(bit[it])
				continue;
			ja[it].sum += ja[x].sum;
			rek(it);
		}
	}
};
string t;
int n;
string xd;

AC ja, on;
int ile[200005];
int ile2[200005];
string s[200005];

int main() {
	cin >> t >> n;
	FOR(i, 1, n) {
		cin >> xd;
		s[i] = xd;
		ja.add(xd, 1);
	}
	ja.build();
	ja.rek(0);
	int v = 0;
	FOR(i, 0, ss(t) - 1) {
		v = ja.ja[v].go[t[i] - 'a'];
		ile[i] = ja.ja[v].sum;
	}
	FOR(i, 1, n) {
		reverse(s[i].begin(), s[i].end());
		on.add(s[i], 1);
	}
	on.build();
	on.rek(0);
	v = 0;
	ll res = 0;
	for(int i = ss(t) - 1; 0 <= i; --i) {
		v = on.ja[v].go[t[i] - 'a'];
		ile2[i] = on.ja[v].sum;
	}
	FOR(i, 0, ss(t) - 1)
		res += (ll) ile[i] * ile2[i + 1];
	cout << res;

	
	
		
		
	
	
	
 
    return 0;
}