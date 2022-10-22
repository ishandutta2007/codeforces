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


struct matrix {
	ll t[N][N];
	matrix () {
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				t[i][j] = -inf;
	}
	matrix operator * (const matrix x) {
		matrix res = matrix();
		for(int i = 0; i < N; ++i) 
			for(int k = 0; k < N; ++k) 
				for(int j = 0; j < N; ++j)
					res.t[i][j] = max(res.t[i][j], t[i][k]  + x.t[k][j]);
		return res;
	}
	matrix Pow(matrix a, ll k) {
		matrix res = a;
		k--;
		while(k) {
			if(k & 1)
				res = res * a;
			a = a * a;
			k /= 2;
		}
		return res;
	}
	void Cat(int k) {
		for(int i = 1; i <= k; ++i)  {
			for(int j = 1; j <= k; ++j)
				cout << t[i][j] << " ";
			cout << endl;
		}
	}
};

AC x;			
ll l;
int val[205];
matrix M = matrix();
int n;
string a;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> l;
	for(int i = 1; i <= n; ++i) {
		cin >> val[i];
	}
	for(int i = 1; i <= n; ++i) {
		cin >> a;
		x.add(a, val[i]);
	}
	x.build();
	
	x.rek(0);
	
	int siz = ss(x.ja);
	for(int i = 0; i < siz; ++i) 
		for(int j = 0; j < siz; ++j)
			M.t[i][j] = -inf;
	
	for(int i = 0; i < siz; ++i) {
		for(int j = 0; j < K; ++j) {
			M.t[i][x.ja[i].go[j]] = max(M.t[i][x.ja[i].go[j]], (ll)x.ja[x.ja[i].go[j]].sum);
		}
	}
	M = M.Pow(M, l);
	ll best = 0;
	for(int i = 0; i < siz; ++i)
		best = max(best, M.t[0][i]);
	cout << best;
	
	
	
	
	
	
		
	
	
	
	return 0;
}