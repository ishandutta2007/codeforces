#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

bool adj[44][44];
vi v;

int get_id(string& s) {
	static map<string, int> ids;
	static int nw_id = 0;
	if(!ids.count(s)) ids[s] = nw_id++;
	return ids[s];
}

void add_edges() {
	sort(ALL(v));
	v.resize(unique(ALL(v)) - v.begin());
	for(int i=0;i<v.size();i++)
		for(int j=0;j<i;j++)
			adj[v[i]][v[j]] = adj[v[j]][v[i]] = true;
}

int is_indp[1<<20], max_indp[1<<20];

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		int t;
		cin >> t;
		if(t == 1) {
			add_edges();
			v.clear();
		} else {
			string s;
			cin >> s;
			int id = get_id(s);
			v.PB(id);
		}
	}
	add_edges();
	if(m == 1) {
		cout << 1 << endl;
		return 0;
	}

	int h = m / 2;
	is_indp[0] = 1;
	for(int i=1;i<(1<<h);i++) {
		int k;
		for(int j=0;j<h;j++) if(i>>j&1) { k = j; break; }
		int rem = i ^ (1 << k);
		is_indp[i] = is_indp[rem];
		for(int j=0;j<h;j++) if(rem >> j & 1 && adj[k][j]) is_indp[i] = 0;
	}
	int hh = m - h;
	for(int i=1;i<(1<<hh);i++) {
		int k;
		for(int j=0;j<hh;j++) if(i>>j&1) { k = j; break; }
		int rem = i ^ (1 << k);
		max_indp[i] = max_indp[rem];
		for(int j=0;j<hh;j++) if(rem >> j & 1 && adj[k+h][j+h]) rem ^= 1 << j;
		max_indp[i] = max(max_indp[i], 1 + max_indp[rem]);
	}
	int ans = 0;
	for(int i=0;i<(1<<h);i++)
		if(is_indp[i]) {
			int rem = (1 << hh) - 1;
			for(int j=0;j<h;j++) if(i >> j & 1)
				for(int k=0;k<hh;k++)
					if(adj[j][h+k] && rem >> k & 1)
						rem ^= 1 << k; 
			ans = max(ans, __builtin_popcount(i) + max_indp[rem]);
		}
	cout << ans << endl;
}