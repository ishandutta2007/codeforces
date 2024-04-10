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

const int K = 26, N = 205;
const ll inf = 1e18;
struct AC {
	queue <int> q;
	vector <string> s;
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
		for(int i = 0; i < ss(ja); ++i)
			bit[i] = 0;
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
	
	int Find(string &a) { // ile jest podciagow w tym czyms
		int v = 0;
		int res = 0;
		for(int i = 0; i < ss(a); ++i) {
			int c = a[i] - 'a';
			v = ja[v].go[c];
			res += ja[v].sum;
		}
		return res;
	}
		
	
	
};


struct task {
	AC f[30];
	void add(string &a) {
		vector <string> s;
		s.pb(a);
		int i = 0;
		while(ss(f[i].s)) {
			for(auto it: f[i].s)
				s.pb(it);
			f[i].s.clear();
			f[i].ja.clear();
			++i;
		}
		for(auto it: s) {
			f[i].s.pb(it);
			f[i].add(it, 1);
		}
		f[i].build();
		f[i].rek(0);
	}
	int query(string &a) {
		int res = 0;
		for(int i = 0; i < 30; ++i) {
			if(ss(f[i].ja))
				res += f[i].Find(a);
		}
		return res;
	}
		
};

task dod, usu;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int type;
		string x;
		cin >> type >> x;
		if(type == 1)
			dod.add(x);
		if(type == 2)
			usu.add(x);
		if(type == 3) {
			cout << dod.query(x) - usu.query(x) << endl;
			fflush(stdout);
		}
	}
		
	
	
	
	return 0;
}